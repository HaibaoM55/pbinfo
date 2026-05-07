#include <iostream>
using namespace std;
int n, x;
bool esteprim(int x){
    if(x < 2){
        return false;
    }
    for(int i = 2; i*i <= x; i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        while(!esteprim(x)){
            x++;
        }
        cout << x << ' ';
    }
    return 0;
}
