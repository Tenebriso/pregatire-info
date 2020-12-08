/*

Determinarea solutiei:
- Parcurgem benzinariile
- Daca nu putem ajunge la o benzinarie, ne intoarcem la cea din urma si alimentam. Practic rezervorul nostru devine 10L + Km la care se afla benzinaria la care alimentam 

*/

#include <iostream>
using namespace std;

int main(){
  int b, ben[50], rez, opriri = 0;
  cout << "Numarul de benzinarii este: "; cin >> b;
  cout << "Capacitatea rezervorului este: "; cin >> rez;
  // Am incercat cu int *ben si apoi ben = new int(b); dar daca dau un b mai mare de 7 nu merge
  for(int i = 0; i < b; i++){
    cout << "Benzinaria " << i << " se afla la (km): "; cin >> ben[i];
  }
  for(int i = 1; i <= b; i ++){
    if(rez <= ben[i]){
      opriri++;
      rez = ben[i-1] + 10;
    }
  }
  cout << "Numarul de opriri este: " << opriri;
  return 0;
}
