#include <fstream>
using namespace std;
ifstream fin("npe.in");
ofstream fout("npe.out");
int n;
int main()
{
    fin >> n;
    int p = 0;
    while(true){
        p++;
        if(n <= p*p){
            break;
        }else{
            n = n-(p*p);
        }
    }
    fout << p << ' ';
    int nrz = 0;
    int p1 = 0;
    while(p1 < p/2){
        for(int i = 1+p1; i <= p-p1-1; i++){
            nrz++;
            if(nrz == n){
                fout << 1+p1 << ' ' << i;
                return 0;
            }
        }
        for(int i = 1+p1; i <= p-p1-1; i++){
            nrz++;
            if(nrz == n){
                fout << i << ' ' << p-p1;
                return 0;
            }
        }
        for(int i = p-p1; i >= 2+p1; i--){
            nrz++;
            if(nrz == n){
                fout << p-p1 << ' ' << i;
                return 0;
            }
        }
        for(int i = p-p1; i >= 2+p1; i--){
            nrz++;
            if(nrz == n){
                fout << i << ' ' << 1+p1;
                return 0;
            }
        }
        p1++;
    }
    return 0;
}
