#include <fstream>
using namespace std;
ifstream fin("divpar.in");
ofstream fout("divpar.out");
int n, x;
int nr = 0;
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
        int nrdiv = 1;
        if(x > 1){
            nrdiv++;
        }
        for(int j = 2; j * j <= x; j++){
            if(x % j == 0){
                nrdiv++;
                if(j*j < x){
                    nrdiv++;
                }
            }
        }
        if(nrdiv % 2 == 0){
            nr++;
        }
    }
    fout << nr;
    return 0;
}
