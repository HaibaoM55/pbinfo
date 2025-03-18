#include <fstream>
#include <map>
using namespace std;
ifstream fin("eras.in");
ofstream fout("eras.out");
int n, m, u;
map<int, int> lin, col;
int q;
int main()
{
    fin >> n >> m >> u;
    for(int i = 1; i <= u; i++){
        char t;
        int a, v;
        fin >> t >> a >> v;
        if(t == 'L'){
            lin[a] += v;
        }else{
            col[a] += v;
        }
    }
    //a[i][j] = lin[i]+col[j];
    fin >> q;
    for(int z = 1; z <= q; z++){
        int k, l1, c1, l2, c2;
        fin >> k >> l1 >> c1 >> l2 >> c2;
        long long nr = 0;
        for(int i = l1; i <= l2; i++){
            nr += 1LL*lin[i]*(c2-c1+1);
        }
        for(int i = c1; i <= c2; i++){
            nr += 1LL*col[i]*(l2-l1+1);
        }
        fout << nr << '\n';
    }
    return 0;
}
