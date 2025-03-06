#include <fstream>
using namespace std;
ifstream fin("razboi.in");
ofstream fout("razboi.out");
int n, t;
int ciur[100004];
int p=0, d=0;
int main()
{
    fin >> n >> t;
    if(t == 1){
        for(int i = 1; i <= n; i++){
            int x;
            fin >> x;
            if(x % 2 == 0){
                p++;
            }else{
                d++;
            }
        }
    }else{
        for(int i = 1; i <= 100000; i++){
            for(int j = i; j <= 100000; j+=i){
                ciur[j] += i;
            }
        }
        for(int i = 1; i <= n; i++){
            int x;
            fin >> x;
            if(ciur[x] % 2 == 0){
                p++;
            }else{
                d++;
            }
        }
    }
    fout <<p << ' ' << d;
    return 0;
}
