#include <iostream>
using namespace std;
int n, sm;
int s[1000004];
long long nr = 0;
int main()
{
    cin >> n >> sm;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        s[i] = s[i-1]+x;
    }
    int nr = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(s[j]-s[i-1] == sm){
                nr++;
            }
        }
    }
    cout << nr;
    return 0;
}
