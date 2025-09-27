#include <iostream>
#include <algorithm>
using namespace std;
int n;
int v[1004];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        int x = v[i], nrc = 0;
        do{
            nrc++;
            x = x/10;
        }while(x > 0);
        if(nrc % 2 == 0){
            int s = 0;
            for(int d = 1; d*d <= v[i]; d++){
                if(v[i] % d == 0){
                    s += d;
                    if(d*d < v[i]){
                        s += v[i]/d;
                    }
                }
            }
            v[i] = s;
        }else{
            int s = 0;
            for(int d = 2; d*d <= v[i]; d++){
                if(v[i] % d == 0){
                    s += d;
                    while(v[i] % d == 0){
                        v[i] = v[i]/d;
                    }
                }
            }
            if(v[i] > 1){
                s += v[i];
            }
            v[i] = s;
        }
    }
    sort(v+1, v+n+1);
    for(int i = 1; i <= n; i++){
        cout << v[i] << ' ';
    }
    return 0;
}
