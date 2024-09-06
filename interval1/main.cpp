#include <fstream>
using namespace std;
ifstream fin("interval1.in");
ofstream fout("interval1.out");
int n, k, x;
int f[2002];
int vmin = 2002;
int vmini, vminj;
int main()
{
    fin >> n >> k;
    for(int i = 1; i <= n; i++){
        fin >> x;
        f[x+1000]++;
    }
    for(int i = 0; i <= 2000; i++){
        int s = 0;
        for(int j = i; j <= 2000; j++){
            s += f[j];
            if(s >= k){
                if(j-i+1 < vmin){
                    vmini = i-1000;
                    vminj = j-1000;
                    vmin = j-i+1;
                }
            }
        }
    }
    fout << vmini <<  ' ' << vminj;
    return 0;
}
