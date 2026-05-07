#include <fstream>
using namespace std;
ifstream cin("matrice4.in");
ofstream cout("matrice4.out");
int n;
int a[104][104];
int suma(int p){
    int s = 0;
    for(int i = 1; i <= n; i++){
        s += a[p][i];
    }
    return s;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        if(suma(i) % 2 == 0){
            cout << i << ' ';
        }
    }
    return 0;
}
