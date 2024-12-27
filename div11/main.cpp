#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("div11.in");
ofstream fout("div11.out");
int n;
long long x;
int rst[100004][20];
int nrc[100004];
int f[20][20];
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
        long long p = x;
        int nrcif = 0;
        do{
            nrcif++;
            p = p/10;
        }while(p > 0);
        nrc[i] = nrcif;
        long long rest = x%11;
        f[nrcif][rest]++;
        rst[i][0] = rest;
        for(int j = 1; j <= 17; j++){
            rest = rest*10;
            rest = rest%11;
            rst[i][j] = rest;
        }
    }
    long long nr = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 17; j++){
            int val = 11-rst[i][j];
            val = val%11;
            nr += f[j][val];
            if(val == rst[i][0] && j == nrc[i]){
                nr--;
            }
        }
    }
    fout << nr;
    return 0;
}
