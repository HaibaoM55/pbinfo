#include <fstream>
using namespace std;
ifstream fin("summat.in");
ofstream fout("summat.out");
long long n,m,q;
pair<long long,long long> get_pos(long long i, long long j, long long x){
    j+=x;
    i+=(j-1)/m;
    j%=m;
    if (j==0) j=m;
    return {i,j};
}
int main(){
    fin >>n>>m>>q;
    for(long long i=1;i<=q;i++){
        long long l1,l2,c1,c2;
        fin >>l1>>c1>>l2>>c2;
        long long s=0;
        for(long long nr=1; nr <= 54; nr++){
            pair <long long,long long> x=get_pos (1,0,(1LL<<(nr-1)));
            pair <long long,long long> y=get_pos (1,0,(1LL<<nr)-1);
            if(x>make_pair (l2,c2)){
                break;
            }
            if(y<make_pair (l1,c1)){
                continue;
            }
            if(x.first==y.first){
                if(x.second > c2 || y.second <c1){
                    continue;
                }
                s+=(min (y.second,c2)-max(x.second,c1)+1)*nr;
                continue;
            }
            long long f1,l3=0;
            if(x.first<l1){
                x={l1,0};
            }
            if(y.first>l2){
                y={l2,m};
            }
            if(x.second<=c1){
                f1=x.first;
            }else{
                if(x.second<=c2){
                    s+=(c2-x.second+1)*nr;
                }
                f1=x.first+1;
            }
            if(y.second>c2){
                l3=y.first;
            }else{
                if(y.second>=c1){
                    s+=(y.second-c1+1)*nr;
                }
                l3=y.first-1;
            }
            s+=(c2-c1+1)*(l3-f1+1)*nr;
        }
        fout <<s<<'\n';
    }
    return 0;
}
