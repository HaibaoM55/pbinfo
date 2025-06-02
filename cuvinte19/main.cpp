#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
char x[256];
char c[16];
int f[34];
int z = 0;
int nr = 0;
struct str{
    char x[16];
}v[104];
bool compara(str a, str b){
    return strcmp(a.x, b.x) < 0;
}
int main()
{
    cin.get(x, 256);
    int l = strlen(x);
    for(int i = 0; i <= l; i++){
        if('a' <= x[i] && x[i] <= 'z'){
            c[z] = x[i];
            z++;
        }else if(z > 0){
            for(int j = 0; j < z; j++){
                f[c[j]-'a']++;
            }
            c[z] = 0;
            bool ok = true;
            for(int j = 0; j <= 26; j++){
                if(f[j] > 1){
                    ok = false;
                }
                f[j] = 0;
            }
            c[z] = 0;
            if(ok){
                nr++;
                strcpy(v[nr].x, c);
            }
            z = 0;
        }
    }
    sort(v+1, v+nr+1, compara);
    for(int i = 1; i <= nr; i++){
        cout << v[i].x << '\n';
    }
    if(nr == 0){
        cout << "nu exista";
    }
    return 0;
}
