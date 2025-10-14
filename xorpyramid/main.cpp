#include <iostream>
using namespace std;
int n, x;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int rasp=0;
    for(int i = 1; i <= n; i++){
        cin >> x;
        if(i % 2 == n%2){
            a = a^x;
        }
    }
    cout << rasp;
    return 0;
}
