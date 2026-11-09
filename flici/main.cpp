#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("flici.in");
ofstream fout("flici.out");
int n;
int v[100004], a[100004];
int f[10004];
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    for(int i = 1; i <= n; i++){
        fin >> a[i];
        f[a[i]]++;
    }
    sort(a+1, a+n+1);
    sort(v+1, v+n+1);
    int r = 0;
    for(int i = 1; i <= n; i++){
        r += abs(v[i]-a[i]);
    }
    /*
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 10000; j++){
            if(f[v[i]-j]){
                f[v[i]-j]--;
                r += j;
                break;
            }else if(f[v[i]+j]){
                f[v[i]+j]--;
                r += j;
                break;
            }
        }
    }*/
    fout << r;
    return 0;
}
