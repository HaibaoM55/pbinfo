#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("cifrevecine.in");
ofstream fout("cifrevecine.out");
char x[25];
long long maxim = 0;
int k;
int main()
{
    fin >> x;
    fin >> k;
    int l = strlen(x);
    for(int i = 0; i < l-k+1; i++){
        long long nr = 0;
        for(int j = 0; j <l; j++){
            if(i <= j && j <= i+k-1){
                continue;
            }
            nr = nr*10+x[j]-'0';
        }
        maxim = max(maxim, nr);
    }
    fout << maxim;
    return 0;
}
