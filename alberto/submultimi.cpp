#include <iostream>
using namespace std;

int solutie[20], n;

void afisare(int pas_curent) {
    for (int i = 1; i <= pas_curent; i++)
        cout << solutie[i] << " ";
    cout << endl;
}

int cont(int pas_curent)
{
    if (solutie[pas_curent] > solutie[pas_curent - 1]) {
	    return 1;
    }
    return 0;
}

void back(int pas_curent){
   for (int i = 1; i <= n; i++) {
        solutie[pas_curent] = i;
        if (cont(pas_curent)) {
	      back(pas_curent + 1);
	     afisare(pas_curent);
  	}
   }
}

int main()
{
    cout << "n=";
    cin >> n;
    //afisare multime vida
    cout << endl;

    back(1);
}
