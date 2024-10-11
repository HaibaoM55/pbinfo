#include <fstream>
using namespace std;
ifstream fin("maxim5.in");
ofstream fout("maxim5.out");
int n;
int miniml=1000000000;
int maxim = 0;
int vmax = 0;
int main()
{
    while(fin >> n){
        int lg = 1;
        vmax = n;
        while(fin >> n){
            if(n == 0){
                break;
            }else if(n > vmax){
                vmax = n;
            }
            lg++;
        }
        if(lg < miniml){
            miniml = lg;
            maxim = vmax;
        }else if(lg == miniml){
            if(maxim < vmax){
                maxim = vmax;
            }
        }
    }
    fout << maxim;
    return 0;
}
