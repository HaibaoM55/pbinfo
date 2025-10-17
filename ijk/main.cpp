///Complexitate O(n*log(n))
#include <fstream>
#include <algorithm>
using namespace std;
ifstream  fin("ijk.in");
ofstream fout("ijk.out");
int n,bit[70005],m,i;
struct per{
    int v,p;
}a[70005];
int cmp(per x, per y){
    if(x.v<y.v)return 1;
    if(x.v==y.v && x.p<y.p)return 1;
    return 0;
}
long long raspuns,cs,cd;
int sum(int i){
    int sum = 0;
    while (i > 0){ sum += bit[i]; i -= ((i) & -(i));}
    return sum;
}

void add(int i, int k){
    while (i <= n){ bit[i] += k; i += ((i) & -(i));}
}
int main(){
    fin>>n;
    for(int i=1;i<=n;i++){
        fin>>a[i].v; a[i].p=i;
    }
    sort(a+1,a+1+n,cmp);
	raspuns=0; i=n; m=n;
    do{
        while(m>=1 && a[m].v==a[i].v){
            add(a[m].p,1);
            m--;
        }
        i=m;
        while(i>=1 && a[i].v==a[m].v){
            cs=sum(a[i].p-1);
            cd=n-m-cs;
            raspuns+=cs*cd;
            i--;
        }
        i=m;
    }while(i>=1);

    fout<<raspuns;
    fin.close(); fout.close();
    return 0;
}
