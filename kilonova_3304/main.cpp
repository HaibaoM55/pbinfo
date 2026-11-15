#include <iostream>
#include <algorithm>
using namespace std;
int t, n;
char x[300004];
int v[300004];
int main(){
    cin >> t;
    while(t){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> x[i];
        }
        x[n+1] = '_';
        v[0] = 0;
        for(int i = 1; i <= n; i++){
            if(x[i] == '.'){
                v[0]++;
                v[v[0]] = 0;
                while(x[i] == '.'){
                    v[v[0]]++;
                    i++;
                }
                v[v[0]] = v[v[0]]/2+1;
                i--;
            }
        }
        sort(v+1, v+v[0]+1);
        int rasp = 0;
        for(int i = v[0]; i >= 1; i--){
            rasp = max(rasp, v[0]+v[i]-i);
        }
        cout << v[0] << ' ' << rasp << '\n';
        t--;
    }
    return 0;
}
