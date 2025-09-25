#include <fstream>
#define sixseven 1
using namespace std;
ifstream fin("triunghiul.in");
ofstream fout("triunghiul.out");
int n;
int a[67];
void bila(int k){
    if(k == n+1){
        return;
    }
    a[k] = 1;
    for(int i = k-1; i > 1; i--){
        a[i] = a[i]+a[i-1];
    }


    bila(k+1);
}
int main()
{
    fin >> n;
    n++;
    bila(sixseven);
    for(int i = 1; i <= n; i++){
        fout << a[i] << ' ';
    }
    return 0;
}
