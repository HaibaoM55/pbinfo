#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("mostenire.in");
ofstream fout("mostenire.out");
int n, k;
bool compara(int a, int b){
    if(a < b){
        return false;
    }
    return true;
}
int v[100004], a[100004];
int main()
{
    fin >> n >> k;
    for(int i = 1; i <= n; i++){
        fin >> a[i];
        v[i] = a[i];
    }
    sort(v+1, v+1+n, compara);
    fout << v[n] << '\n';
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i] == v[j]){
                fout << j << " 1\n";
                break;
            }
        }
    }
    return 0;
}
