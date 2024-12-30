#include <fstream>
using namespace std;
ifstream fin("parap.in");
ofstream fout("parap.out");
int n;
int f[1024];
int f2[1024];
int v[100004][12];
long long x;
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
        do{
            v[i][x%10]++;
            x = x / 10;
        }while(x > 0);
        int nr1 = 0;
        int p = 1;
        for(int j = 0; j <= 9; j++){
            nr1 = nr1 + (v[i][j]%2)*p;
            p = p*2;
        }
        v[i][0] = nr1;
        f[nr1]++;
    }
    int nr = 0;
    for(int i = 1; i <= n; i++){
        int nr1 = v[i][0];
        f2[nr1]++;
        nr = nr + f[nr1] - f2[nr1];
    }
    fout << nr;
    return 0;
}
