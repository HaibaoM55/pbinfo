#include <iostream>
using namespace std;
int n;
int a[100004], b[100004], c[100004];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    int p1 = 1, p2 = 1, p3 = 1;
    while(p1 <= n && p2 <= n && p3 <= n){
        int minim = min(min(a[p1], b[p2]), c[p3]);
        if(a[p1] == b[p2] && b[p2] == c[p3]){
            cout << minim;
            return 0;
        }
        if(a[p1] == minim){
            p1++;
        }else if(b[p2] == minim){
            p2++;
        }else{
            p3++;
        }
    }
    cout << -1;
    return 0;
}
