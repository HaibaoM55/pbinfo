#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("anagrame2.in");
ofstream fout("anagrame2.out");
int f[61], fa[61];
char sir[100004], cuv[25004];
int ls, lc;
int nr = 0;
int c = 0;
bool frst=true;
int main()
{
    fin >> c;
    fin >> sir;
    ls = strlen(sir);
    fin >> cuv;
    lc = strlen(cuv);
    for(int i = 0; i < lc; i++){
        if('a' <= sir[i] && sir[i] <= 'z'){
            f[sir[i]-'a']++;
        }else{
            f[sir[i]-'A'+30]++;
        }
        if('a' <= cuv[i] && cuv[i] <= 'z'){
            fa[cuv[i]-'a']++;
        }else{
            fa[cuv[i]-'A'+30]++;
        }
    }
    bool ok = true;
    for(int j = 0; j <= 60; j++){
        if(f[j] != fa[j]){
            ok = false;
            break;
        }
    }
    if(ok){
        if(c == 1){
            for(int i = 0; i < lc; i++){
                fout << sir[i];
            }
            return 0;
        }
        nr++;
    }
    for(int i = lc; i < ls; i++){
        if('a' <= sir[i-lc] && sir[i-lc] <= 'z'){
            f[sir[i-lc]-'a']--;
        }else{
            f[sir[i-lc]-'A'+30]--;
        }
        if('a' <= sir[i] && sir[i] <= 'z'){
            f[sir[i]-'a']++;
        }else{
            f[sir[i]-'A'+30]++;
        }
        bool ok = true;
        for(int j = 0; j <= 60; j++){
            if(f[j] != fa[j]){
                ok = false;
                break;
            }
        }
        if(ok){
            if(c == 1){
                for(int j = i-lc+1; j <= i; j++){
                    fout << sir[j];
                }
                return 0;
            }
            nr++;
        }
    }
    if(c == 2){
        fout << nr;
    }
    return 0;
}
