//claudel
#include <fstream>
#include <string.h>
#include <map>
using namespace std;
ifstream fin("adfgvx.in");
ofstream fout("adfgvx.out");
int cer;
char x[10][10];
char cuv[1000004], cheie[30];
struct poz{ int i,j; };
map<char, poz> f;
char v[2000004];
char word[1000004];
int col_start[30], col_len_arr[30];
int c[30];
char tocaracter(int x1){
    if(x1 == 1) return 'A';
    if(x1 == 2) return 'D';
    if(x1 == 3) return 'F';
    if(x1 == 4) return 'G';
    if(x1 == 5) return 'V';
    if(x1 == 6) return 'X';
}
int toint(char x1){
    if(x1 == 'A') return 1;
    if(x1 == 'D') return 2;
    if(x1 == 'F') return 3;
    if(x1 == 'G') return 4;
    if(x1 == 'V') return 5;
    if(x1 == 'X') return 6;
}
int main(){
    fin >> cer;
    for(int i = 1; i <= 6; i++)
        for(int j = 1; j <= 6; j++){
            fin >> x[i][j];
            f[x[i][j]].i = i;
            f[x[i][j]].j = j;
        }
    if(cer == 1){
        fin >> cuv >> cheie;
        int l = strlen(cuv);
        int lc = strlen(cheie);
        for(int i = 0; i < l; i++){
            v[2*i]   = tocaracter(f[cuv[i]].i);
            v[2*i+1] = tocaracter(f[cuv[i]].j);
        }
        l = l*2;
        int rows_full = l / lc;
        int extra = l % lc;
        for(char lm='A';lm<='Z';lm++){
            for(int j=0;j<lc;j++){
                if(cheie[j]==lm){
                    int len = rows_full + (j < extra ? 1 : 0);
                    for(int i=0;i<len;i++)
                        fout << v[i*lc + j];
                    fout << " ";
                }
            }
        }
    } else {
        int p = 0;
        int offset = 0;
        while(fin >> word){
            int len = strlen(word);
            col_start[p] = offset;
            col_len_arr[p] = len;
            for(int i = 0; i < len; i++)
                v[offset + i] = word[i];
            offset += len;
            p++;
        }
        p--;

        int lc = col_len_arr[p];
        for(int i = 0; i < lc; i++)
            cheie[i] = v[col_start[p] + i];
        cheie[lc] = 0;

        int l_total = 0;
        for(int i = 0; i < p; i++)
            l_total += col_len_arr[i];

        int rows_full = l_total / lc;

        int pm = 0;
        for(char lm='A';lm<='Z';lm++){
            for(int j=0;j<lc;j++){
                if(cheie[j]==lm){
                    c[j] = pm++;
                    break;
                }
            }
        }

        int total_rows = rows_full + 1;
        char c1;
        int cnt = 0;
        for(int i = 0; i < total_rows; i++){
            for(int j = 0; j < lc; j++){
                int rang = c[j];
                // folosim lungimea reala citita din input
                int len = col_len_arr[rang];
                if(i < len){
                    char ch = v[col_start[rang] + i];
                    if(cnt % 2 == 0) c1 = ch;
                    else fout << x[toint(c1)][toint(ch)];
                    cnt++;
                }
            }
        }
    }
    return 0;
}
