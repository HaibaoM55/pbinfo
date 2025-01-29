#include <fstream>
using namespace std;
ifstream fin("sirdivk.in");
ofstream fout("sirdivk.out");
int a, b, c, n, k;
int r = 0;
int nr = 0;
int main()
{
    fin >> a >> b >> c >> n >> k;
    for(int i = 1; i <= n; i++){
        r = r*10;
        if(i % 3 == 1){
            r = r+a;
        }else if(i % 3 == 2){
            r = r+b;
        }else{
            r = r+c;
        }
        r = r%k;
        if(r == 0){
            nr++;
        }
    }
    fout << nr;
    return 0;
}
