#include <fstream>
#include <math.h>
using namespace std;
ifstream fin("tg.in");
ofstream fout("tg.out");
int n;
bool ciur[4000004];
int nrp=0, prm[400004];
int e = 0;
int main()
{
    fin >> n;
    int nr = 0;
    for(int i = 1; i <= n; i++){
        if(ciur[i] == 0){
            for(int j = 1; j*j <= n/i; j++){
                nr += j-1;
                ciur[j*j*i]=i;
            }
        }
    }
    fout << nr;
    return 0;
}
