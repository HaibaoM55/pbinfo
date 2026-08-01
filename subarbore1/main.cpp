#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("subarbore1.in");
ofstream fout("subarbore1.out");
int n, p, x;
vector<int> v[104], rasp;
void visit(int k){
    int l = v[k].size();
    if(l == 0){
        rasp.push_back(k);
    }
    for(int i = 0; i < l; i++){
        visit(v[k][i]);
    }
}
int main(){
    fin >> n >> p;
    for(int i = 1; i <= n; i++){
        fin >> x;
        v[x].push_back(i);
    }
    visit(p);
    sort(rasp.begin(), rasp.end());
    int l = rasp.size();
    for(int i = 0; i < l; i++){
        fout << rasp[i] << ' ';
    }
    return 0;
}
