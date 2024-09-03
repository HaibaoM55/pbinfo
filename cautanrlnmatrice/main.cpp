#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("cautanrinmatrice.in");
ofstream fout("cautanrinmatrice.out");
int n, m, p;
int z = 0;
int nr;
struct mat{
    int i, j;
    int x;
} a[1000004];
bool compara(mat a, mat b){
    if(a.x < b.x){
        return true;
    }
    return false;
}
int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            z++;
            fin >> a[z].x;
            a[z].i = i;
            a[z].j = j;
        }
    }
    sort(a+1, a+z+1, compara);
    fin >> p;
    for(int i = 1; i <= p; i++){
        fin >> nr;
        int p1 = 1, p2 = z;
        while(p1 <= p2){
            int mij = (p1+p2)/2;
            if(a[mij].x < nr){
                p1 = mij+1;
            }else if(a[mij].x == nr){
                p2 = mij;
                break;
            }
            else{
                p2 = mij-1;
            }
        }
        if(nr == a[p2].x){
            fout << a[p2].i << ' ' << a[p2].j << '\n';
        }else{
            fout << 0 << '\n';
        }
    }
    return 0;
}
