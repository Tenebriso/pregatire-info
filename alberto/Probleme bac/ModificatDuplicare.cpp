/*
21035 -> Pasul 3: 55330112 -> Pasul 4: 21103355
Pasul 1: Parcurgem nr cifra cu cifra
Pasul 2: Verificam daca cidra este para sau impara
Pasul 3: Construim in variabila solutie noul nr: daca cifra este impara, o adaugam de 2 ori
Pasul 4: Inversam numarul solutie
*/
#include <iostream>
using namespace std;
int duplicare(int n, int d) {
  int solutie = 0, ok = 0, countzero = 10;
  while (n % 10 == 0) {
    n /= 10;
    countzero *= 10;
  }
  while( n != 0 ){
    if( n % 2 == 1 ){
      solutie = solutie * 10 + n % 10;
      ok++;
    }
    solutie = solutie * 10 + n % 10;
    n /= 10;
  }
  while( solutie != 0 ){
    d = d * 10 + solutie % 10;
    solutie /= 10;
  }
  if( ok == 0 )
    return -1;
  if ( countzero == 10 ){
    return d;
  } else return d * countzero /10;
}
int main() {
  int n, d = 0;
  cout << "Numarul este: "; cin >> n;
  d = duplicare(n,d);
  cout << d << endl;
  return 0;
}
