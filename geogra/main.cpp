#include <fstream>
using namespace std;
ifstream fin("geogra.in");
ofstream fout("geogra.out");
int c;
int n, l, q;
struct tara{
    int x, y;
    bool c[31];
}v[100004];
int b[31];
int main()
{
    fin >> c;
    fin >> n >> l;
    if(c == 1){
        for(int i = 1; i <= n; i++){
            fin >> v[i].x >> v[i].y;
            for(int j = 1; j <= l; j++){
                fin >> v[i].c[j];
            }
        }
        fin >> q;
        for(int i = 1; i <= q; i++){
            for(int j = 1; j <= l; j++){
                fin >> b[j];
            }
            int nr = 0;
            for(int j = 1; j <= n; j++){
                bool ok = true;
                for(int z = 1; z <= l; z++){
                    if(b[z] == -1){
                        continue;
                    }
                    if(b[z] == 1 && v[j].c[z]==false){
                        ok = false;
                        break;
                    }else if(b[z] == 0 && v[j].c[z]){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    nr++;
                }
            }
            fout << nr << '\n';
        }
    }
    return 0;
}
