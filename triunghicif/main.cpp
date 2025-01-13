#include <iostream>
using namespace std;
int l, c;
int main()
{
    cin >> l >> c;
    int x = 1;
    for(int i = 1; i <= l-1; i++){
        int j = i;
        while(j > 9){
            x++;
            if(x == 10){
                x = 1;
            }
            j -= 10;
        }
        x = x+j;
        if(x >= 10){
            x = x - 9;
        }
    }
    for(int i = 1;  i <= c-1; i++){
        x++;
        if(x == 10){
            x = 1;
        }
    }
    cout << x;
    return 0;
}
