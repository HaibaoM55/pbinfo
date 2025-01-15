#include <iostream>
using namespace std;
int n;
int main()
{
    cin >> n;
    if(n == 2){
        cout << 89;
    }else if(n == 3){
        cout << 899;
    }else{
        if(n % 2 == 0){
            int nr = (n-1)/2;
            for(int i = 1; i <= nr; i++){
                cout << 9;
            }
            cout << 8;
            for(int i = nr+1; i <= n-1; i++){
                cout << 9;
            }
        }else{
            int nr = (n-1)/2;
            for(int i = 1; i <= nr-1; i++){
                cout << 9;
            }
            cout << 8;
            for(int i = 1; i <= nr+1; i++){
                cout << 9;
            }
        }
    }
    return 0;
}
