#include <fstream>
using namespace std;
ifstream fin("secventa.in");
ofstream fout("secventa.out");
int n, vmax = 0;
int v[100004];
int p, u;
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    for(int i = 1; i <= n; i++){
        int vj = i;
        long long s = v[i];
        for(int j = i+1; j <= n; j++){
            if((v[j-1]%2) == (v[j]%2)){
                vj = j-1;
                break;
            }else{
                s += v[j];
                vj = j;
            }
        }
        if(s >= vmax){
            vmax = s;
            p = i;
            u = vj;
        }
    }
    fout << p << ' ' << u;
    return 0;
}
