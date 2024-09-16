#include <fstream>
using namespace std;
ifstream cin("regine.in");
ofstream cout("regine.out");
int n, m;
struct regina{
    int i, j;
    int atac=0;
}v[503];
bool a[104][104];
int p=0, q=0;
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> v[i].i >> v[i].j;
        a[v[i].i][v[i].j] = true;
    }
    for(int i = 1; i <= m; i++){
        //JOS
        for(int j = v[i].i+1; j <= n; j++){
            if(a[j][v[i].j]){
                v[i].atac++;
                break;
            }
        }
        //SUS
        for(int j = v[i].i-1; j >= 1; j--){
            if(a[j][v[i].j]){
                v[i].atac++;
                break;
            }
        }
        //STANGA
        for(int j = v[i].j-1; j >= 1; j--){
            if(a[v[i].i][j]){
                v[i].atac++;
                break;
            }
        }
        //DREAPTA
        for(int j = v[i].j+1; j <= n; j++){
            if(a[v[i].i][j]){
                v[i].atac++;
                break;
            }
        }
        //DIAG. STANGA-SUS
        int ij = v[i].i-1;
        for(int j = v[i].j-1; j >= 1 && ij >= 1; j--){
            if(a[ij][j]){
                v[i].atac++;
                break;
            }
            ij--;
        }
        //DIAG. STANGA JOS
        ij = v[i].i+1;
        for(int j = v[i].j-1; j >= 1 && ij <= n; j--){
            if(a[ij][j]){
                v[i].atac++;
                break;
            }
            ij++;
        }
        //DIAG. DREAPTA SUS
        ij = v[i].i-1;
        for(int j = v[i].j+1; j <= n && ij >= 1; j++){
            if(a[ij][j]){
                v[i].atac++;
                break;
            }
            ij--;
        }
        //DIAG. STANGA JOS
        ij = v[i].i+1;
        for(int j = v[i].j+1; j <= n && ij <= n; j++){
            if(a[ij][j]){
                v[i].atac++;
                break;
            }
            ij++;
        }
        if(v[i].atac > p){
            p = v[i].atac;
            q = 1;
        }else if(v[i].atac == p){
            q++;
        }
    }
    cout << p << ' ' << q;
    return 0;
}
