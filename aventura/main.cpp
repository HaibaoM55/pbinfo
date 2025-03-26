#include <fstream>
#include <map>
using namespace std;
ifstream fin("aventura.in");
ofstream fout("aventura.out");
int t, n;
bool b[2004];
bool v[2004][2004];
void adauga(int x, int y){
    for(int i = 2; i <= n; i++){
        if(v[y][i] && b[i]== false && v[x][i]==false){
            v[x][i] = true;
            if(x != i){
                adauga(x, i);
            }
        }else if(v[y][i]){
            v[x][i] = true;
        }
    }
}
int main()
{
    fin >> t;
    for(int zp = 1; zp <= t; zp++){
        fin >> n;
        for(int i = 1; i <= n; i++){
            b[i] = false;
            for(int j = 1; j <= n; j++){
                v[i][j] = false;
            }
            int sz;
            fin >> sz;
            for(int j = 1; j <= sz; j++){
                int x;
                fin >> x;
                v[i][x] = true;
            }
        }
        int nr = 1;
        b[1] = true;
        for(int i = 2; i <= n; i++){
            for(int j = 2; j <= n; j++){
                if(j == i){
                    continue;
                }
                if(v[i][j] && b[j]==false){
                    adauga(i, j);
                }
            }
            for(int j = 2; j <= n; j++){
                fout <<v[i][j] << ' ';
            }
            fout << '\n';
            if(!v[i][i]){
                b[i] = true;
                nr++;
            }
        }
        fout << nr<< '\n';
    }
    return 0;
}
