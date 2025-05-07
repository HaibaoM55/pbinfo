#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("textcuv.in");
ofstream fout("textcuv.out");
int p;
char x[1004];
char cuv[1004][54];
int main(){
    fin >> p;
    fin.get();
    fin.get(x, 1000);
    int l = strlen(x);
    int z = 0, nr = 1;
    for(int i = 0; i < l; i++){
        if('a' <= x[i] && x[i] <= 'z'){
            cuv[nr][z] = x[i];
            z++;
        }else{
            cuv[nr][z] = 0;
            nr++;
            z = 0;
        }
    }
    int numar = 0;
    for(int i = 1; i <= nr; i++){
        if(strlen(cuv[i]) > 0){
            numar++;
        }
    }
    if(p == 1){
        fout << numar << '\n';
        for(int i = 1; i <= nr; i++){
            if(strlen(cuv[i]) > 0){
                fout << cuv[i] << '\n';
            }
        }
    }else if(p == 2){
        char cuvmin[50];
        cuvmin[0] = 0;
        for(int i = 1; i <= nr; i++){
            if(strlen(cuv[i]) > 0){
                if(cuvmin[0] == 0){
                    strcpy(cuvmin, cuv[i]);
                }
                if(strcmp(cuv[i], cuvmin) < 0){
                    strcpy(cuvmin, cuv[i]);
                }
            }
        }
        fout << cuvmin;
    }else if(p == 3){
        int numar = 0;
        for(int i = 1; i <= nr; i++){
            int l1 = strlen(cuv[i]);
            if(strlen(cuv[i]) > 0){
                bool ok = false;
                for(int j = 0; j < l1-2; j++){
                    if(cuv[i][j] == 'i' && cuv[i][j+1] == 'n' && cuv[i][j+2] == 'i'){
                        ok = true;
                        break;
                    }
                }
                if(ok){
                    numar++;
                }
            }
        }
        fout << numar;
    }else if(p == 4){
        for(int i = 1; i <= nr; i++){
            int l1 = strlen(cuv[i]);
            if(l1 > 0){
                for(int j = l1-1; j >= 0; j--){
                    fout << cuv[i][j];
                }
                fout << '\n';
            }
        }
    }else if(p == 5){
        int numar = 0;
        for(int i = 1; i <= nr; i++){
            int l1 = strlen(cuv[i]);
            if(l1 > 0){
                if(cuv[i][l1-1] == 'a'){
                    numar++;
                }
            }
        }
        fout << numar;
    }else if(p == 6){
        int numar = 0;
        int lmin = 51;
        int lmax = 0;
        for(int i = 1; i <= nr; i++){
            int l1 = strlen(cuv[i]);
            if(l1 > 0){
                lmax = max(lmax, l1);
                lmin = min(lmin, l1);
            }
        }
        fout << lmin << ' ' << lmax;
    }
    return 0;
}
