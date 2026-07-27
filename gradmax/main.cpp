#include <fstream>
using namespace std;
ifstream cin("gradmax.in");
ofstream cout("gradmax.out");
int n, k, x, y;
int f[104];
bool viz[104][104];
int vmax = 0;
int main(){
    cin >> n;
    while(cin >> x >> y){
        if(!viz[min(x, y)][max(x, y)]){
            f[x]++;
            f[y]++;
            vmax = max(vmax, max(f[x], f[y]));
            viz[min(x, y)][max(x, y)] = true;
        }
    }
    int nr = 0;
    for(int i = 1; i <= n; i++){
        if(f[i] == vmax){
            nr++;
        }
    }
    if(nr == 0){
        cout << "NU EXISTA";
        return 0;
    }
    cout << nr << ' ';
    for(int i = 1; i <= n; i++){
        if(f[i] == vmax){
            cout << i << ' ';
        }
    }
    return 0;
}
