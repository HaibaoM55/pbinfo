#include <iostream>
#include <string.h>
using namespace std;
char s[104], rasp[104];
char cif;
int v[104];
int main(){
    cin >> s;
    int l = strlen(s);
    for(int i = 0; i < l; i++){
        if(!(cin >> cif)){
            cout << "cod incorect";
            return 0;
        }
        v[i] = cif-'0';
    }
    if(cin >> cif){
        cout << "cod incorect";
        return 0;
    }
    rasp[l] = 0;
    int p1 = 0, p2 = l-1;
    for(int i = l-1; i >= 0; i--){
        if(v[i] % 2 == 0){
            rasp[i] = s[p1];
            p1++;
        }else{
            rasp[i] = s[p2];
            p2--;
        }
    }
    cout << rasp;
    return 0;
}
