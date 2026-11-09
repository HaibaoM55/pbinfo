#include <iostream>
using namespace std;
int n, a, b, c;
int rasp = 0;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a >> b >> c;
        rasp += max(a, max(b, c));
    }
    cout << rasp;
    return 0;    
}
