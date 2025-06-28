///sunt parcurse toate submultimile, se porneste de la submultimea vida cu suma 0
///in a[] se pastreaza sumele tuturor submultimilor, cel mult 2^20
///aceasta forma de parcurgere poate fi utilizata si pentru tehnica PINEX (principiul includeri/excluderii)
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int v[22],na;
long long a[2000002],s,s1;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        s = s + v[i];
    }
    na=0;
    a[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=na;j>=0;j--){
            a[++na]=a[j]+v[i];
            if(a[na]<=s/2 && a[na]>s1){
                s1=a[na];
            }
        }
    }
    cout << s-s1-s1;
    return 0;
}
