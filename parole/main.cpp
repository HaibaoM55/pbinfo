#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("parole.in");
ofstream fout("parole.out");
int n;
char x[54];
int main(){
    fin >> n;
    fin.get();
    int nr = 0;
    for(int i = 1; i <= n; i++){
        fin.get(x, 51);
        fin.get();
        int l = strlen(x);
        bool litera_mare=false, litera_mica=false, cifra=false, caracter_special = false;
        for(int j = 0; j < l; j++){
            if('a' <= x[j] && x[j] <= 'z'){
                litera_mica=true;
            }else if('A' <= x[j] && x[j] <= 'Z'){
                litera_mare=true;
            }else if('0' <= x[j] && x[j] <= '9'){
                cifra=true;
            }else{
                caracter_special=true;
            }
        }
        if(l >= 8  && litera_mica && litera_mare && cifra && caracter_special){
            nr++;
        }
    }
    fout << nr;
    return 0;
}
