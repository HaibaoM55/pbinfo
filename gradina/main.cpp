#include <fstream>
using namespace std;
ifstream fin("gradina.in");
ofstream fout("gradina.out");
int n, p, k;
int s[1004][1004];
int vmax = 0, vmaxnr=0;
int main(){
    fin >> n >> p >> k;
    for(int i = 1; i <= p; i++){
        int x, y;
        fin >> x >> y;
        s[x][y] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+s[i][j];
        }
    }
    for(int i = 1; i <= n-k+1; i++){
        for(int j = 1; j <= n-k+1; j++){
            int suma = s[i+k-1][j+k-1] - s[i-1][j+k-1] - s[i+k-1][j-1] + s[i-1][j-1];
            if(suma > vmax){
                vmax = suma;
                vmaxnr = 1;
            }else if(suma == vmax){
                vmaxnr++;
            }
        }
    }
    fout << vmax << '\n';
    fout << vmaxnr;
    return 0;
}
