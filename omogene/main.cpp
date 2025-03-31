#include <fstream>
#include <map>
#pragma GCC optimize("O3")
#pragma GCC optimization("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
ifstream fin("omogene.in");
ofstream fout("omogene.out");
int s[3][2001][2001];
int main()
{
    int x,n,m,k=0;
    fin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            fin>>x;
            int ad[3]={0,0,0};
            ad[x]=1;
            s[0][i][j]+=s[0][i][j-1]+s[0][i-1][j]-s[0][i-1][j-1]+ad[0];
            s[1][i][j]+=s[1][i][j-1]+s[1][i-1][j]-s[1][i-1][j-1]+ad[1];
            s[2][i][j]+=s[2][i][j-1]+s[2][i-1][j]-s[2][i-1][j-1]+ad[2];        }
    }
    int r =0;
    for(int i = 1;i <= n;i++) {
        for(int i1 = i; i1 <= n; i1++) {
            map<pair<int,int>,int> vf;
            vf[{0,0}] = 1;
            int z = 0, u = 0, d = 0;
            for(int j = 1; j <= m;j++) {
                int is=i,js=j;
                int ij=i1,jj=j;
                z += s[0][ij][jj] - s[0][is-1][jj] - s[0][ij][js-1] + s[0][is-1][js-1];
                u += s[1][ij][jj] - s[1][is-1][jj] - s[1][ij][js-1] + s[1][is-1][js-1];
                d += s[2][ij][jj] - s[2][is-1][jj] - s[2][ij][js-1] + s[2][is-1][js-1];
                pair<int, int> a;
                a.first = z - u;
                a.second= u - d;
                r += vf[a]++;
            }
        }
    }
    fout<<r;
}
