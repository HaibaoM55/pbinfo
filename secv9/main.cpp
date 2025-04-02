#include <fstream>
using namespace std;
ifstream fin("secv9.in");
ofstream fout("secv9.out");
int c, n, x;
int s[1000004];
long long f[14], v[14], vec[1000004];
int secvmax=0;
int secvmaxi, secvmaxj;
int main(){
    fin >> c >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
        vec[i] = x;
        s[i] = x%9;
        s[i] = (s[i-1]+s[i])%9;
    }
    long long nr = 0;
    for(int j = 0; j <= 9; j++){
        v[j] = -1;
    }
    if(c == 1){
        for(int i = 1; i <= n; i++){
            if(s[i] == 0 && vec[i] != 0){
                secvmax = i;
            }else if(s[i] != 0 && vec[i] != 0){
                if(v[s[i]] != -1){
                    if(i-v[s[i]] > secvmax){
                        secvmax = i-v[s[i]];
                    }
                }else{
                    v[s[i]] = i;
                }
            }
        }
        fout << secvmax;
    }else{
        nr = 0;
        f[0] = 1;
        long long op = 0;
        s[0] = 0;
        for(int i = 1; i <= n; i++){
            f[s[i]]++;
            if(vec[i] == 0){
                op++;
            }else{
                op = 0;
            }
            nr -= op;
        }
        for(int i = 0; i <= 8; i++){
            nr = nr+(f[i]*(f[i]-1))/2;
        }
        fout << nr;
    }
    return 0;
}
