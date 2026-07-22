#include <fstream>
using namespace std;
ifstream fin("adiacenta1.in");
ofstream fout("adiacenta1.out");
int x, y;
int vmax =0;
int a[104][104];
int main(){
    while(fin >> x){
        fin >> y;
        a[x][y] = 1;
        a[y][x] = 1;
        vmax = max(vmax, max(x, y));
    }
    for(int i = 1; i <= vmax; i++){
        for(int j = 1; j <= vmax; j++){
            fout << a[i][j] << ' ';
        }
        fout << '\n';
    }
    return 0;
}
