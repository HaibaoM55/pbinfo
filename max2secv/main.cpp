#include <iostream>
using namespace std;
int n;
int s[100001];
bool doarneg = true, doarpoz = true;
int vmaxC=-101, vmaxB=-101;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if(x >= 0){
            doarneg = false;
        }else{
            doarpoz = false;
        }
        s[i] = s[i-1]+x;
        if(x > vmaxB){
            vmaxC = vmaxB;
            vmaxB = x;
        }else if(x > vmaxC){
            vmaxC = x;
        }
    }
    if(doarneg){
        cout << vmaxB+vmaxC;
        return 0;
    }else if(doarpoz){
        cout << s[n];
        return 0;
    }
    int vmax = -10000001;
    int t = 1;
    int vmaxi = 0;
    int vmaxj = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(s[j]-s[i-1] > vmax){
                vmax = s[j]-s[i-1];
                vmaxj = j;
                vmaxi = i;
            }
        }
    }
    int vmax2 = -10000001;
    for(int i = 1; i <= vmaxi-1; i++){
        for(int j = i; j <= vmaxi-1; j++){
            if(s[j]-s[i-1] > vmax2){
                vmax2 = s[j]-s[i-1];
            }
        }
    }
    for(int i = vmaxj+1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(s[j]-s[i-1] > vmax2){
                vmax2 = s[j]-s[i-1];
            }
        }
    }
    int vmin = 10000002;
    for(int i = vmaxi+1; i <= vmaxj-1; i++){
        for(int j = i; j <= vmaxj-1; j++){
            if(s[j]-s[i-1] < vmin){
                vmin = s[j]-s[i-1];
            }
        }
    }
    if(vmin > 0){
        vmin = 0;
    }
    if(vmax2 == -10000001){
        vmax2 = 0;
    }
    int r = vmax+vmax2;
    if(vmax-vmin > r){
        r = vmax-vmin;
    }
    cout << r;
    return 0;
}
