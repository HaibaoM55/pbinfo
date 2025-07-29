#include <iostream>
using namespace std;
long long x;
int z=0, v[24], cif[24];
int main(){
    cin >> x;
    do{
        z++;
        v[z] = x%10;
        x = x/10;
    }while(x > 0);
    int p = 0;
    for(int i = z; i >= 1; i--){
        p++;
        cif[p] = v[i];
    }
    for(int i = 1; i <= z; i++){
        if(cif[i] % 2 == 0){
            cif[i]++;
            for(int j = i+1; j <= z; j++){
                cif[j] = 1;
            }
            break;
        }
    }
    for(int i = 1; i <= z; i++){
        cout << cif[i];
    }
    return 0;
}
