#include <iostream>
using namespace std;
int N,R,A,B,fA[1000002],fB[1000002];
int main(){
    cin>>N>>R;
    for(int i=1;i<=N;i++){
        cin>>A;
        fA[A]++;
    }
    long long nr=0;
    for(int i=1;i<=N;i++){
        cin>>B;
        fB[B]++;
    }
    for(int i=R+1;i<=1000000;i++){
        if(fB[i]){
            for(int j=R;j<=1000000;j=j+i){
                nr=nr+(long long)fA[j]*fB[i];
            }
        }
    }
    cout<<nr;
    return 0;
}
