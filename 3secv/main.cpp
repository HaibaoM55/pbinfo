#include <fstream>
using namespace std;
ifstream fin("3secv.in");
ofstream fout("3secv.out");
int n, r, nr = 0;
long long s[1000004];
int f[1000004][4];
int main()
{
    fin >> n >> r;
    s[0] = 0;
    f[0][0] = 0;
    f[0][1] = 0;
    f[0][2] = 0;
    long long nr = 0;
    for(int i = 1; i <= n; i++){
        fin >> s[i];
        s[i] = s[i-1]+s[i];
        int rst = s[i]%3;
        for(int j = 0; j <= 2; j++){
            f[i][j] = f[i-1][j];
        }
        if(rst == 0){
            if(r == 0){
                nr += f[i][0]+1;
            }else if(r == 1){
                nr += f[i][2];
            }else{
                nr += f[i][1];
            }
        }else if(rst == 1){
            if(r == 0){
                nr += f[i][1];
            }else if(r == 1){
                nr += f[i][0]+1;
            }else{
                nr += f[i][2];
            }
        }else{
            if(r == 0){
                nr += f[i][2];
            }else if(r == 1){
                nr += f[i][1];
            }else{
                nr += f[i][0]+1;
            }
        }
        f[i][rst]++;
    }
    fout << nr;
    return 0;
}
