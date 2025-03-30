#include <fstream>
using namespace std;
ifstream fin("castele.in");
ofstream fout("castele.out");
int n,x, f[100002];
int modul(int x){
    if(x < 0){
        return -x;
    }
    return x;
}
int main()
{
    fin >> n;
    for(int i= 1; i <= n; i++){
        fin >> x;
        f[x]++;
    }
    long long nr = 100000000;
    for(int i = 1; i <= 1000; i++){
        long long r = 0;
        for(int j = 1; j <= 1000; j++){
            r += modul(i-j)*f[j];
        }
        nr = min(r, nr);
    }
    fout << nr;
    return 0;
}
