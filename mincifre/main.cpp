#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("mincifre.in");
ofstream fout("mincifre.out");
int f[14];
char x;
int main(){
    while(fin >> x){
        f[x-'0']++;
    }
    for(int i = 1; i <= 9; i++){
        if(f[i]){
            fout << i;
            f[i]--;
            break;
        }
    }
    while(f[0]){
        fout << 0;
        f[0]--;
    }
    for(int i = 1; i <= 9; i++){
        while(f[i]){
            fout <<i;
            f[i]--;
        }
    }
    return 0;
}
