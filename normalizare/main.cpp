#include <iostream>
#include <algorithm>
using namespace std;
int n;
struct pv{
    int val, poz;
}a[100004];
int b[100004];
bool compara(pv a, pv b){
    return a.val < b.val;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].val;
        a[i].poz = i;
    }
    sort(a+1, a+n+1, compara);
    int nr = 0;
    for(int i = 1; i <= n; i++){
        //cout << a[i].val << ' ';
        int k = a[i].val;
        nr++;
        while(a[i].val == k){
            b[a[i].poz] = nr;
            i++;
        }
        i--;
    }
    for(int i = 1; i <= n; i++){
        cout << b[i] << ' ';
    }
    return 0;
}
