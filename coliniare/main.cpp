#include <fstream>
using namespace std;
ifstream fin("coliniare.in");
ofstream fout("coliniare.out");
int n;
struct sixseven{
    int x, y;
};
sixseven fortyone[6741];
int f[67][67];
int nr = 0, nrmax=0;
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> fortyone[i].x >> fortyone[i].y;
        f[fortyone[i].x][fortyone[i].y]++;
    }
    for(int i = 1; i <= n-1; i++){
        for(int j = i+1; j <= n; j++){
            int xa = fortyone[i].x, ya = fortyone[i].y;
            int xb = fortyone[j].x, yb = fortyone[j].y;
            /*
            xc-xa    yc-ya
            ----- == -----
            xb-xa    yb-ya
            */
            nr = 0;
            if(xb == xa){
                for(int yc = 0; yc <= 50; yc++){
                    nr += f[xa][yc];
                }
            }else{
                for(int xc = 0; xc <= 50; xc++){
                    if(((xc-xa)*(yb-ya)) % (xb-xa) == 0){
                        int yc = ((xc-xa)*(yb-ya)/(xb-xa))+ya;
                        if(0 <= yc && yc <= 50){
                            nr += f[xc][yc];
                        }
                    }
                }
            }
            nrmax = max(nrmax, nr);
        }
    }
    fout << nrmax;
    return 0;
}
