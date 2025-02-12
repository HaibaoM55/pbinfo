#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("cocochanel.in");
ofstream fout("cocochanel.out");
int n, m;
int c[100004];
int g[100004];
int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        fin >> c[i];
    }
    for(int i = 1; i <= m; i++){
        fin >> g[i];
    }
    sort(g+1, g+m+1);
    for(int i = 1; i <= n; i++){
        int nr = 0;
        while(true){
            int p1 = 1, p2 = m;
            while(p1 <= p2){
                int mij = (p1+p2)/2;
                if(g[mij] < c[i]){
                    p1 = mij+1;
                }else{
                    p2 = mij-1;
                }
            }
            c[i] = c[i]*2;
            if(p1 > m){
                break;
            }else{
                nr++;
            }
        }
        fout <<nr <<  '\n';
    }
    return 0;
}
