#include <fstream>
using namespace std;
ifstream fin("permpf.in");
ofstream fout("permpf.out");
int n;
bool fol[12];
int v[12];
void bt(int k){
    if(k == n+1){
        for(int i = 1; i <= n; i++){
            fout << v[i] << ' ';
        }
        fout << '\n';
    }else{
        for(int i = 1; i <= n; i++) {
            if(fol[i]==false && i != k) {
                v[k] = i;
                fol[i] = true;
                bt(k+1);
                fol[i] = false;
            }
        }
    }
}
int main(){
    fin >> n;
    bt(1);
    return 0;
}
