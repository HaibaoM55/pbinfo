#include <fstream>
using namespace std;
ifstream fin("platou2.in");
ofstream fout("platou2.out");
int n;
int v[1004];
int main(){
    fin >> n;
    int kmax = 0, k= 1;
    v[0] = 6741;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        if(v[i] > v[i-1]){
            k++;
        }else{
            k = 1;
        }
        kmax = max(kmax, k);
    }
    fout << kmax;
    return 0;
}
