#include <iostream>
using namespace std;
int st, dr;
int sum_pare(int x){
    if(x == 0) return 0;
    return (x%2==0)*(x%10)+sum_pare(x/10);
}
int sum_impare(int x){
    if(x == 0) return 0;
    return (x%2==1)*(x%10)+sum_impare(x/10);
}
int suma(int st, int dr){
    if(st > dr) return 0;
    return (sum_pare(dr)==sum_impare(dr))*dr+suma(st, dr-1);
}
int main(){
    cin >> st >> dr;
    cout << suma(st, dr);
    return 0;
}
