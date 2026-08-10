#include <fstream>
using namespace std;
ifstream fin("detdrum.in");
ofstream fout("detdrum.out");
int n, k;
int t[104];
void bt(int i){
    if(i == 0) return;
    fout << i <<  ' ';
    bt(t[i]);
}
int main(){
    fin >> n >> k;
    for(int i = 1; i <= n; i++){
        fin >> t[i];
    }
    bt(k);
    return 0;
}
