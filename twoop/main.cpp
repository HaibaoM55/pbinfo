#include <fstream>
using namespace std;
ifstream fin("twoop.in");
ofstream fout("twoop.out");
int n, nrop1, nrop2;
long long v[100004], mars[100004];
int main()
{
    fin >> n >> nrop1 >> nrop2;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    for(int i = 1; i <= nrop1; i++){
        int st, dr, val;
        fin >> st >> dr >> val;
        mars[st] += val;
        mars[dr+1] -= val;
    }
    mars[0] = 0;
    for(int i = 1; i <= n; i++){
        mars[i] = mars[i-1]+mars[i];
        v[i] = v[i]+mars[i];
    }
    for(int i = 1; i <= nrop2; i++){
        int x;
        fin >> x;
        fout << v[x] << '\n';
    }
    return 0;
}
