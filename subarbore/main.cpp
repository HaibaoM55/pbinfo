#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("subarbore.in");
ofstream fout("subarbore.out");
int n, k, x;
vector<int> v[104], rasp;
void visit(int p){
    int l = v[p].size();
    rasp.push_back(p);
    for(int i = 0; i < l; i++){
        visit(v[p][i]);
    }
}
int main(){
    fin >> n >> k;
    for(int i = 1; i <= n; i++){
        fin >> x;
        v[x].push_back(i);
    }
    visit(k);
    sort(rasp.begin(), rasp.end());
    int l = rasp.size();
    for(int i = 0; i < l; i++){
        fout << rasp[i] << ' ';
    }
    return 0;
}
