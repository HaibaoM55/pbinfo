#include <fstream>
#include <iomanip>
using namespace std;
ifstream fin("medpoz.in");
ofstream fout("medpoz.out");
int n;
int a[23][23];
int s = 0, z= 0;
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            fin >> a[i][j];
            if(j < i && a[i][j] > 0){
                z++;
                s += a[i][j];
            }
        }
    }
    if(z == 0){
        fout << "NU EXISTA";
    }else{
        double benone = 1.0*s;
        benone = benone/z;
        fout << fixed << setprecision(3) << benone;
    }
    return 0;
}
