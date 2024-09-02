#include <iostream>
using namespace std;
int n;
int vx = -1;
int x;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        if(x % 2 == 0){
            if(vx != -1 && x <= vx){
                cout << "NU";
                return 0;
            }
            vx = x;
        }
    }
    cout << "DA";
    return 0;
}
