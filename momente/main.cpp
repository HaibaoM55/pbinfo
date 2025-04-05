#include <fstream>
using namespace std;
ifstream fin("momente.in");
ofstream fout("momente.out");
int n;
int s[240000];
int v[10], z=0;
int luna[15] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
    for(int h = 0; h <= 23; h++){
        for(int m = 0; m <= 59; m++){
            for(int sc = 0; sc <= 59; sc++){
                int nr = h*10000+m*100+sc;
                int cnr = nr;
                z = 0;
                do{
                    z++;
                    v[z] = cnr%10;
                    cnr = cnr/10;
                }while(cnr > 0);
                int f = z;
                int palindrom = 1;
                for(int k = 1; k <= z/2; k++){
                    if(v[k] != v[f]){
                        palindrom = 0;
                        break;
                    }
                    f--;
                }
                s[nr] = palindrom;
            }
        }
    }
    for(int i = 1; i <= 235959; i++){
        s[i] = s[i-1]+s[i];
    }
    fin>> n;
    for(int i = 1; i <= n; i++){
        int d1, l1, h1, m1, s1;
        int d2, l2, h2, m2, s2;
        int nrz = 0;
        fin >> l1 >> d1 >> h1 >> m1 >> s1 >> l2 >> d2 >> h2 >> m2 >> s2;
        int rasp = 0;
        int nr1 = h1*10000+m1*100+s1;
        int nr2 = h2*10000+m2*100+s2;
        if(l1 == l2){
            if(d1 == d2){
                rasp = s[nr2];
                if(nr1 != 0){
                    rasp -= s[nr1-1];
                }
            }else{
                rasp = s[235959]*(d2-d1-1);
                rasp += s[235959];
                if(nr1 > 0){
                    rasp -= s[nr1-1];
                }
                rasp += s[nr2];
            }
        }else{
            for(int l = l1+1; l < l2; l++){
                nrz += luna[l];
            }
            rasp = nrz*s[235959];
            rasp += s[235959]*(luna[l1]-d1);
            rasp += s[235959]*(d2-1);
            rasp += s[235959];
            if(nr1 > 0){
                rasp -= s[nr1-1];
            }
            rasp += s[nr2];
        }
        fout << rasp << '\n';
    }
    return 0;
}
