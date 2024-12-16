#include <fstream>
using namespace std;
ifstream fin("secvb.in");
ofstream fout("secvb.out");
int n, k;
int f[1004];
int v[100004];
int nr = 0;
int main()
{
    fin >> n >> k;
    for(int i = 1; i <= 1000; i++){
        int x = i;
        while(x > 0){
            if(x % 2 == 1){
                f[i]++;
            }
            x = x / 2;
        }
    }
    v[0] = 0;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        v[i] = f[v[i]];
        v[i] = v[i-1]+v[i];
    }
    for(int i = 1; i <= n; i++){
        int p1 = i, p2 = n;
        while(p1 <= p2){
            int mij = (p1+p2)/2;
            if(v[mij]-v[i-1] < k){
                p1 = mij+1;
            }else{
                p2 = mij-1;
            }
        }
        if(v[p1]-v[i-1] == k){
            nr++;
        }
    }
    fout << nr;
    return 0;
}
