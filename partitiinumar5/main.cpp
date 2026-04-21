#include <iostream>
#include <vector>
using namespace std;
int n;
bool exista = false;
void kp(int x, vector<int> v, int vmax){
    if(x == 0){
        for(int i = 1; i <= v[0]; i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        exista = true;
    }else{
        v[0]++;
        for(int i = vmax; i <= x; i++){
            if(i % 2 == 0){
                v[v[0]] = i;
                kp(x-i, v, i);
            }
        }
    }
}
vector<int> clearv(67);
int main(){
    cin >> n;
    kp(n, clearv, 1);
    if(!exista){
        cout << "imposibil";
    }
    return 0;
}
