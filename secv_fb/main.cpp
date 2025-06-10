#include <fstream>
#include <unordered_map>
using namespace std;
ifstream fin("secv_fb.in");
ofstream fout("secv_fb.out");
int n,k;
int v[100004];
unordered_map<int, int> f;
int main()
{
    fin >> n >> k;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    int nrt = 0;
    int nr = 0;
    for(int i = 1; i <= k; i++){
        f[v[i]]++;
        if(f[v[i]] == 2){
            nrt++;
        }
    }
    if(nrt == 0){
        nr++;
    }
    for(int i = k+1; i <= n; i++){
        f[v[i-k]]--;
        if(f[v[i-k]] == 1){
            nrt--;
        }
        f[v[i]]++;
        if(f[v[i]] == 2){
            nrt++;
        }
        if(nrt == 0){
            nr++;
        }
    }
    fout << nr;
    return 0;
}
