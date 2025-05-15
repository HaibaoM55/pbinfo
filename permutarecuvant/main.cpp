#include <fstream>
#include <algorithm>
#include <string.h>
using namespace std;
ifstream fin("permutarecuvant.in");
ofstream fout("permutarecuvant.out");
char x[23];
int main(){
    fin >> x;
    int n = strlen(x);
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            fout << x[j];
        }
        for(int j = 0; j < i; j++){
            fout << x[j];
        }
        fout << ' ' ;
    }
    return 0;
}
