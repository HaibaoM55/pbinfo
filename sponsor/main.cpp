#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("sponsor.in");
ofstream fout("sponsor.out");
int cer, n;
struct str{
    char c[132];
    char st, fn;
    int l;
}s[56];
int z[14];
char sm[14][56][132];
int f[16];
int main(){
    fin >> cer >> n;
    fin.get();
    for(int i = 1; i <= n; i++){
        fin.get(s[i].c, 132);
        fin.get();
        s[i].l = strlen(s[i].c);
        s[i].st = s[i].c[0];
        s[i].fn = s[i].c[s[i].l-1];
        if(s[i].st == 'O' && s[i].fn == 'I'){
            f[1]++;z[1]++;strcpy(sm[1][z[1]], s[i].c);
        }
        if(s[i].st == 'L' && s[i].fn == 'N'){
            f[2]++;z[2]++;strcpy(sm[2][z[2]], s[i].c);
        }
        if(s[i].st == 'I' && s[i].fn == 'F'){
            f[3]++;z[3]++;strcpy(sm[3][z[3]], s[i].c);
        }
        if(s[i].st == 'M' && s[i].fn == 'O'){
            f[4]++;z[4]++;strcpy(sm[4][z[4]], s[i].c);
        }

        if(s[i].st == 'P' && s[i].fn == 'R'){
            f[5]++;z[5]++;strcpy(sm[5][z[5]], s[i].c);
        }

        if(s[i].st == 'I' && s[i].fn == 'M'){
            f[6]++;z[6]++;strcpy(sm[6][z[6]], s[i].c);
        }

        if(s[i].st == 'A' && s[i].fn == 'A'){
            f[7]++;z[7]++;strcpy(sm[7][z[7]], s[i].c);
        }

        if(s[i].st == 'D' && s[i].fn == 'T'){
            f[8]++;z[8]++;strcpy(sm[8][z[8]], s[i].c);
        }
        if(s[i].st == 'A' && s[i].fn == 'I'){
            f[9]++;z[9]++;strcpy(sm[9][z[9]], s[i].c);
        }

        if(s[i].st == 'D' && s[i].fn == 'C'){
            f[10]++;z[10]++;strcpy(sm[10][z[10]], s[i].c);
        }
        if(s[i].st == 'E' && s[i].fn == 'A'){
            f[11]++;z[11]++;strcpy(sm[11][z[11]], s[i].c);
        }
    }
    long long p = 1;
    for(int i = 1; i <= 11; i++){
        p = p*f[i];
    }
    if(cer == 1){
        fout << p;
    }else{
        for(int i = 1; i <= 11; i++){
            char rasp[134];
            strcpy(rasp, sm[i][1]);
            for(int j = 2; j <= z[i]; j++){
                if(strcmp(rasp, sm[i][j]) > 0){
                    strcpy(rasp, sm[i][j]);
                }
            }
            fout << rasp << '\n';
        }
    }
    return 0;
}
