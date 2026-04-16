#include <fstream>
using namespace std;
#define int long long
ifstream fin("collatz.in");
ofstream fout("collatz.out");
int t;
int kp(int x){
    if(x == 1){
        return 0;
    }
    if(x % 2 == 0){
        return kp(x/2)+1;
    }else{
        return kp(x*2+2)+1;
    }
}
long long r(int x){
    if(x <= 1){
        return 0;
    }
    if(x % 2 == 1){
        return kp(x)+r(x-1);
    }else{
        return 2*r(x/2)+2*x-3;
    }
}
signed main(){
    fin >> t;
    for(int i = 1; i <= t; i++){
        int st, dr;
        fin >> st >> dr;
        fout << r(dr)-r(st-1) << '\n';
    }
    return 0;
}
