#include <fstream>
using namespace std;
ifstream fin("eratostene0.in");
ofstream fout("eratostene0.out");
int n, jeni, fici;
long long s[1000004];
int main(){
    for(int i = 1; i <= 1000000; i++){
        for(int j = 1; j <= 1000000/i; j++){
            s[i*j] += i;
        }
    }
    s[0] = 0;
    for(int i = 1; i <= 1000000; i++){
        s[i] = s[i-1]+s[i];
    }
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> jeni >> fici;
        fout << s[fici]-s[jeni-1] << '\n';
    }
    return 0;
}
