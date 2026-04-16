#include <fstream>
#include <vector>
#define MOD 666013
using namespace std;
ifstream fin("changemin.in");
ofstream fout("changemin.out");
int t;
int n;
int v[1000004], stiva[1000004];
vector<int> f[1000004];
bool sub2 = true;
int main(){
    fin >> t;
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        if(v[i] > 2){
            sub2 = false;
        }
    }
    if(sub2 && t == 2){
        int max1 = 0;
        for(int i = n; i >= 1; i--){
            if(max1 == 0 && v[i] == 1){
                max1 = i;
            }
        }
        int cnt = 0;
        long long scor = 0;
        for(int i = 1; i <= n; i++){
            if(v[i] == 2){
                cnt++;
                scor += 2*cnt;
                scor = scor % MOD;
            }
            if(i <= max1){
                cnt++;
                scor += cnt;
                scor = scor % MOD;
            }
        }
        fout << scor;
    }else if(t == 2){
        for(int i = 1; i <= n; i++){
            f[i].push_back(i);
            for(int j = i-1; j >= 1; j--){
                if(v[i] < v[j]){
                    f[j].push_back(i);
                }else{
                    break;
                }
            }
        }
        int cnt = 0;
        long long scor = 0;
        for(int i = 1; i <= n; i++){
            int l = f[i].size();
            for(int j = 0; j < l; j++){
                cnt++;
                scor += 1LL*cnt*v[f[i][j]];
                scor = scor % MOD;
            }
        }
        fout << scor;
    }else{
        int dr = 0;
        long long cnt = 0;
        v[0] = -2e9;
        stiva[0] = 0;
        for(int i = 1; i <= n; i++){
            int oj = i;
            while(dr > 0 && v[i] < v[stiva[dr]]){
                dr--;
            }
            if(dr == 0){
                cnt += i;
            }else{
                cnt += i-stiva[dr];
            }
            dr++;
            stiva[dr] = i;
        }
        fout << cnt;
    }
    return 0;
}
