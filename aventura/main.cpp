#include <fstream>
#include <vector>
using namespace std;
ifstream fin("aventura.in");
ofstream fout("aventura.out");
int t, n;
int b[500004];
vector<int> v[500004];
int c[500004], st=1, dr=0;
int main()
{
    fin >> t;
    for(int zp = 1; zp <= t; zp++){
        fin >> n;
        st = 1;
        dr = 0;
        for(int i = 1; i <= n; i++){
            v[i].clear();
        }
        for(int i = 1; i <= n; i++){
            int sz;
            fin >> sz;
            b[i] = sz;
            if(sz == 0){
                dr++;
                c[dr] = i;
            }
            for(int j = 1; j <= sz; j++){
                int x;
                fin >> x;
                v[x].push_back(i);
            }
        }
        while(st <= dr){
            int l = v[c[st]].size();
            for(int j = 0; j < l; j++){
                b[v[c[st]][j]]--;
                if(b[v[c[st]][j]] == 0){
                    dr++;
                    c[dr] = v[c[st]][j];
                }
            }
            st++;
        }
        fout << dr << '\n';
    }
    return 0;
}
