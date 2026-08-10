#include <fstream>
using namespace std;
ifstream fin("detdrum1.in");
ofstream fout("detdrum1.out");
int n, k;
int t[104], v[104];
void bt(int p){
	if(p == 0) return;
    v[0]++;
    v[v[0]] = p;
    bt(t[p]);
}
int main(){
	fin >> n >> k;
    for(int i = 1; i <= n; i++){
     	fin >> t[i];
    }
    bt(k);
    for(int i = v[0]; i >= 1; i--){
    	fout << v[i] << ' ';
    }
}
