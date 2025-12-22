#include <iostream>
#include <string.h>
using namespace std;
char x[100004], v[100000];
int main(){
    cin.get(x, 100004);
    int l = strlen(x);
    int inceput = 0, sfarsit = 0;
    int l1 = 0;
    bool ok = true;
    while(ok){
        ok = false;
        l1 = 0;
        for(int i = 0; i < l; i++){
            if('0' <= x[i] && x[i] <= '9'){
                int nr = 0;
                while('0' <= x[i] && x[i] <= '9'){
                    nr = nr*10+(x[i]-'0');
                    i++;
                }
                if(x[i] == '['){
                    ok = true;
                    int jm = 1;
                    i++;
                    inceput = i;
                    while(jm != 0){
                        if(x[i] == '['){
                            jm++;
                        }
                        if(x[i] == ']'){
                            jm--;
                        }
                        i++;
                    }
                    i--;
                    sfarsit = i-1;
                    for(int z = 1; z <= nr; z++){
                        for(int j = inceput; j <= sfarsit; j++){
                            v[l1] = x[j];
                            l1++;
                        }
                    }
                }
            }else{
                v[l1] = x[i];
                l1++;
            }
        }
        v[l1] = 0;
        l = l1;
        strcpy(x, v);
    }
    cout << x;
    return 0;
}
