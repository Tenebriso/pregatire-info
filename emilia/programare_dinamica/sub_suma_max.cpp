/* Gasire subsecventa de suma maxima in vectorul v cu n elemente. */

#include <iostream>
#include <vector>
using namespace std;

// functie care calculeaza suma maxima
int suma_max(int n, int v[]) {
	int dp[n];
 
	// caz de baza
	dp[0] = v[0];
 
	// caz general
	for (int i = 1; i < n; i++) {
		if (dp[i - 1] >= 0) {
			// extinde la dreapta cu v[i]
			dp[i] = dp[i - 1] + v[i];
		} else {
			// incep o noua secventa
			dp[i] = v[i];
		}
	}
 
	// solutia e maximul din vectorul dp
	int sol = dp[0];
	for (int i = 1; i < n; i++) {
		if (dp[i] > sol) {
			sol = dp[i];
		}
	}
 
        return sol; // aceasta este suma maxima asociata cu o scubsecventa
}

// functie care afiseaza si subsecventa din care obtinem suma maxima
void subsecventa_max(int n, int v[]) {
	int dp[n];
	int start[n]; // start[i] = pozitia pe care a inceput subsecventa care
       	             // da solutia cu suma egala cu dp[i]

	// caz de baza
	dp[0] = v[0];
	start[0] = 0;

	// caz general
	for (int i = 1; i < n; i++) {
		if (dp[i - 1] >= 0) {
			// extinde la dreapta cu v[i]
			dp[i] = dp[i - 1] + v[i];
			// si v[i] face parte din aceeasi subsecventa cu v[i-1]
			start[i] = start[i - 1];
		} else {
			// incep o noua secventa
			dp[i] = v[i];
			// v[i] face parte dintr-o noua subsecventa care incepe
			// pe pozitia i
			start[i] = i;
		}
	}

	// solutia e maximul din vectorul dp
	// pos retine pozitia unde se afla ultimul element din subsecventa de
	// suma maxima
	int sol = dp[0], pos = 0;
	for (int i = 1; i < n; ++i) {
		if (dp[i] > sol) {
			sol = dp[i];
			pos = i;
		}
	}

	cout << "Suma " << sol << " intre pozitiile " << start[pos] << "-" << pos << "\n";
}

void citire(int n, int v[]) {
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
}

int main() {
	int n;
	cin >> n;
	int v[n];
	citire(n, v);

	cout << "Suma maxima este: " << suma_max(n, v) << '\n';
	subsecventa_max(n, v);

	return 0;
}
