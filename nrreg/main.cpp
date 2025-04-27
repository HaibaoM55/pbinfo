#include <fstream>
using namespace std;
#define int long long
ifstream fin("nrreg.in");
ofstream fout("nrreg.out");
int n;
int reg[10000];
long long a = 2, b = 3, c = 5, ultim = 1;
signed main(){
    fin >> n;
    int p = 1;
    reg[0] = 1;
    long long x=0, y=0, z=0;
    for(int i=1; i<n; i++){
       ultim = min(min(a, b), c);
       reg[i] = ultim;
       if(ultim == a)
           x++;
           a = reg[x]*2;
       if(ultim == b){
           y++;
           b = reg[y]*3;
       }
       if(ultim == c){
           z++;
           c = reg[z]*5;
       }
    }
    fout << ultim << ' ';
    int ex2=0, ex3=0, ex5=0;
    int numar = ultim;
    while(numar % 2 == 0){
        numar = numar/2;
        ex2++;
    }
    while(numar % 3 == 0){
        numar = numar/3;
        ex3++;
    }
    while(numar % 5 == 0){
        numar = numar/5;
        ex5++;
    }
    ex2 = ex2-ex2%2;
    ex3 = ex3-ex3%2;
    ex5 = ex5-ex5%2;
    p = 1;
    for(int i = 1; i <= ex2; i++){
        p = p*2;
    }
    for(int i = 1; i <= ex3; i++){
        p = p*3;
    }
    for(int i = 1; i <= ex5; i++){
        p = p*5;
    }
    fout << ultim/p << ' ' << p;
    return 0;
}
