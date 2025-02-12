#include <fstream>
using namespace std;
ifstream fin("qscmax.in");
ofstream fout("qscmax.out");
int n, q;
int v[100004];
int op, st, dr;
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    fin >> q;
    for(int z1 = 1; z1 <= q; z1++){
        fin >> op >> st >> dr;
        if(op == 1){
            v[st] = dr;
        }else{
            int k = 1;
            int kmax = 1;
            for(int i = st; i <= dr; i++){
                if(i > st){
                    if(v[i-1] <= v[i]){
                        k++;
                    }else{
                        k = 1;
                    }
                    kmax = max(kmax, k);
                }
            }
            fout << kmax <<' ';
        }
    }
    return 0;
}
