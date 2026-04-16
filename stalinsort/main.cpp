#include <fstream>
using namespace std;
#define int long long
ifstream fin("stalinsort.in");
ofstream fout("stalinsort.out");
int n;
int v[1000004];
long long f[1000004];
int stiva[1000004];
long long mars[1000004];
bool maimare = true, maimic = true;
signed main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    int dr = 0;
    stiva[0] = 0;
    for(int i = 1; i <= n; i++){
        int nr = n-i+1;
        while(dr >= 1 && v[i] >= v[stiva[dr]]){
            dr--;
        }
        dr++;
        stiva[dr] = i;
        mars[stiva[dr-1]+1] += nr;
        mars[i+1] -= nr;
    }
    mars[0] = 0;
    for(int i = 1; i <= n; i++){
        mars[i] = mars[i-1]+mars[i];
        fout << (long long) mars[i] << ' ';
    }
    return 0;
}
