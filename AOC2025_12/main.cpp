#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("a.in");
ofstream fout("a.out");
int v[7];
char x[504];
int main(){
    for(int i = 0; i <= 95; i++){
        fin.get();
    }
    v[0] = 5;
    v[1] = 7;
    v[2] = 7;
    v[3] = 7;
    v[4] = 6;
    v[5] = 7;
    int rasp=0;
    for(int i = 1; i <= 1000; i++){
        fin.get(x, 504);
        fin.get();
        int l = strlen(x);
        int l1 = (x[0]-'0')*10+x[1]-'0';
        int l2 = (x[3]-'0')*10+x[4]-'0';
        int arie = l1*l2;
        int nr[7], z = 0;
        for(int j = 7; j < l; j += 3){
            nr[z] = (x[j]-'0')*10;
            nr[z] += x[j+1]-'0';
            z++;
        }
        int suma = 0;
        for(int j = 0; j <= 5; j++){
            suma += nr[j]*v[j];
        }
        if(arie >= suma){
            rasp++;
        }
    }
    fout << rasp;
    return 0;
}
