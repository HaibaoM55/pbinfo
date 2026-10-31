#include <fstream>
#include <vector>
using namespace std;
ifstream fin("raspandaci.in");
ofstream fout("raspandaci.out");
int n, x, y;
vector<int> v[100004];
bool b[100004], viz[100004];
int nr = 0;
bool adauga = true;
int dr = 0, stiva[100004];
void visit(int k){
    viz[k] = true;
    int l = v[k].size();
    for(int i = 0; i < l; i++){
        if(!viz[v[k][i]]){
            visit(v[k][i]);
        }
    }
    if(adauga){
        dr++;
        stiva[dr] = k;
    }
}
int main(){
    fin >> n;
    while(fin >> x >> y){
        v[x].push_back(y);
        b[y] = true;
    }
    for(int i = 1; i <= n; i++){
        if(!viz[i]){
            visit(i);
        }
    }
    for(int i = 1; i <= n; i++){
        viz[i] = false;
    }
    adauga = false;
    while(dr >= 1){
        if(!viz[stiva[dr]]){
            visit(stiva[dr]);
            nr++;
        }
        dr--;
    }
    fout << nr;
	return 0;
}
