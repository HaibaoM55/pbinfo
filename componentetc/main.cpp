#include <iostream>
#include <vector>
using namespace std;
int n, m, x, y;
vector<int> v[104], cc[104];
bool f[104][104];
bool viz[104];
void visit(int k, int j){
    int l = v[k].size();
    viz[k] = true;
    f[j][k] = true;
    for(int i = 0; i < l; i++){
        if(!viz[v[k][i]]){
            viz[v[k][i]] = true;
            visit(v[k][i], j);
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        v[x].push_back(y);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            viz[j] = false;
        }
        visit(i, i);
    }
    for(int i = 1; i <= n; i++){
        viz[i] = false;
    }
    int rasp = 0;
    for(int i = 1; i <= n; i++){
        int corect = -1;
        for(int j = 1; j <= rasp; j++){
            int l = cc[j].size();
            bool ok = true;
            for(int k = 0; k < l; k++){
                if(!f[cc[j][k]][i] || !f[i][cc[j][k]]){
                    ok = false;
                    break;
                }
            }
            if(ok){
                corect = j;
                break;
            }
        }
        if(corect == -1){
            rasp++;
            cc[rasp].push_back(i);
        }else{
            cc[corect].push_back(i);
        }
    }
    int z = 0;
    for(int i = 1; i <= rasp; i++){
        if(cc[i].size() == 1){
        	z++;
        }
    }
    cout << z;
    return 0;
}
