#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("halfsort1.in");
ofstream fout("halfsort1.out");
int main(){
    int n, a[54], b[54];
    fin >> n;
    for(int i = 1; i <= n/2; i++){
        fin >> a[i];
    }
    sort(a+1, a+n/2+1);
    for(int i = 1; i <= n/2; i++){
        fout << a[i] << ' ';
    }
    for(int i = 1; i <= n/2; i++){
        fin >> b[i];
    }
    sort(b+1, b+n/2+1);
    for(int i = n/2; i >= 1; i--){
        fout << b[i] << ' ';
    }
    return 0;
}
