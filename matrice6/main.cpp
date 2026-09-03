#include <fstream>
using namespace std;
ifstream cin("matrice6.in");
ofstream cout("matrice6.out");
int n;
int a[104][104];
bool b[104];
int main(){
    cin >> n;
    int vmin = 2e9, vmax = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            vmax = max(vmax, a[i][j]);
            vmin = min(vmin, a[i][j]);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j] == vmax){
                b[i] = true;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(b[i]){
                a[i][j] += vmin;
            }
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
