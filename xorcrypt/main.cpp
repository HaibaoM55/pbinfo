#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("xorcrypt.in");
ofstream fout("xorcrypt.out");
char a[267], b[267];
int v[12];
int main(){
    fin.get(a, 267);
    fin.get();
    fin.get(b, 267);
    int l = strlen(a);
    for(int i = 0; i < l; i++){
        int x = ((int)a[i] ^ (int)b[i]);
        int z = 0;
        for(int j = 0; j < 12; j++){
            v[j] = 0;
        }
        while(x){
            z++;
            v[z] = x % 2;
            x = x / 2;
        }
        for(int j = 8; j >= 1; j--){
            fout << v[j];
        }
        fout << ' ';
    }

    return 0;
}
