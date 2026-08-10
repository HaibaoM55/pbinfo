#include <fstream>
#include <vector>
using namespace std;
ifstream fin("sumsubmax.in");
ofstream fout("sumsubmax.out");
int n, x;
int a[104], b[104];
vector<int> v[104];
int vmax = -2e9;
int rasp(int k){
    if(b[k] != -2e9){
        return b[k];
    }
    b[k] = a[k];
    int l = v[k].size();
    for(int i = 0; i < l; i++){
        b[k] += rasp(v[k][i]);
    }
    return b[k];
}
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
        v[x].push_back(i);
    }
    for(int i = 1; i <= n; i++){
        fin >> a[i];
        b[i] = -2e9;
    }
    for(int i = 1; i <= n; i++){
        vmax = max(rasp(i), vmax);
    }
    for(int i = 1; i <= n; i++){
        if(rasp(i) == vmax){
            fout << i << ' ';
        }
    }
    return 0;
}
