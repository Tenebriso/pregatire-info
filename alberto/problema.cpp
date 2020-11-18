#include <iostream>
using namespace std;

int n;
int solutie[10][2];
int labirint[10][10];
void citire(){
  int i,j;
  for(i=0; i<n; i++)
    for(j=0; j<n; j++)
      cin >> labirint[i][j];
}
void afisare(){
  int i;
  for(i=0; i<2*n-1; i++)
  cout <<"("<< solutie[i][0]<< ", "<<solutie[i][1]<<") ";
}
int cond(int jos, int dreapta){
  if(jos >= n || dreapta >=n)
    return 0;
  if(labirint[jos][dreapta] == 1)
    return 0;
    return 1;
  }
void back(int k){
  int i, j;
  if(k == 0){
  solutie[k][0]=0;
  solutie[k][1]=0;
  return;
}
  if(k < 2*n-1)
  afisare();
  else{
        int jos_i=solutie[k][0]+1;
        int jos_j=solutie[k][1];
        int dreapta_i=solutie[k][0];
        int dreapta_j=solutie[k][1]+1;
        if(cond(jos_i,jos_j)){
          solutie[k][0]=jos_i;
          solutie[k][1]=jos_j;
          back(k+1);
          }
          if(cond(dreapta_i, dreapta_j)){
            solutie[k][0]=dreapta_i;
            solutie[k][1]=dreapta_j;
            back(k+1);
          }
      }
}

int main(){
  cin>>n;
  citire();
  back(0);
}
