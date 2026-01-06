#include <fstream>
#include <set>
#include <array>
using namespace std;
ifstream fin("concurs.in");
ofstream fout("concurs.out");
int n;
set<array<int, 14>> states;
bool estevalid(array<int, 14> f){
    int vmax = 0;
    bool fp[14];
    for(int i = 1; i <= n; i++){
        vmax = max(vmax, f[i]);
        fp[f[i]] = true;
    }
    for(int i = 1; i <= vmax; i++){
        if(!fp[i]){
            return false;
        }
    }
    return true;
}
void kp(array<int, 14> f, int z){
    if(z == n+1){
        if(estevalid(f)){
            states.insert(f);
        }
        return;
    }
    for(int i = 1; i <= n; i++){
        f[z] = i;
        kp(f, z+1);
    }
}
array<int, 14> frlp;
int main(){
    fin >> n;
    kp(frlp, 1);
    int nr = 0;
    for(const auto& state : states){
        if(estevalid(state)){
            nr++;
        }
    }
    fout << nr;
    return 0;
}
