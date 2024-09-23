#include <fstream>
using namespace std;
ifstream fin("secvpal.in");
ofstream fout("secvpal.out");
int n;
int v[1004];
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    int vmax = 1, vmaxi, vmaxj;
    for(int i = 1; i <= n-vmax; i++){
        for(int j = i+vmax; j <= n; j++){
            int dr = j;
            bool ok = true;
            for(int x = i; x <= j; x++){
                if(v[x] != v[dr]){
                    ok = false;
                    break;
                }
                dr--;
            }
            if(ok){
                vmax = j-i+1;
                vmaxi = i;
                vmaxj = j;
            }
        }
    }
    fout << vmaxi << ' ' << vmaxj;
    return 0;
}
