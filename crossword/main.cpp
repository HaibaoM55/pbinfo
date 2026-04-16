#include <fstream>
using namespace std;
ifstream fin("crossword.in");
ofstream fout("crossword.out");
int n, m, w;
char a[1004][1004];
bool vizsus[1004][1004], vizdreapta[1004][1004];
int sus[1004][1004], dreapta[1004][1004];
int main(){
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> a[i][j];
        }
    }
    fin >> w;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!vizsus[i][j]){
                for(int k = i; k <= n; k++){
                    if(a[k][j] == '-'){
                        sus[i][j]++;
                        vizsus[k][j] = true;
                    }else{
                        break;
                    }
                }
            }
            if(!vizdreapta[i][j]){
                for(int k = j; k <= m; k++){
                    if(a[i][k] == '-'){
                        dreapta[i][j]++;
                        vizdreapta[i][k] = true;
                    }else{
                        break;
                    }
                }
            }
        }
    }
    int z = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(sus[i][j]){
                z++;
                fout << "JOS " << i << ' ' << j << '\n';
            }
            if(dreapta[i][j]){
                z++;
                fout << "DREAPTA " << i << ' ' << j << '\n';
            }
        }
    }
    fout << z;
    return 0;
}
