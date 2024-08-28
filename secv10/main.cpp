#include <fstream>
using namespace std;
ifstream fin("secv10.in");
ofstream fout("secv10.out");
int n;
int v[10004];
int lmax=0, lap=0;
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    for(int i = 1; i <= n; i++){
        int l = 0;
        for(int j = i; j <= n; j++){
            if(v[j] % 10 == 0){
                l++;
            }else{
                i = j;
                break;
            }
        }
        if(l > lmax){
            lmax = l;
            lap = 1;
        }else if(l == lmax){
            lap++;
        }
    }
    fout << lmax << ' ' << lap;
    return 0;
}
