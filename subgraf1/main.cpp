#include <fstream>
using namespace std;
ifstream fin("subgraf1.in");
ofstream fout("subgraf1.out");
int n,m,x,y;
int f[104];
bool fm[104][104];
pair<int, int> v[10004];
int main(){
    fin >> n;
    while(fin >> x >> y){
        if(!fm[x][y]){
            fm[x][y] = true;
            f[x]++;
            f[y]++;
            m++;
            v[m] = {x, y};
        }
    }
    int vmin = f[1];
    for(int i = 1; i <= n; i++){
     	vmin = min(vmin, f[i]);
    }
    int r = 0;
    for(int i = 1; i <= m; i++){
        if(f[v[i].first] > vmin && f[v[i].second] > vmin){
        	r++;
        }
    }
    fout << r;
    return 0;
}
