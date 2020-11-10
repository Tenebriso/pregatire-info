#include <iostream>
#include <string.h>
using namespace std;
int x[5],n=5,p=3;
string v[6]={"","caise","capsune","prune","piersici","cirese"},copiev[6];
void afisare()
{
    int i;
    for(i=1;i<=p;i++)
    copiev[i]=v[x[i]];
    for(i=1;i<=p;i++)
        cout<<copiev[i]<<" ";
    cout<<endl;
}
int cont(int k)
{
    int i;
    for(i=1;i<=k-1;i++)
        if (x[k]==x[i]) return 0;
    if ((k>1)&&(x[k]<=x[k-1])) return 0;
    if(x[k]==4) return 0;
return 1;
}
void back(int k)
{
    int i;
    if(k==p+1) afisare();
    else for (i=1;i<=n;i++){
        x[k]=i;
    if(cont (k)) back(k+1);}
}
int main()
{
    back(1);
}
