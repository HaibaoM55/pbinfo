#include <fstream>
#include <math.h>
using namespace std;
ifstream fin("pxp.in");
ofstream fout("pxp.out");
int n, e;
long long x;
long long p = 1;
bool b[1000004];
int main(){
    fin >> n >> e;
    int nr = 0;
    for(int j = 1; j*j <= 1000004; j++){
        b[j*j] = true;
    }
    for(int i = 1; i <= n; i++){
        fin >> x;
        bool fericit = false;
        for(int j = 1; j*j <= x; j++){
            if(b[x-(j*j)]){
                p = p*x;
                nr++;
                break;
            }
        }
    }
    fout << nr << '\n';
    if(e == 2){
        p = p*p;
    }else if(e == 3){
        p = p*p*p;
    }
    for(long long i = 1; i*i <= p; i++){
        long long y = p-(i*i);
        long long sq = sqrt(y);
        if(sq*sq == y){
            fout << i << ' ' << sq <<'\n';
            break;
        }
    }
    return 0;
}
