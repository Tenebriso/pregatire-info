#include <iostream>
using namespace std;


int profit_max(int G, int greutate[], int pret[], int i) {
	// caz de baza
	if (i == 0 || G == 0) {
		return 0;
	}
	// caz general
	// verificam daca incape obiectul in rucsac
	// daca nu, nu-l punem
	if (greutate[i - 1] > G) {
		return profit_max(G, greutate, pret, i-1);
	// altfel, avem doua posibilitati:
	// 1 - il punem in rucsac
	// 2 - nu-l punem in rucsac
	// calculam maximul dintre cele doua posibilitati
	} else {
		int profit_inclus = pret[i-1] + profit_max(G - greutate[i-1], 
				greutate, pret, i-1);
		int profit_exclus = profit_max(G, greutate, pret, i-1);
		return max(profit_inclus, profit_exclus);
	}
}


int main() {
	int pret[] = {6, 3, 2, 8, 5};
	int greutate[] = {3, 3, 1, 1, 2};
	int G = 10;
	cout << "pentru G = " << G << " profitul maxim este " << profit_max(G, greutate, pret, 5) << endl;
	G = 3;
	cout << "pentru G = " << G << " profitul maxim este " << profit_max(G, greutate, pret, 5) << endl;
}
