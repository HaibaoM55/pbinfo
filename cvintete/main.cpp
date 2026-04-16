#pragma GCC optimize("O3, Ofast, unroll-loops")
#include <fstream>
#include <map>
#include <math.h>
using namespace std;
#define MOD 1000000007
#define int long long
ifstream fin("cvintete.in");
ofstream fout("cvintete.out");
int n, d;
int s[100004];
bool verif(int i1, int i2, int i3, int i4, int i5){
    int a = s[i1], b = s[i2], c = s[i3];
    int x = s[i4], y = s[i5];
    if(a < b && b < c){
        if(x != y){
            if(1LL*a*x*x + 1LL*b*y*y == 1LL*c*c){
                if(1LL*a*b*c == d){
                    return true;
                }
            }
        }
    }
    return false;
}
map<int, int> f;
map<int, int> fd;
signed main(){
    fin >> n >> d;
    for(int i = 1; i <= n; i++){
        fin >> s[i];
        f[s[i]]++;
        if(d % s[i] == 0){
            fd[s[i]]++;
        }
    }
    int nr = 0;
    for(auto a1: fd){
        for(auto b1: fd){
            int a = a1.first;
            int b = b1.first;
            if(a >= b){
                continue;
            }
            if(a*b > d){
                continue;
            }
            if(d % (a*b) != 0){
                continue;
            }
            int c = d/(a*b);
            if(f[c] == 0 || c <= b){
                continue;
            }
            for(auto x1: f){
                int x = x1.first;
                //1LL*a*x*x+b*y*y=1LL*c*c;
                int byy = 1LL*c*c-1LL*a*x*x;
                if(byy > 0 && byy % b == 0){
                    int yy = byy/b;
                    int y = sqrt(yy);
                    if(y*y == yy && x != y){
                        nr += a1.second*b1.second*f[c]*x1.second*f[y];
                        nr = nr % MOD;
                    }
                }
            }
        }
    }
    fout << nr;
    return 0;
}
