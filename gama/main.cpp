#include <fstream>
using namespace std;
ifstream fin("gama.in");
ofstream fout("gama.out");
int n, k;
int v[1004];
int main(){
    fin >> n >> k;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    for(int i = 1; i <= n && k > 0; i++){
        int minim = n+1,minimi;
        int mx = min(i+k, n);
        for(int j = i; j <= mx; j++){
            if(v[j] < minim){
                minim = v[j];
                minimi = j;
            }
        }
        for(int j = minimi; j >= i+1; j--){
            swap(v[j], v[j-1]);
            k--;
        }
    }
    for(int i = 1; i <= n; i++){
        fout << v[i] << ' ';
    }
    return 0;
}
