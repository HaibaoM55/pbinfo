#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("halfsort.in");
ofstream fout("halfsort.out");
int n;
int a[54], b[54];
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        if(i <= n/2){
            fin >> a[i];
        }else{
            fin >> b[i-(n/2)];
        }
    }
    sort(a+1, a+n/2+1);
    for(int i = 1; i <= n/2; i++){
        fout << a[i] << ' ';
    }
    sort(b+1, b+n/2+1);
    for(int i = n/2; i >= 1; i--){
        fout << b[i] << ' ';
    }
    return 0;
}
