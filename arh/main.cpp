#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("arh.in");
ofstream fout("arh.out");
char s[1000004];
char r[1000004];
char og[100004];
int l;
int z = 0;
void clearr(){
    for(int i = 0; i < z; i++){
        r[z] = 0;
    }
}
int main(){
    fin.get(s, 100004);
    strcpy(og, s);
    l = strlen(s);
    bool ok = true;
    while(ok){
        ok = false;
        int nr = 0;
        z = 0;
        for(int i = 0; i < l; i++){
            if(s[i] == '('){
                int j = i-1;
                while('0' <= s[j] && s[j] <= '9'){
                    j--;
                    z--;
                }
                j++;
                nr = 0;
                while('0' <= s[j] && s[j] <= '9'){
                    nr = nr*10+s[j]-'0';
                    j++;
                }
                ok = true;
                int nr1 = 1;
                j = i+1;
                while(true){
                    if(s[j] == '('){
                        nr1++;
                    }else if(s[j] == ')'){
                        nr1--;
                        if(nr1 == 0){
                            break;
                        }
                    }
                    j++;
                }
                int i1 = i+1;
                int j1 = j-1;
                while(nr){
                    for(int k = i1; k <= j1; k++){
                        r[z] = s[k];
                        z++;
                    }
                    nr--;
                }
                i = j;
            }else{
                r[z] = s[i];
                z++;
                nr = 0;
            }
        }
        l = z;
        strcpy(s, r);
        //clearr();
    }
    ok = true;
    while(ok){
        ok = false;
        z = 0;
        for(int i = 0; i < l; i++){
            if(s[i] == '[' && s[i+1] == '*'){
                i = i+2;
                int nr1 = 1;
                int j = i;
                while(true){
                    if(s[j] == '['){
                        nr1++;
                    }else if(s[j] == ']'){
                        nr1--;
                        if(nr1 == 0){
                            break;
                        }
                    }
                    j++;
                }
                for(int k = i; k <= j-1; k++){
                    r[z] = s[k];
                    z++;
                }
                for(int k = j-1; k >= i; k--){
                    r[z] = s[k];
                    z++;
                }
                i = j;
            }else{
                r[z] = s[i];
                z++;
            }
        }
        l = z;
        strcpy(s, r);
        //clearr();
    }
    ok = true;
    while(ok){
        ok = false;
        z = 0;
        for(int i = 0; i < l; i++){
            if(s[i] == '['){
                i = i+1;
                int nr1 = 1;
                int j = i;
                while(true){
                    if(s[j] == '['){
                        nr1++;
                    }else if(s[j] == ']'){
                        nr1--;
                        if(nr1 == 0){
                            break;
                        }
                    }
                    j++;
                }
                j--;
                for(int k = i; k <= j-1; k++){
                    r[z] = s[k];
                    z++;
                }
                for(int k = j-2; k >= i; k--){
                    r[z] = s[k];
                    z++;
                }
                i = j+1;
            }else{
                r[z] = s[i];
                z++;
            }
        }
        l = z;
        strcpy(s, r);
        //clearr();
    }
    fout << 67 << '\n';
    for(int i = 0; i < l; i++){
        fout << s[i];
    }
    return 0;
}
