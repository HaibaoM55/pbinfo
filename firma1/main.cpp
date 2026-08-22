#include <fstream>
#include <vector>
using namespace std;
ifstream fin("firma1.in");
ofstream fout("firma1.out");
int n, x;
vector<int> v[104];
int c[104];
int rasp(int x){
    int s = 0;
    int l = v[x].size();
    for(int i = 0; i < l; i++){
        s += rasp(v[x][i]);
    }
    int sl = s/l;
    if(s % l != 0){
        sl++;
    }
    return c[x]+sl;
}
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
        v[x].push_back(i);
    }
    for(int i = 1; i <= n; i++){
        fin >> c[i];
    }
    fout << rasp(0);
    return 0;
}
