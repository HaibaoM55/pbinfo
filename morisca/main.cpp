#include <iostream>
using namespace std;
int n;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j=1; j <= i; j++){
            cout << '*';
        }
        for(int j=1; j<=3*n-2*i; j++){
            cout << ' ';
        }
        for(int j=1; j <= i; j++){
            cout << '*';
        }
        cout << '\n';
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << ' ';
        }
        for(int j = 1; j <= n; j++){
            cout <<'*';
        }
        cout << '\n';
    }
    for(int i = n; i >= 1; i--){
        for(int j=1; j <= i; j++){
            cout << '*';
        }
        for(int j=1; j<=3*n-2*i; j++){
            cout << ' ';
        }
        for(int j=1; j <= i; j++){
            cout << '*';
        }
        cout << '\n';
    }
    return 0;
}
