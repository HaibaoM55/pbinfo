#include <fstream>
#include <bitset>
using namespace std;
ifstream fin("casa.in");
ofstream fout("casa.out");
int p;
int n, m, x;
struct poz{
    int i, j;
}f[100004];
unsigned short mat[1000004];
char c;
int lin, col;
int main(){
    fin >> p;
    if(p == 1){
        bitset<100004> a;
        fin >> n;
        f[1].i = 1;
        f[1].j = 1;
        int nr = 1;
        int lin=1, col=1;
        for(int i = 1; i <= n; i++){
            fin >> x >> c;
            nr++;
            f[nr].i = f[x].i;
            f[nr].j = f[x].j;
            if(c == 'N'){
                f[nr].i--;
            }else if(c == 'S'){
                f[nr].i++;
            }else if(c == 'E'){
                f[nr].j++;
            }else{
                f[nr].j--;
            }
            lin = max(lin, f[nr].i);
            col = max(col, f[nr].j);
        }
        int linmin = 2e9;
        int colmin = 2e9;
        for (int i = 1; i <= n; i++) {
            linmin = min(linmin, f[i].i);
            colmin = min(colmin, f[i].j);
        }
        int dl = 1 - linmin;
        int dc = 1 - colmin;
        for (int i = 1; i <= nr; i++) {
            f[i].i += dl;
            f[i].j += dc;
        }
        lin += dl;
        col += dc;
        for(int i = 1; i <= nr; i++){
            a[(f[i].i-1)*col+f[i].j]=true;
        }
        fout << lin <<' ' << col << '\n';
        for(int i = 1; i <= lin; i++){
            for(int j = 1; j <= col; j++){
                fout << a[(i-1)*col+j] << ' ';
            }
            fout << '\n';
        }
    }else{
        fin >> n >> m;
        int nr = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                fin >> mat[(i-1)*m+j];
                if(mat[(i-1)*m+j] == 1){
                    nr++;
                }
                if(mat[(i-1)*m+j] == 1 && lin == 0 && col == 0){
                    lin = i;
                    col =j;
                }
            }
        }
        int st = 0, dr = 1;
        f[1].i = lin;
        f[1].j = col;
        fout << nr << ' ' << col << '\n';
        nr = 1;
        while(st <= dr){
            st++;
            int i = f[st].i;
            int j = f[st].j;
            if(j < m && (i-1)*m+(j+1) <= 100000){
                if(mat[(i-1)*m+(j+1)] == 1){
                    nr++;
                    mat[(i-1)*m+(j+1)] = nr;
                    dr++;
                    f[dr].i = i;
                    f[dr].j = j+1;
                    fout << mat[(i-1)*m+j] << " E\n";
                }
            }
            if((i-1) < n&& i*m+j <= 100000){
                if(mat[i*m+j] == 1){
                    nr++;
                    mat[i*m+j] = nr;
                    dr++;
                    f[dr].i = i+1;
                    f[dr].j = j;
                    fout << mat[(i-1)*m+j] << " S\n";
                }
            }
            if(j > 1&& (i-1)*m+(j-1) <= 100000){
                if(mat[(i-1)*m+(j-1)] == 1){
                    nr++;
                    mat[(i-1)*m+(j-1)] = nr;
                    dr++;
                    f[dr].i = i;
                    f[dr].j = j-1;
                    fout << mat[(i-1)*m+j] << " V\n";
                }
            }
            if(i > 1&& (i-2)*m+j <= 100000){
                if(mat[(i-2)*m+j] == 1){
                    nr++;
                    mat[(i-2)*m+j] = nr;
                    dr++;
                    f[dr].i = i-1;
                    f[dr].j = j;
                    fout << mat[(i-1)*m+j] << " N\n";
                 }
            }
            mat[(i-1)*m+j] = 0;
        }
    }
    return 0;
}
