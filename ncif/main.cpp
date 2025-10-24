#include <fstream>
#include <math.h>
using namespace std;
ifstream fin("ncif.in");
ofstream fout("ncif.out");
int n, a, b;
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> a >> b;
        double rasp = log10(a)*b+1;
        fout << (int)rasp << '\n';
    }
    return 0;
}
