#include <fstream>
#include <string.h>
#include <algorithm>
using namespace std;
ifstream fein("kps.in");
ofstream fout("kps.out");
int c;
char x[1003];
struct schar{
    char x[104];
};
struct k1{
    int nr = 0;
    schar y[5004];
}v[104];
int l;
bool compara(schar a, schar b){
    if(strcmp(a.x, b.x) < 0){
        return true;
    }
    return false;
}
int main()
{
    fein >> c;
    if(c == 1){
        fein >> x;
        l = strlen(x);
        int k = 0;
        for(int i = 1; i <= l-1; i++){
            char p1[1003];
            char p2[1003];
            int z = 0;
            for(int j = 0; j <= i-1; j++){
                p1[j] = x[j];
            }
            p1[i] = 0;
            for(int j = l-i; j < l; j++){
                p2[z] = x[j];
                z++;
            }
            p2[z] = 0;
            if(strcmp(p1, p2) == 0){
                k = i;
            }
        }
        fout << k;
    }else{
        int max_k = 0;
        while(fein >> x){
            l = strlen(x);
            int k = 0;
            for(int i = 1; i <= l-1; i++){
                char p1[103];
                char p2[103];
                int z = 0;
                for(int j = 0; j <= i-1; j++){
                    p1[j] = x[j];
                }
                p1[i] = 0;
                for(int j = l-i; j < l; j++){
                    p2[z] = x[j];
                    z++;
                }
                p2[z] = 0;
                if(strcmp(p1, p2) == 0){
                    k = i;
                }
            }
            v[k].nr++;
            strcpy(v[k].y[v[k].nr].x, x);
            max_k = max(k, max_k);
        }
        for(int i = 0; i <= max_k; i++){
            fout << v[i].nr << ' ';
            sort(v[i].y+1, v[i].y+v[i].nr+1, compara);
            for(int j = 1; j <= v[i].nr; j++){
                fout << v[i].y[j].x << ' ';
            }
            fout << '\n';
        }
    }
    return 0;
}
