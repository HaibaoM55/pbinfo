#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("subarbore2.in");
ofstream fout("subarbore2.out");
int n, p, x;
int rasp = 0;
int a[104];
vector<int> v[104];
void visit(int k){
    int l = v[k].size();
    rasp += a[k];
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
    for(int i = 1; i <= n; i++){
    	fin >> a[i];
    }
    visit(p);
    fout << rasp;
    return 0;
}
