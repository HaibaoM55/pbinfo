#include <iostream>
using namespace std;
int det(int n){
    int p = 1;
    int difmin=2e9, difmini;
    for(int i = 1; i <= 12; i++){
        p = p*i;
        if(abs(p-n) < difmin){
            difmin = abs(p-n);
            difmini = p;
        }
    }
    return difmini;
}/*
int main()
{
    cout << det(100);
    return 0;
}*/
