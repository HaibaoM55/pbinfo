#include <fstream>
using namespace std;
ifstream fin("sumperm.in");
ofstream fout("sumperm.out");
int n, x;
int p = 1;
long long s = 0;
int main(){
    fin >> n;
    for(int i = 2; i <= n; i++){
        p = p*10+1;
    }
    for(int i = 1; i <= n; i++){
        fin >> x;
        s = s + (x*p);
    }
    fout << s;
    return 0;
}
