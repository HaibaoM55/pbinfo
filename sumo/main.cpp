#include <fstream>
using namespace std;
ifstream fin("sumo.in");
ofstream fout("sumo.out");
int n;
int p, q;
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> p >> q;
        int j = 1;
        long long s = 0;
        int nrcif = 0;
        int z[16];
        int nrz = 0;
        while(nrcif <= q){
            int x = j;
            nrz=0;
            do{
                nrz++;
                z[nrz] = x%10;
                x = x/10;
            }while(x > 0);
            for(int j = nrz; j >= 0; j--){
                nrcif++;
                if(p <= nrcif && nrcif <= q){
                    s = s+z[j];
                }
            }
            j++;
        }
        fout << s << '\n';
    }
    return 0;
}
