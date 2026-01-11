#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("circular.in");
ofstream fout("circular.out");
int cer;
char c[50004];
char alfa[50004];
int difc[27][27];
char rasp[100004];
int main(){
    fin >> cer;
    fin >> c;
    char lit = 'A';
    int l = strlen(c);
    for(int i = 0; i <= 26; i++){
        for(int j = 0; j <= 26; j++){
            difc[i][j] = -1;
        }
    }
    for(int i = 0; i < 26; i++){
        int c1 = i;
        int c2 = i;
        for(int j = 0; j < 26; j++){
            if(difc[i][c1] == -1){
                difc[i][c1] = j;
            }
            if(difc[i][c2] == -1){
                difc[i][c2] = j;
            }
            c1++;
            c2--;
            if(c1 == 26){
                c1 = 0;
            }
            if(c2 == -1){
                c2 = 25;
            }
        }
    }
    fin >> alfa;
    int lalfa = strlen(alfa);
    if(cer == 1){
        int nr = 0;
        for(int i = 0; i < l; i++){
            nr += difc[lit-'A'][c[i]-'A'];
            lit = c[i];
        }
        fout << nr;
    }else{
        int nr = difc[0][c[0]-'A'];
        long long p = 1;
        int z = 0;
        for(int i = 0; i < l-1; i++){
            rasp[z] = c[i];
            z++;
            int difmin = 2e9;
            int difmiv = 1;
            int difmini= 0;
            for(int j = 0; j < lalfa; j++){
                int dif = difc[c[i]-'A'][alfa[j]-'A']+difc[alfa[j]-'A'][c[i+1]-'A'];
                if(dif < difmin){
                    difmin = dif;
                    difmiv=1;
                    difmini = j;
                }else if(dif == difmin){
                    difmiv++;
                }
            }
            nr += difmin;
            rasp[z] = alfa[difmini];
            z++;
            p = p*difmiv;
            p = p%666013;
        }
        rasp[z] = c[l-1];
        z++;
        rasp[z] = 0;
        fout << nr << '\n';
        fout << p << '\n';
        fout << rasp;
    }
    return 0;
}
