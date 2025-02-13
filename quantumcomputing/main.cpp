#include <iostream>
using namespace std;
int c, t;
int n, k;
char x;
bool b[1000004];
int mars[1000004];
int main()
{
    cin >> c >> t;
    if(c == 1){
        for(int z1 = 1; z1 <= t; z1++){
            cin >> n;
            for(int i = 1; i <= n; i++){
                cin >> x;
                if(x == '1'){
                    b[i] = true;
                }else{
                    b[i] = false;
                }
            }
            b[n+1] = true;
            int nr = 0;
            for(int i = 1; i <= n; i++){
                if(b[i] == false && b[i+1] == true){
                    nr++;
                }
            }
            cout << nr << '\n';
        }
    }else{
        for(int z1 = 1; z1 <= t; z1++){
            cin >> n >> k;
            for(int i = 1; i <= n; i++){
                cin >> x;
                if(x == '1'){
                    b[i] = true;
                }else{
                    b[i] = false;
                }
                mars[i] = 0;
            }
            mars[0] = 0;
            int nr = 0;
            for(int i = 1; i <= n-k+1; i++){
                mars[i] = mars[i-1]+mars[i];
                if(mars[i] % 2 == 1){
                    b[i] = !b[i];
                }
                if(b[i] == false){
                    nr++;
                    mars[i]++;
                    mars[i+k]--;
                    b[i] = true;
                }
            }
            bool ok = true;
            for(int i = n-k+2; i <= n; i++){
                mars[i] = mars[i-1]+mars[i];
                if(mars[i] % 2 == 1){
                    b[i] = !b[i];
                }
                if(b[i] == false){
                    ok = false;
                    break;
                }
            }
            if(ok){
                cout << nr << '\n';
            }else{
                cout << "-1\n";
            }
        }
    }
    return 0;
}
