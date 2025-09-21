#include <iostream>
using namespace std;
int CautaKth(int a[], int n, int k) {
    int nrk = 0;
    for (int i = 0; i < n; i++) {
        if(i == 0){
            if(a[i] - 1 >= k){
                return k;
            }else{
                nrk += a[i]-1;
            }
        }else{
            int lipsa = a[i]-a[i-1]-1;
            if(nrk + lipsa >= k){
                return a[i-1]+k-nrk;
            }
            nrk += lipsa;
        }
    }
    return a[n-1]+k-nrk;
}
/*
int main(){
    int obamahavdih[67] = {2,3,4,5,6,7};
    cout << CautaKth(obamahavdih, 6, 2);
    return 0;
}
*/
