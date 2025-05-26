#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;
ifstream fin("parsare.in");
ofstream fout("parsare.out");
int vmax=-2e9,n;
int main(){
    char s[8];
    while(fin.get(s , 8 , ' ')){
        n = atoi(s);
        vmax=max(vmax,n);
        fin.get();
    }
    fout << vmax;
    return 0;
}
