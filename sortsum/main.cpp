#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("sortsum.in");
ofstream fout("sortsum.out");
int nm=10000000;
int a[1000001], x, n, i;
int main()
{
    while(fin >> x){
        n++;
        int ox = x;
        int s=0;
        while(x)
        {
            s+=x%10;
            x/=10;
        }
        a[n]=s*nm + nm-ox;
    }
    sort(a+1,a+n+1);
    for(i=1; i<=n; i++){
        fout << nm-a[i]%nm << " ";
    }
    return 0;
}
