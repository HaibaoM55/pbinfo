#include <fstream>
using namespace std;
ifstream fin("mincols1.in");
ofstream fout("mincols1.out");
int n;
int a[32][32];
int vmin[32];
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            fin >> a[i][j];
            if(i == 1){
                vmin[j] = a[i][j];
            }else{
                vmin[j] = min(vmin[j], a[i][j]);
            }
        }
    }
    int j = 1;
    int p = -1;
    for(int i = n; i >= 1; i--){
        if(vmin[j] == a[i][j]){
            if(p == -1){
                p = a[i][j]%10;
            }else{
                p = p*(a[i][j]%10);
                p = p%10;
            }
        }
        j++;
    }
    if(p == -1){
        fout << "NU EXISTA";
    }else{
        fout << p;
    }
    return 0;
}
