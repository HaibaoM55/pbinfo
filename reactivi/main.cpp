#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("reactivi.in");
ofstream fout("reactivi.out");
int n, nr = 0;
int x, y;
struct interval{
    int vmin, vmax;
}v[8004];
bool compara(interval a, interval b){
    return a.vmax < b.vmax;
}
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i].vmin >> v[i].vmax;
    }
    sort(v+1, v+n+1, compara);
    int ult = -2e9;
    for(int i = 1; i <= n; i++){
        if(v[i].vmin > ult){
            nr++;
            ult = v[i].vmax;
        }
    }
    fout << nr;
	return 0;
}
