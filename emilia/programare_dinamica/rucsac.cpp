#include <iostream>
using namespace std;


// functie care calculeaza profitul maxim 
int rucsac(int G, int greutate[], int pret[], int n) {
	// matrice in care retinem profituri maxime partiale
	int dp[n+1][G+1];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= G; j++) {
			// pentru G = 0, profitul va fi 0
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
			// daca obiectul incape
			} else if (greutate[i] <= j) {
				int pret_includ = pret[i] + dp[i-1][j-greutate[i]];
				int pret_exclud = dp[i-1][j];
				dp[i][j] = max(pret_includ, pret_exclud);
			// daca nu incape
			} else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][G];
}

int main() {
	int n, *greutate, *pret, G;
	cout << "Numar obiecte: ";
	cin >> n;
	cout << "Greutate maxima: ";
	cin >> G;
	greutate = new int[n+1];
	pret = new int[n+1];
	for (int i = 1; i <= n; i++) {
		cout << "Greutatea obiectului " << i << ": ";
		cin >> greutate[i];
		cout << "Pretul obiectului " << i << ": ";
		cin >> pret[i];
	}
	cout << rucsac(G, greutate, pret, n) << endl;

	return 0;
}
