/*
1. Cred ca este greedy nu prog dinamica :(
2. La final am observat ca trebuia afisat doar profitul si indicii.. nu si obiectele
3. Nu prea inteleg de ce nu functioneaza.. Se pare ca este ceva gresit la citire dar nu imi dau seama ce
REZOLVARE:
Pasul 1: Aflam raportul ( rp = pret/kg ) pt fiecare obiect.
Pasul 2: Ordonam obiectele descrescator in functie de pret rp.
Pasul 3: Punem obictele cat timp rucsacul nu este plin.
*/
#include <iostream>
using namespace std;

int main(){
  int G, prof = 0, n, g[20], p[20], rp[20], ind[20], cont = 0, aux;
  cout << "Dimensiunea rucsacului este (kg): "; cin >> G;
  cout << "Numarul obiectelor este: "; cin >> n;
  // Citim datele obiectelor si aflam raportul rp pentru fiecare obiect.
  // + Construim vectorul ind ( pentru a stii indicii obiectelor ).
  for (int i = 0; i < n; i++) {
    cout << "Greutatea obiectului " << i << " este: "; cin >> g[i];
    cout << "Pretul obiectului " << i << " este: "; cin >> p[i];
    rp[i] = p[i] / g[i];
    ind[i] = i;
  }
  /*
  // Testez valorile vectorilor
  for ( int i = 0; i < n; i++ ){
    cout << endl << "Pentru i = " << i;
    cout << endl << "greutate: " << g[i] << " ";
    cout << endl << "pret: " << g[i] << " ";
    cout << endl << "ind: " << g[i] << " ";
  }
  */
  // Ordonam obiectele in fucntie de rp.
  for (int i = 0; i < n-1; i++)
    for (int j = i + 1; j < n; j++) {
    if (rp[i] < rp[j]) {
      aux = rp[i];
      rp[i] = rp[j];
      rp[j] = aux;
      aux = g[i];
      g[i] = g[j];
      g[j] = aux;
      aux = p[i];
      p[i] = p[j];
      p[j] = aux;
      aux = ind[i];
      ind[i] = ind[j];
      ind[j] = aux;
    }
  }
  // Introducem obiectele in rucsac si afisam indicii.
  cout << "Au fost puse obiectele cu indicii: ";
  while (G != 0 && cont < n) {
    if (g[cont] <= G) {
      G -= g[cont];
      prof += p[cont];
      cout << ind[cont]; // afisam indicii
    }

    cont++;
  }
  cout << endl << "Profitul este: " << prof;
    return 0;
}
