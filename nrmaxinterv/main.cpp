#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("nrmaxinterv.in");
ofstream fout("nrmaxinterv.out");
int n;
int x[100004], y[100004];
int nr = 1, nrmax = 0;
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x[i] >> y[i];
    }
    sort(x+1, x+n+1);
    sort(y+1, y+n+1);
    int i = 2;
    int j = 1;
    while (i <= n && j <= n) {
        if(x[i] <= y[j]){
            nr++;
            nrmax = max(nr, nrmax);
            i++;
        }else{
            nr--;
            j++;
        }
    }
    fout << nrmax;
    return 0;
}
