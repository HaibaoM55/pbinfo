#include <iostream>
using namespace std;
int n, m;
int x, y, z;
int s[104], p[104];
int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> x >> y >> z;
        s[x] += z;
        s[y] += z;
        p[x]++;
        p[y]++;
    }
    double vmin = 2e9;
    int vmini = 1;
    for(int i = 1; i <= n; i++){
        double med = (1.0*s[i])/(1.0*p[i]);
        if(vmin > med){
            vmin = med;
            vmini = i;
        }
    }
    cout << vmini;
    return 0;
}
