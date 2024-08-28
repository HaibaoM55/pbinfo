#include <fstream>
using namespace std;
ifstream fin("secvcresc.in");
ofstream fout("secvcresc.out");
int n;
int v[10001];
int vmax = 0;
int st, dr;
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    for(int i = 1; i <= n; i++){
        int vj=i;
        for(int j = i+1; j <= n; j++){
            if(v[j-1] >= v[j]){
                vj = j-1;
                break;
            }else{
                vj = j;
            }
        }
        if(vj-i+1 > vmax){
            vmax = vj-i+1;
            st = i;
            dr = vj;
        }
    }
    fout << st << ' ' << dr;
    return 0;
}
