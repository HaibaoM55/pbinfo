#include <fstream>
using namespace std;
ifstream fin("potcoave.in");
ofstream fout("potcoave.out");
long long n, m;
long long p[10004], k[10004];
long long nrz = 0;
bool verif(long long nr){
    long long total = 0;
    for(int i = 1; i <= n; i++){
        total += nr*p[i];
        total -= (nr/k[i])*p[i];
    }
    return total >= m;
}
int main(){
    fin >> m;
    fin >> n;
    long long tungtungtung=0;
    for(int i = 1; i <= n; i++){
        fin >> p[i] >> k[i];
        tungtungtung += p[i];
    }
    nrz = 1;
    long long p1 = 1, p2 = 2*m/tungtungtung;
    while(p1 <= p2){
        long long mij = (p1+p2);
        mij = mij/2;
        if(verif(mij)){
            p2 = mij-1;
            nrz = mij;
        }else{
            p1 = mij+1;
        }
    }
    fout << nrz;
    return 0;
}
