#include <fstream>
using namespace std;
ifstream fin("cmmdc1.in");
ofstream fout("cmmdc1.out");
int n, k;
int x;
int f[1000004];
int main()
{
    fin >> n >> k;
    for(int i = 1; i <= n; i++){
        fin >> x;
        f[x]++;
    }
    for(int i = 1000000; i >= 1; i--){
        int nr = 0;
        int j;
        for(j = i; j <= 1000000; j += i){
            nr += f[j];
        }
        if(nr >= k){
            fout << i << '\n';
            j-= i;
            for(j; j >= i; j -= i){
                if(f[j] <= k){
                    for(int p = 1; p <= f[j]; p++){
                        fout <<  j << ' ';
                    }
                    k -= f[j];
                }else{
                    for(int i = 1; i <= k; i++){
                        fout << j << ' ';
                    }
                    return 0;
                }
            }
        }
    }
    return 0;
}
