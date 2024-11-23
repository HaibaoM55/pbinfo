#include <iostream>
using namespace std;
int n, m;
int main()
{
    cin >> n >> m;
    if(n > 1){
        cout << "__";
        for(int i = 1; i <= m-1; i++){
            cout <<"0_0";
            cout<<"_____";
        }
        cout<<"0_0___\n";
        for(int i = 1; i <= n-2; i++){
            cout << '_';
            for(int j = 1; j <= 2*m-1; j++){
                cout<<"0___";
            }
            cout<<"0__";
            cout << '\n';
        }
        for(int i = 1; i <= m; i++){
            cout << "0_____0_";
        }
    }else{
        cout << "__";
        for(int i = 1; i <= m-1; i++){
            cout <<"0_0";
            cout<<"_____";
        }
        cout<<"0_0___\n";
    }
    return 0;
}
