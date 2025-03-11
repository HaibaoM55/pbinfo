#include<fstream>
using namespace std;
ifstream  fin("triunghi.in");
ofstream fout("triunghi.out");
int c, n,sp[4000004];
char ciur[4000004];
int main(){
    fin>>c>>n;
    if(c==1){
        ///1=1^2,1+3=2^2, 1+3+5=3^2,
        long long s=0;
        for(int i=1;i<=n;i++){
            s=s+i*i;
        }
        fout<<s;
    }
    if(c==2){
        int i=0,s=0,t=0;
        while(s<n){
            t=s;
            i++;
            s=s+i*i;
        }
        int j=0,k=n-t,r=0;
        while(r<k){
            j++;
            r=r+2*j-1;
        }
        fout<<i<<" "<<j;
    }
    if(c==3){
        ciur[0]=1; ciur[1]=1;
        for(int i=2;i<=2000;i++){
            if(ciur[i]==0){
                for(int j=i;j<=4000000/i;j++){
                    ciur[j*i]=1;
                }
            }
        }
        sp[0]=0;
        for(int i=1;i<=4000000;i++){
            sp[i]=sp[i-1];
            if(ciur[i]==0){
                sp[i]++;
            }
        }
        long long t=0, s=0;
        for(int i=2;i<=n;i++){
            ///2*(i-1),...,2*i-1
            s=s+sp[i*i]-sp[(i-1)*(i-1)];
            t=t+s;
        }
        fout<<t;
    }
    return 0;
}
