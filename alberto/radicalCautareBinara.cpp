/*
Am mai cautat pe net.. nu prea imi iesea cum gandeam eu :(
In primul rand incepem cu 3 variabile, start (initial este 0) end ( = n) si mid (care primeste mijlocul intervalului)
Notam: ans(wer) = radical din n
2. Verificam unde cautam ans, daca mid * mid este mai mare ca n, atunci trebuie sa ne intoarcem in spate adica start ramane la fel si end primeste mid - 1
 Verificam daca mid * mid = n (asta inseamna ca am gasit ans fara zecimale) iar daca nu este egal verificam daca mid * mid este mai mic ca n si daca este nau mic atunci start primeste mid + 1 si ans este mid (verificam daca gasim alta solutie si daca nu gasim, ans ramane ultimul mid gasit cand start = end)

*/

#include <iostream>
using namespace std;

int radical(int n){
  int start = 0, end = n, mid;
  float ans;
  while(start <= end){
    mid = (start + end) / 2;
    if(mid * mid == n){
      ans = mid;
      break;
    } else {
      if(mid * mid < n){
        start = mid + 1;
        ans = mid;
      }else {
          end = mid - 1 ;
      }
    }
  }
  return ans;
  }

int main(){
  int n, rad;
  cout << "n = "; cin >> n;
  rad = radical(n);
  cout << rad;
  return 0;
}
/*
Prima data am scris cum trebuie rezolvata problema iar apoi codul si tocmai dupa ce am rulat codul am realizat ca nu este corect deoarece nu ne da rasp cu precizia.. si nu prea imi dau sema cum trebuie facut.
*/
