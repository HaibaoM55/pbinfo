#include<fstream>
using namespace std;
ifstream  cin("placare1.in");
ofstream cout("placare1.out");
long long L,A,B,r,x,hA,hB;
int main(){
    cin>>L>>A>>B;
    hA=0;
    r=0;///rest imaginar ramas de la ultimul rand (imaginar)
    do{
        hA=hA+A;
        x=(L-r)%B;///trebuie taiat x din B
        if(x==0){
            r=0;
        }else{
            r=B-x;///pentru urmatorul rand restul ramas
        }
    }
    while(r!=0);
    hB=0;
    r=0;///rest imaginar ramas de la ultimul rand (imaginar)
    do{
        hB=hB+B;
        x=(L-r)%A;///trebuie taiat x din A
        if(x==0){
            r=0;
        }else{
            r=A-x;///pentru urmatorul rand restul ramas
        }
    }
    while(r!=0);
    if(hA>hB){
        cout<<hA;
    }else{
        cout<<hB;
    }
    return 0;
}
