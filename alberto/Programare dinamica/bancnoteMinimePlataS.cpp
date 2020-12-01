/*
Solutie:
pentru suma i verific daca pot adauga o bancnota la i - (de la 1 la i) si sa obtin un nr mai mic de bancnote
de la 1 la i: (un for cu j)
verific daca:
(1). pot sa adaug o bancnota la i-1 astfel incat suma lor sa fie i
(2). daca obtin un nr mai mic de bancnote (cand trecem la un nou i trebuie sa ii dam un nr max de bancnote)
i - 1: verific: (1) true (2) true => dp[i] = 1 + dp[i - bancnote[1]];
i - 2: verific: (1) true (2) false => valoarea lui dp[i] nu se schimba
i - 3: verific: (1) true (2) true => dp[i] = 1 + dp[i - bancnote[3]];
......
i - i: verific (1), true (2) true => dp[i] = 1 + dp[i - bancnota[i]] = 1; adica avem o bancnota egala cu suma i
i - i: verific (1), true (2) false => valoarea lui dp[i] nu se schimba ramane ultima valoare gasita


exemplu:

suma = 12;
nr_bancnote = 4;
bancnote[10] = { 1, 2, 3, 6 }

i de la 1 la 12 si j de la 1 la 4
i = 1, j = 1 - 4
1 - 1: pot sa adaug o bancnota la 0? da pt ca avem 1 si abtinem nr_bancnote = 1
1 - 2 2>1
i = 2
2 - 1: pot sa adaug o bancnota la 1? da si obtinem dp[2] = 1 + dp[2 - bancnote[1]] => 1+1 = 2
2 - 2: pot sa adaug o bancota la 0? da si obtinem dp[2] = 1 + dp[2 - bancnote[2]] => 1+0 = 1
2 - 3: 3>2 rezulta nr_bancnote = 1;
...
...
*/

#include <iostream>
using namespace std;
int suma, nr_bancnote, bancnote[10], dp[100];

void solutie(){
  dp[0] = 0;
  for (int i = 1; i < suma+1; i++){
    dp[i] = 99999;
    for (int j = 0; j < nr_bancnote; j++){
      if (bancnote[j] <= i && 1 + dp[i - bancnote[j]] < dp[i]){
        dp[i] = 1 + dp[i - bancnote[j]];
      }
    }
  }
  for(int i = 1; i < suma+1; i++)
    if(dp[i] == 99999)
      dp[i] = -1;
  cout << endl << "Numarul minim de bancnote pentru " << suma << " este: " << dp[suma];
}

int main(){
  cout << "Suma este: "; cin >> suma;
  cout << "Numarul de bancnote este: "; cin >> nr_bancnote;
  for (int i = 0; i < nr_bancnote; i++){
    cout << "Bancnota " << i << " este: ";
    cin >> bancnote[i];
  }
  solutie();

  return 0;
}
