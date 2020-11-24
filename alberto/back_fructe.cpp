#include <iostream>
#include <string.h>
using namespace std;

int solutie[5], n = 5, p = 3;
string cos_fructe[5] = {"caise", "capsune", "prune", "piersici", "cirese" };

void afisare()
{
    for (int i = 0; i < p; i++) {
        cout << cos_fructe[solutie[i]] << " ";
    }
    cout << endl;
}

/* Functie care verifica daca fructul pus la pasul curent e valid.
 * Returneaza 0 daca in solutie exista deja 1 (capsune), iar la pasul
 * curent incercam sa punem 3 (piersici). 
 * Nu verifica si invers deoarece solutia e generata direct in ordine
 * crescatoare si nu vom avea niciodata in solutie 3, iar la pasul curent
 * sa punem 1. */
int verificare(int pas)
{
    for (int i = 0; i < pas; i++) {
        if (solutie[pas] == 3 && solutie[i] == 1) {
		return 0;
	}
    }
    return 1;
}

void back(int pas)
{
    if (pas == p) {
	afisare();
    } else {
	// solutia va fi in ordine crescatoare, asa ca
	// pornim de la numarul urmator (pasul anterior + 1)
	int i = pas > 0? solutie[pas - 1] + 1 : 0;
	for (; i < n; i++) {
		solutie[pas] = i;
	    	if (verificare(pas)) {
		       	back(pas + 1);
		}
	}
    }
}

int main()
{
    back(0);

    return 0;
}
