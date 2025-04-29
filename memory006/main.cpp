#include<fstream>
using namespace std;
ifstream fin ("memory006.in");
ofstream fout("memory006.out");
char v[10104];
int n,k,ul,pr,i,c,s,r,nrt;
long long x;

int main(){
    fin>>n>>k;
    r=10100;
    pr=1; ul=0; nrt=0; s=0;
    for(i=1;i<=n;i++){
        fin>>x;
        c=0;while(x%2==0){c++;x=x/2;}
        if(x==1){
            ul++; if(ul>r){ul=1;}
            v[ul]=c;
            s=s+c;
            while(s>k){
                s=s-v[pr];
                pr++; if(pr>r){pr=1;}
            }
            if(s==k){
                nrt=nrt+1;
            }
        }
        else{
            pr=1; ul=0; s=0;
        }
    }
    fout<<nrt<<"\n";
    fout.close();
    fin.close();
    return 0;
}

