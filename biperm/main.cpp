#include <fstream>
using namespace std;
ifstream fin("biperm.in");
ofstream fout("biperm.out");
int n;
int a[10004], b[10004];
int fa[10004], fb[10004];
int nr = 0;
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        fin >> b[i];
    }
    for(int i = 1; i <= n; i++){
        fa[a[i]]++;
        fb[b[i]]++;
        if(fa[a[i]] == 2 || fb[b[i]] == 2){
            fa[a[i]]--;
            fb[b[i]]--;
            fb[a[i]]++;
            fa[b[i]]++;
            swap(a[i], b[i]);
            nr++;
        }
    }
    fout << nr << ' ' << nr << '\n';
    for(int i = 1; i <= n; i++){
        fout << a[i] << ' ';
    }
    fout << '\n';
    for(int i = 1; i <= n; i++){
        fout << b[i] << ' ';
    }

    return 0;
}
