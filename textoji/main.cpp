#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("textoji.in");
ofstream fout("textoji.out");
int n, l;
char x[10005];
char ln[1005][55];
int nrc = 0;
int main()
{
    fin >> n;
    fin.get();
    while(fin.get(x, 10005)){
        l = strlen(x);
        int litere = -1;
        for(int i = 0; i <= l-1; i++){
            int z = 0;
            char c[10005];
            while(x[i] != ' ' && x[i] != 0){
                c[z] = x[i];
                i++;
                z++;
            }
            c[z] = 0;
            if(litere+z+1 <= n){
                nrc++;
                strcpy(ln[nrc], c);
                litere = litere+z+1;
            }else{
                int ltr = n-litere;
                int ltr1 = ltr/(nrc-1);
                int ltr2 = ltr%(nrc-1);
                for(int j = 1; j <= nrc; j++){
                    fout << ln[j] << ' ';
                    for(int j1 = 1; j1 <= ltr1; j1++){
                        fout << ' ';
                    }
                    if(ltr2 > 0){
                        fout << ' ';
                        ltr2--;
                    }
                }
                fout << '\n';
                nrc = 1;
                litere = z;
                strcpy(ln[1], c);
            }
        }
        for(int j = 1; j <= nrc; j++){
            fout << ln[j] << ' ';
        }
        fout << '\n';
        fin.get();
    }
    return 0;
}
