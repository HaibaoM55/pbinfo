#include <fstream>
using namespace std;
ifstream fin("fadema.in");
ofstream fout("fadema.out");
int n, m;
int vmax = 1;
bool a[1004][1004];
bool b[1004][1004];
int vq[1004];
int c[1004][1004];
int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        int kk=0;
        vq[i] = 1;
        for(int j = 1; j <= m; j++){
            fin >> a[i][j];
            if(j > 1 && a[i][j] == a[i][j-1]){
                kk = j;
                for(int k = vq[i]; k <= j-1; k++){
                    c[i][k] = j;
                }
                vq[i] = j;
            }
        }
        for(int j = kk; j <= m; j++){
            c[i][j] = m+1;
        }
    }
    for(int i = 1; i <= n; i++){
        if((n-i+1)*m >= vmax){
            for(int j = 1; j <= m; j++){
                if(b[i][j] == false){
                    int minim = 1004;
                    for(int i1 = i; i1 <= n; i1++){
                        if((i1 == i) || (i1 > i && a[i1][j] != a[i1-1][j])){
                            if(c[i1][j]-1 < minim){
                                b[i1][j] = true;
                                minim = c[i1][j]-1;
                            }
                            vmax = max(vmax, (minim-j+1)*(i1-i+1));
                        }else{
                            break;
                        }
                    }
                }
            }
        }
    }
    fout << vmax;
    return 0;
}
