#include <fstream>
using namespace std;
#define MOD 1000000007
ifstream fin("antrenament.in");
ofstream fout("antrenament.out");
int n, m;
int a[200004], b[200004];
int main(){
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        fin >> a[i];
    }
    long long rasp = 1;
    for(int j = 1; j <= m; j++){
        fin >> b[j];
    }
    int i = n;
    for(int j = m; j >= 2; j--){
        while(true){
            if(a[i] == b[j]){
                break;
            }
            i--;
        }
        int nr = 0;
        for(int z = i; z >= 1; z--){
            if(a[z] < b[j]){
                break;
            }
            nr++;
        }
        rasp = rasp*nr;
        rasp = rasp%MOD;
    }
    fout << rasp;
    return 0;
}
