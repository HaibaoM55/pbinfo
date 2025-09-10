#include <iostream>
#include <string.h>
#include <unordered_map>
using namespace std;
long long SecvBiti(char s[]){
    int f[1000004];
    unordered_map<int, int> fv;
    int l = strlen(s);
    long long numar = 0;
    f[0] = 1;
    fv[1]++;
    for(int i = 1; i <= l; i++){
        f[i] = f[i-1];
        if(s[i-1] == '0'){
            f[i]--;
        }else{
            f[i]++;
        }
        fv[f[i]]++;
        numar += fv[f[i]]-1;
    }

    return numar;
}/*
int main(){
    cout << SecvBiti("1001");
    return 0;
}*/
