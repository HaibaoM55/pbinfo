#include <iostream>
#include <algorithm>
using namespace std;
int n, x;
int zp=0, zi = 0;
int p[505], im[505];
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        if(x % 2 == 0){
            zp++;
            p[zp] = x;
        }else{
            zi++;
            im[zi] = x;
        }
    }
    sort(p+1, p+zp+1);
    for(int i = 1; i <= zp; i++){
        cout << p[i] << ' ';
    }
    sort(im+1, im+zi+1);
    for(int i = 1; i <= zi; i++){
        cout << im[i] << ' ';
    }
    return 0;
}
