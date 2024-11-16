#include <fstream>
using namespace std;
ifstream fin("plaja.in");
ofstream fout("plaja.out");
int n, m;
int amax = 0;
char x;
int st[1004], dr[1004];
int v[1004][1004];
int stv[1004];
int vf = 0;
int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> x;
            if(x == '0'){
                v[i][j] = v[i-1][j]+1;
            }else{
                v[i][j] = 0;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        vf = 0;
        stv[0] = 0;
        v[i][0] = -1;
        for(int j = 1; j <= m; j++){
            st[j] = j;
            while(v[i][stv[vf]] >= v[i][j]){
                st[j] = st[stv[vf]];
                vf--;
            }
            vf++;
            stv[vf] = j;
        }
        vf = 0;
        stv[0] = m+1;
        v[i][m+1] = -1;
        for(int j = m; j >= 1; j--){
            dr[j] = j;
            while(v[i][stv[vf]] >= v[i][j]){
                dr[j] = dr[stv[vf]];
                vf--;
            }
            vf++;
            stv[vf] = j;
        }
        for(int j = 1; j <= m; j++){
            amax = max(amax, v[i][j]*(dr[j]-st[j]+1));
        }
    }
    fout << amax;
    return 0;
}
