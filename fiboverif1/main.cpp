#include <fstream>
using namespace std;
ifstream fin("fiboverif1.in");
ofstream fout("fiboverif1.out");
int n,x;
int f[67];//tuff
bool fibo(int x){
    for(int i = 1; i <= 50 && f[i] <= x; i++){
        if(f[i] == x){
            return true;
        }
    }
    return false;
}
int main(){
    f[1] = 1;
    f[2] = 1;
    for(int i = 3; i <= 50; i++){
        f[i] = f[i-1]+f[i-2];
    }
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
        if(fibo(x)){
            fout << x << ' ';
        }
    }
    return 0;
}
