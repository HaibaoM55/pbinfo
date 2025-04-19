#include <fstream>
using namespace std;
ifstream fin("subnumar.in");
ofstream fout("subnumar.out");
int n;
int f[104];
int vmax = 0;
int main(){
    while(fin >> n){
        while(n > 10){
            int x = n%10;
            int y = n/10%10;
            f[y*10+x]++;
            n = n/10;
            vmax = max(vmax, f[y*10+x]);
        }
    }
    for(int i = 99; i >= 10; i--){
        if(f[i] == vmax){
            fout << i << ' ';
        }
    }
    return 0;
}
