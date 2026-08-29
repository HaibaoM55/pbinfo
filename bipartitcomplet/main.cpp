#include <fstream>
using namespace std;
ifstream fin("bipartitcomplet.in");
ofstream fout("bipartitcomplet.out");
int n, k, x;
bool a[104];
int main(){
    fin >> n;
    fin >> k;
    for(int i = 1; i <= k; i++){
        fin >> x;
        a[x] = true;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            fout << ((a[i] && !a[j]) || (!a[i] && a[j])) << ' ';
        }
        fout << '\n';
    }
    return 0;
}
