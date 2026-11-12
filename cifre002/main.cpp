#include <iostream>
#include <algorithm>
using namespace std;
int n;
int v[14];
int main(){
    cin >> n;
    do{
        v[0]++;
        v[v[0]] = n%10;
        n = n/10;
    }while(n);
    sort(v+1, v+v[0]+1);
    int nr = 0;
    do{
        if(v[1] > 0 && v[v[0]]%2==0){
            nr++;
        }
    }while(next_permutation(v+1, v+v[0]+1));
    cout << nr;
    return 0;
}
