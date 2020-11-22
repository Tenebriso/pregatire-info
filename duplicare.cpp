/*
210356 -> Pasul 3: 655330112 -> Pasul 4: 211033556
Pasul 1: Parcurgem nr cifra cu cifra
Pasul 2: Verificam daca cidra este para sau impara
Pasul 3: Construim in variabila solutie noul nr: daca cifra este impara, o adaugam de 2 ori
Pasul 4: Inversam numarul solutie
*/
#include <iostream>
using namespace std;
int duplicare( int n, int d ){
  int solutie = 0, ok = 0;
  while( n != 0 ){
    if( n % 2 == 1 ){
      solutie *= 10 + n % 10;
      ok++;
    }
  solutie *= 10 + n % 10;
  n /= 10;
  }
  while( solutie != 0 ){
    d *= 10 + solutie % 10;
    solutie /= 10;
  }
  if( ok == 0 )
    d=-1;
  return d;
}
int main(){
  int n, d;
  cout << "Numarul este: "; cin >> n;
  duplicare(n,d);
  cout << d;
  return 0;
}
