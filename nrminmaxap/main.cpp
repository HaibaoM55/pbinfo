#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int NrMinMaxAp(vector<int> &a){
    sort(a.begin(), a.end());
    int l = a.size();
    int nr = 1, nrmax=0,nrmaxi;
    for(int i = 1; i < l; i++){
        if(a[i] == a[i-1]){
            nr++;
            if(nr > nrmax){
                nrmax = nr;
                nrmaxi = a[i];
            }
        }else{
            nr = 1;
        }
    }
    return nrmaxi;
}/*
int main(){
    vector<int> v;
    v = {1,2,2,1,1,7,5,7,5,7,7,5,5};
    cout << NrMinMaxAp(v);
    return 0;
}*/
