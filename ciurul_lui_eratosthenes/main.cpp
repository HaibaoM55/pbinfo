#include <iostream>
using namespace std;
bool ciur[1000004];
int n;
int main(){
    cin >> n;
    for(int i=2;i<=n;i++){
        if(ciur[i]==false){
            cout<<i<<" ";
            for(int j=i;j<=n/i;j++){
               ciur[j*i]=true;
            }
        }
    }
    return 0;
}