#include <iostream>
using namespace std;
int elimcif(int n, int c){
    int nr = 0;
    do{
        if(n%10 != c){
         	nr = nr*10+n%10;
        }
        n = n/10;
    }while(n > 0);
    int nrcorect= 0;
    do{
        nrcorect = nrcorect*10+nr%10;
        nr = nr/10;
    }while(nr > 0);
    return nrcorect;
}/*
int main()
{
    cout << elimcif(2454, 4);
    return 0;
}*/
