#include <iostream>
using namespace std;
int n;
int main()
{
    cin >> n;
    for(int i = 1; i <= n-1; i++){
        int k = 2*i-1;
        for(int j = 1; j <= (2*n-1-k)/2; j++){
            cout <<'#';
        }
        for(int j = 1; j <= k; j++){
            cout <<'*';
        }
        for(int j = 1; j <= (2*n-1-k)/2; j++){
            cout<<'#';
        }
        cout << '\n';
    }
    for(int i = 1; i <= 2*n-1; i++){
        cout << '*';
    }
    cout << '\n';
    for(int i = n-1; i >= 1; i--){
        int k = 2*i-1;
        for(int j = 1; j <= (2*n-1-k)/2; j++){
            cout <<'#';
        }
        for(int j = 1; j <= k; j++){
            cout <<'*';
        }
        for(int j = 1; j <= (2*n-1-k)/2; j++){
            cout<<'#';
        }
        cout << '\n';
    }
    return 0;
}
