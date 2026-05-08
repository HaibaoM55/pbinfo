#include <iostream>
#include <string>
using namespace std;
string b16;
int b10(char x){
    if('0' <= x && x <= '9'){
        return x-'0';
    }else{
        return (x-'A')+10;
    }
}
long long tob10(string x, long long p){
    if(x.empty()){
        return 0;
    }
    long long r = 1LL*p*b10(x[x.size()-1]);
    x.pop_back();
    return r+tob10(x, p*16);
}
int main(){
    cin >> b16;
    cout << tob10(b16, 1);
    return 0;
}
