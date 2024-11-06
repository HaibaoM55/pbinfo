#define MAX 1000006
#include <fstream>
using namespace std;
ifstream fein("tramvaie.in");
ofstream fout("tramvaie.out");
#define MAX 1000011
int n, m;
int F[1000011];
int main()
{
    fein >> n;
    for(int i = 1; i <= MAX; i++){
        F[i] = i;
    }
    for(int i = 2; i <= MAX; i++){
        if(F[i] == i){
            F[i]--;
            for(int j = 2; j*i <= MAX; j++){
                F[j*i] = (F[j*i] / i) * (i - 1);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        fein >> m;
        fout << F[m] << ' ';
    }
    return 0;
}
