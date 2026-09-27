#include <fstream>
using namespace std;
ifstream cin("mdiferenta.in");
ofstream cout("mdiferenta.out");
int n, m, p, q;
int a[104][104], b[104][104];
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    cin >> p >> q;
    for(int i = 1; i <= p; i++){
        for(int j = 1; j <= q; j++){
            cin >> b[i][j];
            a[i][j] -= b[i][j];
        }
    }
    cout << n << ' ' << m << '\n';
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
