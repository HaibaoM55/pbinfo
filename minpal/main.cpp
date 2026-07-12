#include <iostream>
using namespace std;
int n;
long long v[1000004];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    int i=1, j=n;
    int nr = 0;
    while(i < j){
        if(v[i] < v[j]){
            v[i+1] = v[i]+v[i+1];
            nr++;
            i++;
        }else if(v[i] > v[j]){
            v[j-1] = v[j-1]+v[j];
            nr++;
            j--;
        }else{
            i++;
            j--;
        }
    }
    cout << nr;
    return 0;
}
