#include <fstream>
using namespace std;
ifstream fin("sir2dif.in");
ofstream fout("sir2dif.out");
int n;
int v[100004];
int mxst[100004];
int mndr[100004];
int st[100004], dr[100004];
int vmax = -4000000;
int main()
{
    fin >> n;
    mxst[0] = 0;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        mxst[i] = max(mxst[i-1], v[i]);
    }
    mndr[n+1]=1000000;
    for(int i = n; i >= 1; i--){
        mndr[i] = min(mndr[i+1], v[i]);
    }
    st[2] = v[1]-v[2];
    for(int i = 3; i <= n-1; i++){
        st[i] = max(mxst[i-1]-v[i], st[i-1]);
    }
    dr[n-1] = v[n-1]-v[n];
    for(int i = n-2; i >= 1; i--){
        dr[i] = max(dr[i+1], v[i]-mndr[i+1]);
    }
    for(int i = 2; i <= n-2; i++){
        vmax = max(vmax, st[i]+dr[i+1]);
    }
    fout << vmax;
    return 0;
}
