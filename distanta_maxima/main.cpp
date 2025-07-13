#include <fstream>
using namespace std;
ifstream fin("distanta.in");
ofstream fout("distanta.out");
int n, x, vmax = 0;
int f[1004];
int main()
{
    int i = 1;
    while(fin >> x){
        if(f[x] == 0){
            f[x] = i;
        }
        vmax = max(i-f[x], vmax);
        i++;
    }
    fout << vmax;
    return 0;
}
