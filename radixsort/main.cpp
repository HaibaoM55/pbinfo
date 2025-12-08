#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("radixsort.in");
ofstream fout("radixsort.out");
int n;
int v[1000004];
int main(){
    fin >> n;
    for(int i= 1; i <= n; i++){
        fin >> v[i];
    }
    sort(v+1, v+n+1);
    for(int i = 1; i <= n; i++){
        fout << v[i] << ' ';
    }
    return 0;
}
