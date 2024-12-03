#include <fstream>
#include <iomanip>
using namespace std;
ifstream fin("strazi.in");
ofstream fout("strazi.out");
int n, nri;
double x, nr;
int nrv;
double cmax = 0;
int cmaxi;
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> nri;
        x = 0;
        nrv = 0;
        for(int j = 1; j <= nri; j++){
            fin >> nr;
            if(nr > x){
                x = nr;
                nrv++;
            }
        }
        double c = (double) nrv/nri;
        if(c > cmax){
            cmax = c;
            cmaxi = i;
        }
        fout << fixed << setprecision(3) << c << '\n';
    }
    fout << cmaxi;
    return 0;
}
