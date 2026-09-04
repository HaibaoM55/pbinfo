#include <iostream>
using namespace std;
int n;
int v[204];
bool ok = false;
bool esteprim(int k){
    if(k < 2){
        return false;
    }
    for(int i = 2; i*i <= k; i++){
        if(k % i == 0){
            return false;
        }
    }
    return true;
}
void kp(int vmax, int s){
    if(s == 0){
        ok = true;
        for(int i = 1; i <= v[0]; i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }else{
        for(int i = vmax+1; i <= s; i++){
            if(esteprim(i)){
                v[0]++;
                v[v[0]] = i;
                kp(i, s-i);
                v[0]--;
            }
        }
    }
}
int main(){
    cin >> n;
    kp(1, n);
    if(!ok){
        cout << "nu exista";
    }
    return 0;
}
