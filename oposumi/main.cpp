#include <fstream>
using namespace std;
ifstream fin("oposumi.in");
ofstream fout("oposumi.out");
int p, n;
int a[1004][1004];
int c[500504], z = 1;
int main(){
    fin >> p >> n;
    c[1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= n-i+2; j++){
            z++;
            c[z] = i;
        }
    }
    if(p == 1){
        for(int i = 1; i <= z; i++){
            fout << c[i] << ' ';
        }
    }else{
        int k;
        fin >> k;
        int z = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j++){
                if(a[j][i] == 0){
                    z++;
                    a[j][i]=z;
                }
                if(z == k-1 && i < n){
                    z++;
                    a[i+1][i+1]=z;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                fout << a[i][j] << ' ';
            }
            fout << '\n';
        }
    }
    return 0;
}
