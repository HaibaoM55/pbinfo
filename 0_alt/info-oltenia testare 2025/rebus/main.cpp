#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("rebus.in");
ofstream fout("rebus.out");
int n;
char a[505][505];
int k;
char x[505];
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            fin >> a[i][j];
            if('A' <= a[i][j] && a[i][j] <= 'Z'){
                a[i][j] = (a[i][j]-'A')+'a';
            }
        }
    }
    fin >> k;
    for(int z1 = 1; z1 <= k; z1++){
        fin >> x;
        int l = strlen(x);
        bool okm = false;
        for(int i = 0; i < l; i++){
            if('A' <= x[i] && x[i] <= 'Z'){
                x[i] = (x[i]-'A')+'a';
            }
        }
        for(int i = 1; i <= n && okm == false; i++){
            for(int j = 1; j <= n; j++){
                if(i <= n-l+1){
                    bool ok = true;
                    for(int i1 = i; i1 <= i+l-1; i1++){
                        if(a[i1][j] != x[i1-i]){
                            ok = false;
                            break;
                        }
                    }
                    if(ok){
                        okm = true;
                        break;
                    }
                }
                if(j <= n-l+1){
                    bool ok = true;
                    for(int j1 = j; j1 <= j+l-1; j1++){
                        if(a[i][j1] != x[j1-j]){
                            ok = false;
                            break;
                        }
                    }
                    if(ok){
                        okm = true;
                        break;
                    }
                }
            }
        }
        fout << okm;
    }
    return 0;
}
