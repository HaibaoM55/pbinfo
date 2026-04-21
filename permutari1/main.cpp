#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("permutari1.in");
ofstream cout("permutari1.out");
int n;
int p[40325][10];
int v[10];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        v[i] = i;
    }
    int z = 0;
    do{
        z++;
        for(int i = 1; i <= n; i++){
            p[z][i] = v[i];
        }
    }while(next_permutation(v+1, v+n+1));
    for(int i = z; i >= 1; i--){
        for(int j = 1; j <= n; j++){
            cout << p[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
