#include <fstream>
#include <math.h>
using namespace std;
ifstream fin("consecutive.in");
ofstream fout("consecutive.out");
long long n;
long long nr = 0, kk;
long long f[104]= {0,3,9,15,81,45,729,105,225,405,59049,315,531441,3645,2025,945,43046721,1575,0,2835,18225,295245,0,3465,50625,2657205,11025,25515,0,14175,0,10395,1476225,0,455625,17325,0,0,13286025,31185,0,127575,0,2066715,99225,0,0,45045,11390625,354375,0,18600435,0,121275,36905625,280665,0,0,0,155925,0,0,893025,135135,0,10333575,0,0,0,3189375,0,225225,0,0,2480625,0,0,93002175,0,405405,1334025,0,0,1403325,0,0,0,22733865,0,1091475,0,0,0,0,0,675675,0,79734375,72335025,3898125,0};
int main()
{
    fin >> n;
    long long i = f[n];
    if(i == 0){
        fout << 0;
        return 0;
    }
    fout << i << '\n';
    for(long long x = i/2; x >= 0; x--){
        /*
        1+2+3+...+k-1-2-3-...-x = i
        k*(k+1)/2-x*(x+1)/2 = i
        k*(k+1)-x*(x+1)= 2*i;
        k^2+k-(x^2+x+2*i)=0
        delta = 1+4x^2+4x+8i
        k = -1+sqrt(delta)/2
        */
        long long delta = 1+4LL*x*x+4LL*x+8LL*i;
        long long sq = sqrt(delta);
        if(sq*sq == delta){
            if((sq-1) % 2 == 0){
                long long k = (sq-1)/2;
                fout << k-x << '\n';
            }
        }
    }
    return 0;
}
