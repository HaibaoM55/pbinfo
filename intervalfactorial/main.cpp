#include <iostream>
using namespace std;
void interval(int n,int &a, int&b){
    a = 1;
    b = 1;
    for(int i = 1; i <= n-1; i++){
        a = a*i;
        b = b*i;
    }
    b = b*n;
    b = b*(n+1);
    a++;
    b--;
}/*
int main(){
    int a,b;
    interval(3, a, b);
    cout << a << ' '<< b;
    return 0;
}
*/
