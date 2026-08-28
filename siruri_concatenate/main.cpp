#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("siruri_concatenate.in");
ofstream fout("siruri_concatenate.out");
int n;
char s[5004];
bool estecon(char x[]){
    int l = strlen(x);
    if(l % 2 != 0){
        return false;
    }
    int z = l/2;
    for(int i = 0; i < l/2; i++){
        if(x[i] != x[z]){
            return false;
        }
        z++;
    }
    return true;
}
int main(){
    fin >> n;
    int rasp = 0;
    while(n){
        fin >> s;
        if(estecon(s)){
            rasp++;
        }
        n--;
    }
    fout << rasp;
    return 0;
}
