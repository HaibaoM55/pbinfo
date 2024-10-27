#include <iostream>
using namespace std;
int n;
int x;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        long long nr = 1;
        int y = 2;
        while(x > 1){
            if(x % y == 0){
                int exp = 0;
                while(x % y == 0){
                    x = x/y;
                    exp++;
                }
                nr = nr*(2*exp+1);
            }
            y++;
            if(x > 1 && y * y > x){
                y = x;
            }
        }
        cout << nr << ' ';
    }
    return 0;
}
