#include <fstream>
using namespace std;
ifstream fin("identice.in");
ofstream fout("identice.out");
int t, n, d;
char x;
int sl[2][1005][1005], sc[2][1005][1005];
int k;
int main(){
    fin >> t >> n >> d;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            fin >> x;
            sl[x-'0'][i][j] = sl[x-'0'][i][j-1]+1;
            sc[x-'0'][i][j] = sc[x-'0'][i-1][j]+1;
        }
    }
    long long s = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            s += sl[0][i][j]*sc[0][i][j];
            s += sl[1][i][j]*sc[1][i][j];
        }
    }
    if(t == 1){
        fout << s;
    }else{
        fout << -1;
    }
    return 0;
}
