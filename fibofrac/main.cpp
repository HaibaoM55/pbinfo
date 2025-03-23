#include <fstream>
using namespace std;
ifstream fin("fibofrac.in");
ofstream fout("fibofrac.out");
int n;
long long nr = 0;
long long f[1000004];
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        f[i] = i;
    }
    for(int i = 2; i <= n; i++){
        if(f[i] == i){
            for(int j = 2*i; j <= n; j += i){
                f[j] -= f[j]/i;
            }
            f[i]--;
        }
    }
    for(int i = 1; i <= n; i++){
        nr += f[i];
        if(i <= n/2){
            nr += f[i];
        }
    }
    fout << nr-n-1;
    return 0;
}
