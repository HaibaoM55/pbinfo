#include <fstream>
using namespace std;
ifstream fin("tort.in");
ofstream fout("tort.out");
int n;
int v[200004], s[200004];
bool f[400004];
int main(){
    fin >> n;
    s[0] = 0;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        s[i] = s[i-1]+v[i];
    }
    int nr = 0, sma = 0;
    for(int i = n; i >= 2; i--){
        sma += v[i];
        f[sma] = true;
    }
    for(int i = 1;  i <= 400000; i++){
        if(f[i]){
            for(int j = i; j <= 400000; j += i){
                if(f[j]){
                    nr++;
                }else{
                    break;
                }
            }
        }
    }
    fout << nr;
    return 0;
}
