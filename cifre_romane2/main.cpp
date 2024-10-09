#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("cifre_romane2.in");
ofstream fout("cifre_romane2.out");
int a, c1;
char b[20][4] = {"I","V","X","L","C","D","M","(V)","(X)","(L)","(C)","(D)","(M)"};
int c[20] = {1, 5, 10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000};
int vp[1003];
int z = 0;
char bc[1004][4];
int nbc =0;
void cifre_romane(int n, bool scrie){
    if(n == 0){
        return;
    }
    int p = n;
    int z = 1;
    while(p >= 10){
        z = z*10;
        p = p/10;
    }
    int y = z*p;
    int poz;
    for(int i = 0; i <= 12; i++){
        if(c[i] == z){
            poz = i;
            break;
        }
    }
    if(1 <= p && p <= 3){
        for(int i = 1; i <= p; i++){
            nbc++;
            strcpy(bc[nbc], b[poz]);
            if(scrie){
                fout << b[poz];
            }
        }
    }else if(p == 4){
        nbc++;
        strcpy(bc[nbc], b[poz]);
        nbc++;
        strcpy(bc[nbc], b[poz+1]);
        if(scrie){
            fout << b[poz] << b[poz+1];
        }
    }else if(p == 5){
        nbc++;
        strcpy(bc[nbc], b[poz+1]);
        if(scrie){
            fout << b[poz+1];
        }
    }else if(6 <= p && p <= 8){
        nbc++;
        strcpy(bc[nbc], b[poz+1]);
        if(scrie){
            fout << b[poz+1];
        }
        for(int i = 1; i <= p-5; i++){
            nbc++;
            strcpy(bc[nbc], b[poz]);
            if(scrie){
                fout << b[poz];
            }
        }
    }else{
        nbc++;
        strcpy(bc[nbc], b[poz]);
        nbc++;
        strcpy(bc[nbc], b[poz+2]);
        if(scrie){
            fout << b[poz] << b[poz+2];
        }
    }
    cifre_romane(n-y, scrie);
}
int numar = 0;
int n;
int main()
{
    fin >> c1;
    if(c1 == 1){
        fin >> a;
        cifre_romane(a, true);
    }else{
        char x[1004];
        fin >> x;
        int l = strlen(x);
        for(int i = 0; i < l; i++){
            if(x[i] == '('){
                for(int j = 7; j <= 13; j++){
                    if(x[i+1] == b[j][1]){
                        z++;
                        vp[z] = j;
                        break;
                    }
                }
                i += 2;
            }else{
                for(int j = 0; j <= 6; j++){
                    if(x[i] == b[j][0]){
                        z++;
                        vp[z] = j;
                        break;
                    }
                }
            }
        }
        int s = 0;
        int nr = 0;
        for(int i = 1; i <= z-1; i++){
            if(vp[i] < vp[i+1]){
                s -= c[vp[i]];
            }else{
                s += c[vp[i]];
            }
        }
        s += c[vp[z]];
        cifre_romane(s, false);
        char pvc[4004];
        int lpvc = 0;
        for(int i = 1; i <= nbc; i++){
            int lg = strlen(bc[i]);
            for(int j = 0; j < lg; j++){
                pvc[lpvc] = bc[i][j];
                lpvc++;
            }
        }
        pvc[lpvc] = 0;
        if(strcmp(x, pvc) == 0){
            fout << s;
        }else{
            fout << "Numar invalid";
        }
    }
    return 0;
}
