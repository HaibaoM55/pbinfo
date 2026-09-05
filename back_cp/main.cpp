#include <iostream>
using namespace std;
int n, m;
char s[27];
void kp(int k, int c, int p){
    if(c){
        s[k] = 'C';
        kp(k+1, c-1, p);
    }
    if(p){
        s[k] = 'P';
        kp(k+1, c, p-1);
    }
    if(c == 0 && p == 0){
        bool ok = true;
        for(int i = 1; i < k-1; i++){
            if(s[i] == 'P' && s[i-1] == 'C' && s[i+1] == 'C'){
                ok = false;
                break;
            }
        }
        if(ok){
            cout << s << '\n';
        }
    }
}
int main(){
    cin >> n >> m;
    kp(0, n, m);
    return 0;
}
