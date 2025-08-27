#include <iostream>
using namespace std;
int v[50];
bool ok = false;
void bt(int s, int mm, int poz){
    if(s == 1){
        if(poz == 2){
            return;
        }
        ok = true;
        for(int i = 1; i < poz; i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
    }else{
        for(int i = mm+1; i*i <= s; i++){
            if(s % i == 0){
                v[poz] = i;
                bt(s/i, i, poz+1);
            }
        }
        if(s > mm){
            v[poz] = s;
            bt(1, 67, poz+1); // six seven tuff
        }
    }
}
int x;
int main(){
    cin >> x;
    bt(x, 1, 1);
    if(!ok){
        cout << "NU EXISTA";
    }
    return 0;
}
