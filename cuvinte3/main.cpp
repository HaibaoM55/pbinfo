#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("cuvinte3.in");
ofstream fout("cuvinte3.out");
int n=0,z=0;
char c[265],k[265];
char x[104][265];
bool estesimbol(char p){
    if(p == 0 || p == '.' || p == ',' || p == ';' || p == ':' || p == '-' || p == '?' || p == '!' || p == ' '){
        return true;
    }
    return false;
}
bool exista_ate(char o[265]){
    int l = strlen(o);
    for(int i = 0; i < l-2; i++){
        if(tolower(o[i]) == 'a' && tolower(o[i+1]) == 't' && tolower(o[i+2]) == 'e'){
            return true;
        }
    }
    return false;
}
int main(){
    while(fin.get(c, 260)){
        fin.get();
        int l = strlen(c);
        for(int i = 0; i <= l; i++){
            if(estesimbol(c[i])){
                k[z] = 0;
                if(z >= 3 && exista_ate(k)){
                    bool exista = false;
                    for(int j = 1; j <= n; j++){
                        bool ok = true;
                        int l1 = strlen(x[j]);
                        if(z == l1){
                            for(int o = 0; o < z; o++){
                                if(tolower(k[o]) != tolower(x[j][o])){
                                    ok = false;
                                    break;
                                }
                            }
                            if(ok){
                                exista = true;
                                break;
                            }
                        }
                    }
                    if(!exista){
                        n++;
                        strcpy(x[n], k);
                    }
                }
                z = 0;
            }else{
                k[z] = c[i];
                z++;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        fout << x[i] << '\n';
    }
    return 0;
}
