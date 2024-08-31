#include <fstream>
using namespace std;
ifstream fin("oglindiri.in");
ofstream fout("oglindiri.out");
int n, m;
int v[104];
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    fin >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        fin >> x >> y;
        int z = (y-x)/2+x;
        for(int j = x; j <= z; j++){
            int aux = v[j];
            v[j] = v[y-(j-x)];
            v[y-(j-x)] = aux;
        }
    }
    for(int i = 1; i <= n; i++){
        fout << v[i] << ' ';
    }
    return 0;
}
