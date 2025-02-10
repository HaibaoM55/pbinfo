#include <fstream>
using namespace std;
ifstream fin("axel.in");
ofstream fout("axel.out");
int n;
int a[1504][1504];
bool b[8004][1504];
int f[8004][1504];
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 8000; j++){
            f[j][i] = n+1;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            fin >> a[i][j];
            b[a[i][j]][j] = true;
            if(j == i){
                f[a[i][j]][j] = 0;
            }else if(j < i){
                f[a[i][j]][j] = min(f[a[i][j]][j], i-j);
            }else{
                f[a[i][j]][j] = min(f[a[i][j]][j], i+n-j);
            }
        }
    }
    int smax = -1500*1500+1;
    bool da = false;
    for(int i = 1; i <= 8000; i++){
        bool ok = true;
        for(int j = 1; j <= n; j++){
            if(b[i][j] == false){
                ok = false;
                break;
            }
        }
        if(ok){
            int sm = 0;
            for(int j = 1; j <= n; j++){
                sm = sm+f[i][j];
            }
            if(i-sm > smax){
                smax = i-sm;
            }
            da = true;
        }
    }
    if(da){
        fout << "DA\n";
        fout << smax;
    }else{
        fout << "NU";
    }
    return 0;
}
