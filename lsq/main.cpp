#include <fstream>
using namespace std;
ifstream fin("lsq.in");
ofstream fout("lsq.out");
int n, m;
char x;
bool a[1004][1004];
int s[1004][1004];
int main(){
    fin >> n >> m;
    int vmax = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> x;
            if(x == '1'){
                a[i][j] = true;
            }
            if(a[i][j]){
                s[i][j] = 1;
                vmax = 1;
            }else{
                s[i][j] = 0;
            }
            s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+s[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j]){
                for(int l = min(m-j+1, n-i+1); l > vmax; l--){
                    if(l == 2){
                        if(a[i][j] && a[i][j+1] && a[i+1][j] && a[i+1][j+1]){
                            vmax = l;
                        }
                    }
                    int is=i,js=j;
                    int ij=i+l-1,jj=j+l-1;
                    long long suma1 =s[ij][jj] - s[is-1][jj] - s[ij][js-1] + s[is-1][js-1];
                    is++;js++;
                    ij--;jj--;
                    long long suma2 =s[ij][jj] - s[is-1][jj] - s[ij][js-1] + s[is-1][js-1];
                    if(suma1-suma2 == (l-1)*4){
                        vmax = max(l, vmax);
                    }
                }
            }
        }
    }
    fout << vmax;
    return 0;
}
