#include <iostream>
using namespace std;
int n;
int ciur[100003];
int vmax = 1, vmaxi = 1;
int main()
{
    cin >> n;
    for(int i = 2; i <= n; i++){
        for(int j = i; j <= n; j += i){
            ciur[j]++;
            if(ciur[j] > vmax){
                vmax = ciur[j];
                vmaxi = j;
            }else if(ciur[j] == vmax){
                if(j < vmaxi){
                    vmaxi = j;
                }
            }
        }
    }
    cout << vmaxi;
    return 0;
}
