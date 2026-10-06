#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("sclmprime.in");
ofstream fout("sclmprime.out");
int n;
int v[1004], dp[1004], p[1004];
bool b[1004];
vector<int> r, cr;
bool esteprim(int x){
    if(x < 2) return  false;
    for(int i = 2; i*i <= x; i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        b[i] = esteprim(v[i]);
    }
    int rasp = 0;
    for(int i = 1; i <= n; i++){
        if(b[i]){
            int vmax = 0;
            int vmaxi = -1;
            for(int j = 1; j < i; j++){
                if(b[j] && v[j] <= v[i]){
                    if(dp[j] > vmax){
                        vmax = dp[j];
                        vmaxi = j;
                    }else if(dp[j] == vmax){
                        if(v[j] < v[vmaxi]){
                            vmaxi = j;
                        }
                    }
                }
            }
            p[i] = vmaxi;
            dp[i] = vmax+1;
            rasp = max(rasp, dp[i]);
        }
    }
    fout << rasp << '\n';
    int nr = 0;
    for(int i = 1; i <= n; i++){
        if(dp[i] == rasp){
            int j = i;
            int pa[1004];
            int pp = 0;
            while(j != -1){
                pp++;
                pa[pp] = j;
                j = p[j];
            }
            nr++;
            for(int i = rasp; i >= 1; i--){
                r.push_back(v[pa[i]]);
            }
            if(nr == 1){
                cr = r;
            }
            if(r < cr){
                cr = r;
            }
            r.clear();
        }
    }
    for(int i = 0; i < rasp; i++){
        fout << cr[i] << ' ';
    }
    return 0;
}
