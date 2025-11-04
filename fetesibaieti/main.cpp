#include <fstream>
#include <bitset>
using namespace std;
ifstream fin("fetesibaieti.in");
ofstream fout("fetesibaieti.out");
int k, n, m, d;
bitset<2004> a[1000004];
char x[2004];
int dirx[12] = {1,-1,0,0};
int diry[12] = {0,0,-1,1};
void leefill(int i, int j){
    a[i][j] = 0;
    for(int sixseven = 0; sixseven < 4; sixseven++){
        int i1 = i+dirx[sixseven];
        int j1 = j+diry[sixseven];
        if(1 <= i1 && i1 <= n){
            if(1 <= j1 && j1 <= m){
                if(a[i1][j1] == 1){
                    a[i1][j1] = 0;
                    leefill(i1, j1);
                }
            }
        }
    }
}
int main(){
    fin >> k >> n >> d;
    for(int i = 1; i <= k; i++){
        fin >> x[i];
    }
    int nrm = 1, p = 0, i;
    for(i = 1; nrm <= n; i++){
        for(int j = 1; j <= d; j++){
            p++;
            if(x[p] == 'b'){
                a[i][j] = 1;
            }else{
                a[i][j] = 0;
            }
            if(p == k){
                nrm++;
                p = 0;
            }
        }
    }
    i--;
    n = i;
    m = d;
    int nr = 0;
//    for(int i1 = 1; i1 <= n; i1++){
//        for(int j1 = 1; j1 <= m; j1++){
//            fout << a[i1][j1] << ' ';
//        }
//        fout << '\n';
//    }
//    fout << '\n';
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == 1){
                nr++;
                leefill(i, j);
//                for(int i1 = 1; i1 <= n; i1++){
//                    for(int j1 = 1; j1 <= m; j1++){
//                        fout << a[i1][j1] << ' ';
//                    }
//                    fout << '\n';
//                }
//                fout << '\n';
            }
        }
    }
    fout << nr;
    return 0;
}
