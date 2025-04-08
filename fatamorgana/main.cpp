#include <iostream>
#include <algorithm>
using namespace std;
int n;
long long v[300004];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    sort(v+1, v+n+1);
    if(n % 4 == 2){
        swap(v[n], v[n/2]);
    }
    bool srt = false;
    for(int i = 1; i <= n/2; i++){
        if(v[i] == v[n/2+i]){
            srt=true;
            break;
        }
    }
    if(srt){
        sort(v+1, v+n+1);
        for(int i = 1; i <= n; i++){
            cout << v[i] << ' ';
        }
    }else{
        for(int i = 1; i <= n/2; i++){
            cout << v[i] << ' ' << v[n/2+i] << ' ';
        }
    }
    return 0;
}
