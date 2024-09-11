#include <iostream>
using namespace std;
int n, m, p;
int x[16], f[16];
void bk(int k, int vm){
    if(k == n+1){
        for(int i = 1; i <= p; i++){
            cout << '{';
            int c = 0;
            for(int j = 1; j <= n; j++){
                if(x[j] == i){
                    c++;
                    if(c == 1){
                        cout << j;
                    }else{
                        cout << "," << j;
                    }
                }
            }
            cout << '}';
            if(i < p){
                cout << 'U';
            }
        }
        cout << '\n';
    }else{
        int vmax = vm+1;
        if(vmax > p){
            vmax = p;
        }
        for(int i = 1; i <= vmax ; i++){
            if(f[i] < m){
                x[k] = i;
                f[i]++;
                int z = max(vm, i);
                bk(k+1, z);
                f[i]--;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    if(n % m != 0){
        cout << "IMPOSIBIL";
    }else{
        p = n/m;
        x[1] = 1;
        f[1] = 1;
        bk(2, 1);
    }
    return 0;
}
