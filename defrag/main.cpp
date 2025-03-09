#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("defrag.in");
ofstream fout("defrag.out");
int c;
int p, s;
int n;
bool b[104];
bool v[104][364];
int z[104];
int sp[724];
int main()
{
    fin >> c;
    fin >> p >> s;
    fin >> n;
    for(int i = 1; i <= n; i++){
        int x, y;
        fin >> x >> y;
        z[x]++;
        v[x][y] = true;
        b[x] = true;
    }
    if(c == 1){
        int nr = 0;
        for(int i = 1; i <= p; i++){
            if(b[i] == false){
                nr++;
            }
        }
        fout << nr;
    }else{
        for(int i = 1; i <= p; i++){
            if(b[i]){
                for(int j = 0; j <= 2*s; j++){
                    sp[j] = 0;
                }
                for(int j = 1; j <= s; j++){
                    sp[j] = sp[j-1]+sp[j];
                    if(v[i][j]){
                        sp[j]++;
                    }
                }
                for(int j = s+1; j <= 2*s; j++){
                    sp[j] = sp[j-1]+sp[j];
                    if(v[i][j-s]){
                        sp[j]++;
                    }
                }
                int costmin = 364;
                for(int j = z[i]; j <= 2*s; j++){
                    int cost = z[i]-(sp[j]-sp[j-z[i]]);
                    costmin = min(costmin, cost);
                }
                fout << costmin << ' ';
            }else{
                fout << "0 ";
            }
        }
    }
    return 0;
}
