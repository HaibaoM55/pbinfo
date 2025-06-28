#include <iostream>
#include <algorithm>
using namespace std;
int n;
int v[20],a[20];
int main(){
    cin >> n;
    long long s =0;
    for(int i = 1; i <= n; i++){
        a[i] = i;
        cin >> v[i];
        s = s + v[i];
    }
    long long mindif=s;
    do{
        long long s1 =0;
        for(int i = 1; i <= n; i++){
            if(s1+v[a[i]] > s/2){
                break;
            }else{
                s1 = s1+v[a[i]];
            }
        }
        mindif = min(mindif, s-2*s1);
    }while(next_permutation(a+1, a+n+1));
    cout << mindif;
    return 0;
}
