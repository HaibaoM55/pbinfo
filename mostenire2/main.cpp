#include <fstream>
using namespace std;
ifstream fin("mostenire.in");
ofstream fout("mostenire.out");
int n, m;
char f[104][10004];
int s[104][10004];
int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> f[i][j];
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + (f[i][j] - '0');
        }
    }
    long long cnt = 0;
    for(int i1 = 1; i1 <= n; i1++){
        for(int i2 = i1+2; i2 <= n; i2++){
            int l = 0, c= 0;
            int h = (i2 - i1) + 1;
            for(int j = 1; j <= m; j++){
                if(f[i1][j] != '1' || f[i2][j] != '1') {
                    l = 0;
                    c = 0;
                    continue;
                }
                int suma = s[i2][j] - s[i2][j-1] - s[i1-1][j] + s[i1-1][j-1];
                if(suma == h) {
                    c++;
                    cnt += l;
                }else{
                    l += c;
                    c = 0;
                }
            }
        }
    }
    fout << cnt;
    return 0;
}
