#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<int> graf[1000005];
map<int, int> adancime[1000005];
int indiceDominant[1000005];
int n;
void dfs(int nod, int parinte){
    adancime[nod][0] = 1;
    for(int vecin : graf[nod]){
        if(vecin == parinte){
            continue;
        }
        dfs(vecin, nod);
        for(auto& pereche : adancime[vecin]){
            int dist = pereche.first;
            int contor = pereche.second;
            adancime[nod][dist + 1] += contor;
        }
    }
    int maxDist = 0;
    for(auto& pereche : adancime[nod]){
        maxDist = max(maxDist, pereche.first);
    }
    vector<int> valori(maxDist + 1, 0);
    for(auto& pereche : adancime[nod]){
        valori[pereche.first] = pereche.second;
    }
    for(int j = 0; j <= maxDist; j++){
        bool esteValid = true;
        for(int k = 0; k < j; k++){
            if(valori[k] >= valori[j]){
                esteValid = false;
                break;
            }
        }
        if(!esteValid) continue;
        for(int k = j + 1; k <= maxDist; k++){
            if(valori[k] > valori[j]){
                esteValid = false;
                break;
            }
        }
        if(esteValid){
            indiceDominant[nod] = j;
            break;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        graf[x].push_back(y);
        graf[y].push_back(x);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i++){
        cout << indiceDominant[i] << '\n';
    }
    return 0;
}
