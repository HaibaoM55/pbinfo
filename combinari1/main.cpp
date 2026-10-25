#include <fstream>
using namespace std;        
ifstream fin("combinari1.in");
ofstream fout("combinari1.out");
int n, k;
int v[34];

void bt(int cnt, int par) {
    if(cnt == k){
        for(int i = 1; i <= k; i++){
            fout << v[i] << ' ';
        }
        fout << '\n';
        return;
    }
    int start = 1;
    if(cnt > 0){
        start = v[cnt]+1;
    }
    for(int i = start; i <= n; i++){
        if(cnt == 0){
            v[cnt+1] = i;
            bt(cnt+1, i%2);
        }else{
            if(i % 2 == par){
                v[cnt+1] = i;
                bt(cnt+1, par);
            }
        }
    }
}
int main() {
    fin >> n >> k;
    bt(0, -1);
    return 0;
}
