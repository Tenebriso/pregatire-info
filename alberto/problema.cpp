/*
1. Soluția e un șir de poziții care inițial (la pasul 0) are doar poziția (0, 0).
2. Creem funcția recursivă *back* care primește ca argument poziția curentă a șoricelului (i, j).
3. Dacă poziția curentă == poziția destinație, afișăm soluția.
4. Dacă nu, verificăm dacă putem să ne mutăm în jos (pe (i+1, j)). Dacă da, adăugăm (i+1, j) la soluție și apelăm *back(i+1, j).*
5. Verificăm dacă putem să ne mutăm la dreapta (pe (i, j+1)). Dacă da, adăugăm (i, j+1) la soluție și apelăm *back(i, j+1)*.
*/

#include <iostream>
#include <vector>
#define n 3

void afisare(std::vector<std::pair<int, int> > solutie) {
	for (int i = 0; i < solutie.size(); i++) {
		std::cout << "(" << solutie[i].first << ", " << solutie[i].second << ") ";
	}
	std::cout << std::endl;
}

bool check(int i, int j, int maze[n][n]){
	// sa nu iesim din maze
	if (i >= n || i < 0 || j < 0 || j >= n) {
		return false;
	}
	// sa nu fie zid
	if (maze[i][j] == 1) {
		return false;
	}

	return true;
}

void back(int i, int j, int maze[n][n], std::vector<std::pair<int, int> > &solutie) {
	// pozitia destinatie este (n-1, n-1)
	if (i == n - 1 && j == n - 1) {
		afisare(solutie);
		return;
	}
	// ne mutam jos cu o casuta
	int jos_i = i + 1;
	int jos_j = j;
	if (check(jos_i, jos_j, maze)) {
		// adaugam <jos> la solutie
		solutie.push_back({jos_i, jos_j});
		// calculam toate drumurile posibile care contin <jos>
		back(jos_i, jos_j, maze, solutie);
		// scoatem <jos> din solutie, pentru ca la pasul urmator, 
		// cand ne mutam la dreapta, sa nu apara ca ne-am mutat si jos
		solutie.pop_back();
	}
	
	// ne mutam dreapta cu o casuta
	int dreapta_i = i;
	int dreapta_j = j + 1;
	if (check(dreapta_i, dreapta_j, maze)) {
		solutie.push_back({dreapta_i, dreapta_j});
		back(dreapta_i, dreapta_j, maze, solutie);
		solutie.pop_back();
	}
}

int main() {
	int maze[n][n] = {{0, 0, 0},
			  {0, 1, 0},
			  {1, 0, 0}};
	std::vector<std::pair<int, int> > solutie;
	solutie.push_back({0, 0});
	back(0, 0, maze, solutie);
	return 0;
}
