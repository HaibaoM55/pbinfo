#include <fstream>
using namespace std;
ifstream cin("summax_xi.in");
ofstream cout("summax_xi.out");
int n, x, vmax=0;
long long s = 0;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        vmax = -2e9;
        for(int j = 1; j <= n; j++){
            cin >> x;
            vmax = max(vmax, x);
        }
        s += vmax;
    }
    cout << s;
    return 0;
}
