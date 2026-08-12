#include <iostream>
#include <vector>
using namespace std;
int n, m, x, y;
vector<int> v[104];
int rasp[104];
int viz[104];
void visit(int i){
    if(viz[i]){
        bool incepe = false;
        for(int k = 1; k <= rasp[0]; k++){
            if(rasp[k] == i){
                incepe = true;
            }
            if(incepe){
                cout << rasp[k] << ' ';
            }
        }
        cout << i;
        exit(0);
        return;
    }
    viz[i]++;
    rasp[0]++;
    rasp[rasp[0]] = i;
    int l = v[i].size();
    for(int k = 0; k < l; k++){
        if(!viz[v[i][k]] || (viz[v[i][k]] && rasp[0] > 3)){
            visit(v[i][k]);
            rasp[0]--;
            viz[v[i][k]]--;
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        visit(i);
    }
    return 0;
}
