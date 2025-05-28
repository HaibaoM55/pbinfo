#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("ordsume.in");
ofstream fout("ordsume.out");
#define int long long
int n;
int v[104];
int z = 0;
int s[100004];
signed main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        for(int j = 1; j < i; j++){
            if(v[i] != v[j]){
                z++;
                s[z] = v[i]+v[j];
            }
        }
    }
    sort(s+1, s+z+1);
    for(int i = 1; i <= z; i++){
        if(s[i] != s[i-1] || i == 1){
            fout << s[i] << ' ';
        }
    }
    return 0;
}
