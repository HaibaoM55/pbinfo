#include <fstream>
using namespace std;
ifstream fin("arbvalmax.in");
ofstream fout("arbvalmax.out");
int n, m, x, y;
int v[300004], t[300004];
bool b[300004];
void visit(int k, int finish){
    b[k] = true;
    if(k == finish){
        return;
    }
    visit(t[k], finish);
}
int main(){
    fin >> n >> m;
    for(int i = 2; i <= n; i++){
        fin >> t[i];
    }
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    for(int i = 1; i <= m; i++){
        fin >> x >> y;
        visit(y, x);
        int vmax = 0;
        for(int j = 1; j <= n; j++){
            if(!b[j]){
                vmax = max(vmax, v[j]);
            }
            b[j] = false;
        }
        fout << vmax << '\n';
    }
    return 0;
}
