#include <iostream>
using namespace std;

int main(){
  int *sir, nr, *count, ok = 0;
  cout << "Dimensiunea sirului este de: "; cin >> nr;
  sir = new int[nr];
  count = new int[1000];
  for(int i = 0; i < 1000; i++){
    count[i] = 0;
  }
  for(int i = 0; i < nr; i++){
    cout << "x[" << i << "]: ";
    cin >> sir[i];
    count[sir[i]]++;
  }
  for(int i = 0; i < 1000; i++){
    if(count[i] % 2 != 0)
    ok++;
  }
  if(ok <= 1){
    cout << "Da";
  }else cout << "Nu";
  return 0;
}
