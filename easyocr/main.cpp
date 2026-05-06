#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("easyocr.in");
ofstream fout("easyocr.out");
class Cifra{
    private:
    public:
        int NrCif, lin, col;
        char a[10][10];
        Cifra(int nc, int n, int m, char v[10][10]){
            NrCif = nc;
            lin = n;
            col = m;
            for(int i = 1; i <= lin; i++){
                for(int j = 1; j <= col; j++){
                    a[i][j] = v[i][j];
                }
            }
        }
        Cifra(){
            NrCif = 0;
            lin = 0;
            col = 0;
        }
};
char sp[10][10];
Cifra cifre[14];
void init(){
    //zero
    strcpy(sp[1], "x11111");
    strcpy(sp[2], "x10001");
    strcpy(sp[3], "x10001");
    strcpy(sp[4], "x10001");
    strcpy(sp[5], "x10001");
    strcpy(sp[6], "x10001");
    strcpy(sp[7], "x11111");
    cifre[0] = Cifra(0, 7, 5, sp);
    //unu
    strcpy(sp[1], "x01");
    strcpy(sp[2], "x11");
    strcpy(sp[3], "x01");
    strcpy(sp[4], "x01");
    strcpy(sp[5], "x01");
    strcpy(sp[6], "x01");
    strcpy(sp[7], "x01");
    cifre[1] = Cifra(1, 7, 2, sp);
    //doi
    strcpy(sp[1], "x11111");
    strcpy(sp[2], "x00001");
    strcpy(sp[3], "x00001");
    strcpy(sp[4], "x11111");
    strcpy(sp[5], "x10000");
    strcpy(sp[6], "x10000");
    strcpy(sp[7], "x11111");
    cifre[2] = Cifra(2, 7, 5, sp);
    //trei
    strcpy(sp[1], "x11111");
    strcpy(sp[2], "x00001");
    strcpy(sp[3], "x00001");
    strcpy(sp[4], "x11111");
    strcpy(sp[5], "x00001");
    strcpy(sp[6], "x00001");
    strcpy(sp[7], "x11111");
    cifre[3] = Cifra(3, 7, 5, sp);
    //patru
    strcpy(sp[1], "x10001");
    strcpy(sp[2], "x10001");
    strcpy(sp[3], "x10001");
    strcpy(sp[4], "x11111");
    strcpy(sp[5], "x00001");
    strcpy(sp[6], "xxxx01");
    strcpy(sp[7], "xxxx01");
    cifre[4] = Cifra(4, 7, 5, sp);
    //cinci
    strcpy(sp[1], "x11111");
    strcpy(sp[2], "x10000");
    strcpy(sp[3], "x10000");
    strcpy(sp[4], "x11111");
    strcpy(sp[5], "x00001");
    strcpy(sp[6], "x00001");
    strcpy(sp[7], "x11111");
    cifre[5] = Cifra(5, 7, 5, sp);
    //sase
    strcpy(sp[1], "x11111");
    strcpy(sp[2], "x10000");
    strcpy(sp[3], "x10000");
    strcpy(sp[4], "x11111");
    strcpy(sp[5], "x10001");
    strcpy(sp[6], "x10001");
    strcpy(sp[7], "x11111");
    cifre[6] = Cifra(6, 7, 5, sp);
    //sapte
    strcpy(sp[1], "x11111");
    strcpy(sp[2], "x00001");
    strcpy(sp[3], "x00001");
    strcpy(sp[4], "x00010");
    strcpy(sp[5], "x00100");
    strcpy(sp[6], "xx010x");
    strcpy(sp[7], "xx010x");
    cifre[7] = Cifra(7, 7, 5, sp);
    //opt
    strcpy(sp[1], "x11111");
    strcpy(sp[2], "x10001");
    strcpy(sp[3], "x10001");
    strcpy(sp[4], "x11111");
    strcpy(sp[5], "x10001");
    strcpy(sp[6], "x10001");
    strcpy(sp[7], "x11111");
    cifre[8] = Cifra(8, 7, 5, sp);
    //noua
    strcpy(sp[1], "x11111");
    strcpy(sp[2], "x10001");
    strcpy(sp[3], "x10001");
    strcpy(sp[4], "x11111");
    strcpy(sp[5], "x00001");
    strcpy(sp[6], "x00001");
    strcpy(sp[7], "x11111");
    cifre[9] = Cifra(9, 7, 5, sp);
}
int n, m;
char a[1014][1014];
int nc(int x, int y){
    for(int i = 0; i < 10; i++){
        bool ok = true;
        for(int i1 = x; i1 <= x+cifre[i].lin-1 && ok; i1++){
            for(int j1 = y; j1 <= y+cifre[i].col-1; j1++){
                if(a[i1][j1] != cifre[i].a[i1-x+1][j1-y+1] && cifre[i].a[i1-x+1][j1-y+1] != 'x'){
                    ok = false;
                    break;
                }
            }
        }
        if(ok){
            return i;
        }
    }
    return 10;
}
int f[67];
int main(){
    init();
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j =1; j <= m; j++){
            fin >> a[i][j];
        }
    }
    int nr = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            f[nc(i, j)]++;
        }
    }
    for(int i = 0; i < 10; i++){
        nr += f[i];
    }
    fout << nr << '\n';
    for(int i = 0; i < 10; i++){
        if(f[i] > 0){
            fout << i << ' ' <<f[i] << ' ';
        }
    }
    return 0;
}
