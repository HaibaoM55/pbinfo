#include <fstream>
using namespace std;
ifstream fin("numinum.in");
ofstream fout("numinum.out");
int n;
struct fract{
    int a, b;
}v[1000004];
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        int x, y, a, b;
        fin >> x >> y >> a >> b;
        v[1].a = x;
        v[1].b = y;
        int z = 1;
        int p = 1;
        int nrp = 0;
        bool ok = true;
        while(ok){
            ok = true;
            int oz = z;
            for(int i = oz-p+1; i <= oz; i++){
                z++;
                v[z].a = v[i].a;
                v[z].b = v[i].a+v[i].b;
                if(v[z].a == a && v[z].b == b){
                    ok = false;
                    break;
                }
                z++;
                v[z].a = v[i].a+v[i].b;
                v[z].b = v[i].b;
                if(v[z].a == a && v[z].b == b){
                    ok = false;
                    break;
                }
            }
            p = p * 2;
            nrp++;
        }
        fout << nrp << '\n';
    }
    return 0;
}
