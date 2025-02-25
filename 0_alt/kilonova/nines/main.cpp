#include <iostream>
using namespace std;
int t;
int n, k;
int x[1000004];
int main()
{
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> n >> k;
        x[0] = n;
        for(int j = 1; j <= n; j++){
            char cif;
            cin >> cif;
            x[n-j+1] = cif-'0';
        }
        int nr9 = x[0];
        if(x[n] == 1){
            x[0]--;
            for(int j = 1; j <= x[0]; j++){
                x[j] = 9;
            }
        }else{
            for(int j = x[0]; j > 1; j--){
                if(x[j] < 9){
                    x[j]--;
                    for(int k1 = j-1; k1 >= 1; k1--){
                        x[k1] = 9;
                    }
                    break;
                }
            }
        }
        x[n-k]++;
        x[0] = max(x[0], n-k);
        int p = n-k;
        while(x[p] > 9){
            x[0] = max(x[0], p+1);
            x[p+1]++;
            x[p] = x[p]%10;
            p++;
        }
        cout << "IMP";
        for(int j = x[0]; j >= 1; j--){
            cout << x[j];
        }
        cout <<"IMP";
        cout <<'\n';
    }
    return 0;
}
