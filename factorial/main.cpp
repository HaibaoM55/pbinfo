#include <iostream>
using namespace std;
long long n,p=1;
int main(){
cin>>n;
    for(int i=1; i<=n;i++){
    p=p*i;
}
    cout<<p;
    return 0;
}
