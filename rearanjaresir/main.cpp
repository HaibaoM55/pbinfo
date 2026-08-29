#include <iostream>
using namespace std;
int n;
int f[64][64], b[64];
long long v[64], r[64];
bool eliber(){

}
int main(){
    fin >> n;
    for(int i = 0; i < n; i++){
        fin >> v[i];
        long long x = v[i];
        for(int j = 0; x; j++){
            f[i][j] = x%2;
            x = x/2;
            b[j] += x%2;
        }
    }
    while()
    return 0;
}
