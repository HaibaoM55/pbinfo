#include <iostream>
using namespace std;
int n;
int vmax=0, vmin=1000000;
int apmax=1, apmin=1;
long long s = 0;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        s = s+x;
        if(x > vmax){
            vmax = x;
            apmax = 1;
        }else if(x == vmax){
            apmax++;
        }
        if(x < vmin){
            vmin = x;
            apmin = 1;
        }else if(x == vmin){
            apmin++;
        }
    }
    s = s - vmax*apmax - vmin*apmin;
    cout << s;
    return 0;
}
