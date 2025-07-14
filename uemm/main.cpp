#include <iostream>
using namespace std;
int n;
int v[1004];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    for(int i = 1; i <= n; i++){
        int nr = -1;
        for(int j = i+1; j <= n; j++){
            if(v[j] > v[i]){
                nr = v[j];
                break;
            }
        }
        cout << nr << ' ';
    }
    return 0;
}
