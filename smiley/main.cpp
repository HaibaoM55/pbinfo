#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("smiley.in");
ofstream fout("smiley.out");
int n;
int p = 1;
char p1[6] =":;>8";
char p3[10]="()[]DPOX3";
char x[256];
int l = 0;
int main(){
    int nr = 0;
    while(fin.getline(x, 256)){
        int l = strlen(x);
        int i = 0;
        while(i < l){
            if(strchr(p1, x[i])){
                i++;
                while(i < l && x[i] == '-'){
                    i++;
                }
                if(i < l && x[i] != 0 && strchr(p3, x[i])){
                    nr++;
                    i++;
                }
            }else{
                i++;
            }
        }
    }
    fout << nr;
    return 0;
}
