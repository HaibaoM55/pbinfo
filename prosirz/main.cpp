#include <fstream>
#include <algorithm>
#include <string.h>
using namespace std;
ifstream fin("prosirz.in");
ofstream fout("prosirz.out");
char s[204];
struct cuvant{
    char c[204];
}cuv[204];
char vocale[] = "aeiou";
bool compara(cuvant a, cuvant b){
    return strcmp(a.c, b.c) > 0;
}
int main(){
    fin.get(s, 204);
    int l = strlen(s);
    int nrc = 1, nrvoc = 0;
    int j = 0;
    for(int i = 0; i <= l; i++){
        if('a' <= s[i] && s[i] <= 'z'){
            if(strchr(vocale, s[i]) != 0){
                nrvoc++;
            }
            cuv[nrc].c[j] = s[i];
            j++;
        }else{
            if(j > 0){
                s[i-1] = 'Z';
                cuv[nrc].c[j] = 0;
                nrc++;
                j = 0;
            }
        }
    }
    fout << nrvoc << '\n';
    nrc--;
    fout << s << '\n';
    sort(cuv+1, cuv+nrc+1, compara);
    for(int i = 1; i <= nrc; i++){
        fout << cuv[i].c << ' ';
    }
    return 0;
}
