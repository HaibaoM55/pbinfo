#include <fstream>
using namespace std;
ifstream fin("mins.in");
ofstream fout("mins.out");
int n;
int a[1004][1004];
int v[1004];
int k;
int x, y;
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            fin >> a[i][j];
        }
    }
    fin >> k;
    for(int z1 = 1; z1 <= k; z1++){
        fin >> x >> y;
        int z = 0;
        int i = 1, j = 1;
        while(i <= n && j <= n && z < n){
            if(a[x][i] <= a[y][j]){
                z++;
                v[z] = a[x][i];
                i++;
            }else if(a[x][i] > a[y][j]){
                z++;
                v[z] = a[y][j];
                j++;
            }
        }
        if(z < n){
            while(i <= n && z < n){
                z++;
                v[z] = a[x][i];
                i++;
            }
            while(j <= n && z < n){
                z++;
                v[z] = a[y][j];
                j++;
            }
        }
        for(int l = 1; l <= n; l++){
            a[x][l] = v[l];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            fout << a[i][j] << ' ';
        }
        fout << '\n';
    }
    return 0;
}
