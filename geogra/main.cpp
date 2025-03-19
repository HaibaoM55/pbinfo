#include <fstream>
#include <map>
using namespace std;
ifstream fin("geogra.in");
ofstream fout("geogra.out");
int c;
int n, l, q;
struct tara{
    int x, y;
    bool c[31];
}v[100004];
map<int, int> f;
int b[31];
int pt = 1;
int main()
{
    fin >> c;
    fin >> n >> l;
    if(c == 1){
        for(int i = 1; i <= l; i++){
            pt = pt*2;
        }
        for(int i = 1; i <= n; i++){
            fin >> v[i].x >> v[i].y;
            int p = pt;
            int nr = 0;
            for(int j = 1; j <= l; j++){
                fin >> v[i].c[j];
                if(v[i].c[j]){
                    nr = nr+p;
                }
                p = p/2;
            }
            fout << nr << '\n';
        }
        fin >> q;
        for(int i = 1; i <= q; i++){
            for(int j = 1; j <= l; j++){
                fin >> b[j];
            }
            int nr = 0;

            fout << nr << '\n';
        }
    }
    return 0;
}
