#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("valori.in");
ofstream fout("valori.out");
int v[27];
int n;
char x[260];
int valmax=0, z =0;
char vmax[1004][260];
int main(){
    for(int i = 0; i < 26; i++){
        fin >> v[i];
    }
    fin.get();
    fin >> n;
    for(int i = 1; i <= n; i++){
        int s1 = 0;
        int s2 = 0;
        fin >> x;
        int l = strlen(x);
        for(int j = 0; j < l; j++){
            if('a' <= x[j] && x[j] <= 'z'){
                s1 += v[x[j]-'a'];
            }else{
                s2 += v[x[j]-'A'];
            }
        }
        int s = s1-s2;
        if(s > valmax){
            valmax = s;
            z = 1;
            for(int j = 0; j < l; j++){
                vmax[z][j] = x[j];
            }
            vmax[z][l] = 0;
        }else if(s == valmax){
            z++;
            for(int j = 0; j < l; j++){
                vmax[z][j] = x[j];
            }
            vmax[z][l] = 0;
        }
    }
    for(int i = 1; i <= z; i++){
        fout << vmax[i] << '\n';
    }
    return 0;
}
