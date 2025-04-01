#include <fstream>
#include <algorithm>
#pragma GCC optimize ("O3")
using namespace std;
ifstream fin("qvect.in");
ofstream fout("qvect.out");
int n, q;
int v[104][5004];
int p[104];
int a[5000004];
int poz(int x, int i, int j){
    int nr = 1;
    for(int k = i; k <= j; k++){
        int p1 = 1, p2 = v[k][0];
        int p = 0;
        if(x > v[k][p2]){
            p = v[k][0];
        }else if(x < v[k][1]){
            p = 0;
        }else{
            while(p1 <= p2){
                int mij = (p1+p2)/2;
                if(v[k][mij] < x){
                    p = mij;
                    p1 = mij+1;
                }else{
                    p2 = mij-1;
                }
            }
        }
        nr += p;
    }
    return nr;
}
int main(){
    fin >> n >> q;
    for(int i = 1; i <= n; i++){
        fin >> v[i][0];
        for(int j = 1; j <= v[i][0]; j++){
            fin >> v[i][j];
        }
    }
    int c, i, j;
    for(int z = 1; z <= q; z++){
        fin >> c >> i >> j;
        if(c == 1){
            int rmin = 2e9;
            int vk = 1;
            for(int k = 1; k <= v[i][0]; k++){
                for(vk; vk <= v[j][0]; vk++){
                    if(v[j][vk] > v[i][k]){
                        break;
                    }
                }
                if(1 <= vk && vk <= v[j][0]){
                    rmin = min(rmin, abs(v[i][k]-v[j][vk]));
                }
                if(1 <= vk-1 && vk-1 <= v[j][0]){
                    rmin = min(rmin, abs(v[i][k]-v[j][vk-1]));
                }
            }
            fout << rmin << '\n';
        }else{
            int numar = 0, med = 0, z = 0;
            for(int k = i; k <= j; k++){
                for(int l = 1; l <= v[k][0]; l++){
                    z++;
                    a[z] = v[k][l];
                }
            }
            nth_element(a+1,a+z/2, a+z+1);
            fout << a[z/2] << '\n';
        }
    }
    return 0;
}
