#include <iostream>
using namespace std;
int x[20],n,p;
void afisare(int k){
    for(int i=1;i<=k;i++)
        cout<<x[i]<<" ";
    cout<<endl;
}
int cont(int k)
{
    if (x[k]>x[k-1]) return 1;
return 0;
}
void back(int k){
   for (int i=1;i<=n;i++){
        x[k]=i;
    if(cont (k)) {
      back(k+1);
    afisare(k);
  }}
}
int main()
{
    cout<<"n=";cin>>n;
    back(1);
}
