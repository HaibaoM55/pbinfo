#include <string.h>
#include <fstream>
using namespace std;
ifstream fin("cifre_romane1.in");
ofstream fout("cifre_romane1.out");
char m[50];
int valoare(char c){
    if(c == 'I') return 1;
    if(c == 'V') return 5;
    if(c == 'X') return 10;
    if(c == 'L') return 50;
    if(c == 'C') return 100;
    if(c == 'D') return 500;
    if(c == 'M') return 1000;
    return -1;
}
bool esteValid(char m[], int l){
    for(int i = 0; i < l; i++) {
        if(valoare(m[i]) == -1)
            return false;
    }
    int consecutiv = 1;
    for(int i = 1; i < l; i++) {
        if(m[i] == m[i-1]) {
            consecutiv++;
            if(m[i] == 'V' || m[i] == 'L' || m[i] == 'D')
                return false;
            if(consecutiv > 3)
                return false;
        } else {
            consecutiv = 1;
        }
    }
    for(int i = 0; i < l - 1; i++) {
        int v1 = valoare(m[i]);
        int v2 = valoare(m[i+1]);
        if(v1 < v2){
            if(m[i] != 'I' && m[i] != 'X' && m[i] != 'C')
                return false;
            if(m[i] == 'I' && m[i+1] != 'V' && m[i+1] != 'X')
                return false;
            if(m[i] == 'X' && m[i+1] != 'L' && m[i+1] != 'C')
                return false;
            if(m[i] == 'C' && m[i+1] != 'D' && m[i+1] != 'M')
                return false;
            if(i > 0 && valoare(m[i-1]) < v2)
                return false;
            if(i < l - 2 && valoare(m[i+2]) >= v2)
                return false;
        }
    }
	return true;
}
int main(){
    fin >> m;
    int l = strlen(m);
    if(!esteValid(m, l)) {
        fout << "Numar invalid";
        return 0;
    }
    int x = 0;
    for(int i = 0; i < l; i++){
        int v1 = valoare(m[i]);
        if(i < l - 1){
            int v2 = valoare(m[i+1]);
            if(v1 < v2){
                x -= v1;
            }else{
                x += v1;
            }
        }else{
            x += v1;
        }
    }
    fout << x;
    return 0;
}
