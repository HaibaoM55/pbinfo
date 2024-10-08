#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("cifre_romane2.in");
ofstream fout("cifre_romane2.out");
int a, c1;
char b[13][4] = {"I","V","X","L","C","D","M","(V)","(X)","(L)","(C)","(D)","(M)"};
int c[13] = {1, 5, 10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000};
void cifre_romane(int n){
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
            fout << b[poz];
        }
    }else if(p == 4){
        fout << b[poz] << b[poz+1];
    }else if(p == 5){
        fout << b[poz+1];
    }else if(6 <= p && p <= 8){
        fout << b[poz+1];
        for(int i = 1; i <= p-5; i++){
            fout << b[poz];
        }
    }else{
        fout << b[poz] << b[poz+2];
    }
    cifre_romane(n-y);
}
int numar = 0;
int n;
void cifre_arabe(int x[], int k){
    if(x[0] == 0){
        return;
    }
    if(x[0] == '('){
        int poz1, poz2;
        for(int i = 7; i <= 12; i++){
            if(x[1] == b[i][1]){
                poz1 = i;
                break;
            }
        }
        if(x[3] == '('){
            for(int i = 7; i <= 12; i++){
                if(x[4] == b[i][1]){
                    poz2 = i;
                    break;
                }
            }
            if(poz2-poz1 == 1 && poz1 % 2 == 0){
                numar = numar+c[poz1]*4;
                cifre_arabe(x+6);
            }else if(poz2-poz1 == 2 && poz1 % 2 == 0){
                numar = numar+c[poz1]*9;
                cifre_arabe(x+6);
            }else if(poz1==poz2){
                int poz3;
                if(x[6] == '('){
                    for(int i = 7; i <= 12; i++){
                        if(x[7] == b[i][1]){
                            poz3 = i;
                            break;
                        }
                    }
                    if(poz3 == poz1){
                        numar += c[poz1]*3;
                        cifre_arabe(x+9);
                    }else{
                        numar += c[poz1]*2;
                        cifre_arabe(x+6);
                    }
                }
            }else{
                numar += c[poz1];
                cifre_arabe(x+3);
            }
        }else{
            if(x[1] == 'V'){
                if(x[3] == 'M'){
                    numar += 4000;
                    cifre_arabe(x+4);
                }
            }else if(x[1] == 'X'){
                if(x[3] == 'M'){
                    numar += 9000;
                    cifre_arabe(x+4);
                }
            }else{
                numar += c[poz1];
                cifre_arabe(x+3);
            }
        }
    }else{
        for(int i = 0; i <= 6; i++){
            if(x[0] == b[i][0]){
                poz2 = i;
                break;
            }
        }
        if(poz2-poz1 == 1 && poz1 % 2 == 0){
            numar = numar+c[poz1]*4;
            cifre_arabe(x+2);
        }else if(poz2-poz1 == 2 && poz1 % 2 == 0){
            numar = numar+c[poz1]*9;
            cifre_arabe(x+2);
        }else if(poz1==poz2){
            int poz3;
            if(x[2] != '('){
                for(int i = 0; i <= 6; i++){
                    if(x[2] == b[i][0]){
                        poz3 = i;
                        break;
                    }
                }
                if(poz3 == poz1){
                    numar += c[poz1]*3;
                    cifre_arabe(x+3);
                }else{
                    numar += c[poz1]*2;
                    cifre_arabe(x+6);
                }
            }
        }else{
            numar += c[poz1];
            cifre_arabe(x+3);
        }
    }
}
int main()
{
    fin >> c1;
    if(c1 == 1){
        fin >> a;
        cifre_romane(a);
    }
    return 0;
}
