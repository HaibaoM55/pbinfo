#include <fstream>
#include <algorithm>
#include <map>
using namespace std;
#define zeros(x) ((x ^ (x - 1))&x)
ifstream fin("nrseq.in");
ofstream fout("nrseq.out");
int n;
int v[100004], a[100004];
long long rasp = 0;
int nrp = 1;
map<int, int> f;
int AIB[100004];
int p;
void Add(int x){
    int i;
    for(i = x; i <= p; i += zeros(i))
        AIB[i]++;
}
int Compute(int x){
    int i, ret = 0;
    for (i = x; i > 0; i -= zeros(i))
        ret += AIB[i];
    return ret;
}
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        a[i] = v[i];
    }
    sort(a+1, a+n+1);
    p = 1;
    for(int i = 2; i <= n; i++){
        if(a[i] > a[p]){
            p++;
            a[p]=a[i];
        }
    }
    for(int i=1;i<=p;i++){
        f[a[i]]=i;
    }
    for(int i = 1; i <= n; i++){
        int x = f[v[i]];
        rasp += Compute(x-1);
        Add(x);
    }
    fout << rasp;
    return 0;
}
