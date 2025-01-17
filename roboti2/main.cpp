#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("roboti2.in");
ofstream fout("roboti2.out");
int c, n;
int v[200004];
int a[1001];
int b[200005];
int main()
{
    fin >> c;
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    if(c == 1){
        for(int i = n+1; i <= 2*n; i++){
            v[i] = v[i-n];
        }
        int lgmax = 1;
        int lg = 1;
        for(int i = 2; i <= 2*n; i++){
            if(v[i] >= v[i-1]){
                lg++;
                lgmax = max(lgmax, lg);
            }else{
                lg = 1;
            }
        }
        fout << lgmax;
    }else{
        for(int i=1;i<=n;i++){
            a[v[i]]++;
        }
        sort(v+1, v+n+1);
        int p=0,q=n-1;
        b[p]=v[1];
        p++;
        for(int i=2;i<=n;i++){
            if(b[(q+1)%n] < b[p-1]){
                b[q]=v[i];
                q--;
            }
            else{
                b[p]=v[i];
                p++;
            }
        }
        for(int i=0; i < n;i++){
            fout<<b[i]<<" ";
        }
    }
    return 0;
}
