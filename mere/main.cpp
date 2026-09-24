#include <fstream>
#include <vector>
using namespace std;
ifstream fin("mere.in");
ofstream fout("mere.out");
int n,x, y;
int c[1004];
vector<int> v[1004];
bool viz[1004];
int rasp = 0;
void visit(int k){
    rasp += c[k];
    int l = v[k].size();
    int vmax = 0, vmini = -1;
    for(int i = 0; i < l; i++){
        if(!viz[v[k][i]]){
            if(vmax < c[v[k][i]]){
                vmax = c[v[k][i]];
                vmini = v[k][i];
            }else if(vmax == c[v[k][i]]){
                vmini = min(vmini, v[k][i]);
            }
        }
    }
    if(vmini == -1) return;
    viz[vmini] = true;
    visit(vmini);
}
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> c[i];
    }
    while(fin >> x >> y){
        v[x].push_back(y);
        v[y].push_back(x);
    }
    viz[1] = true;
    visit(1);
    fout << rasp;
    return 0;
}
