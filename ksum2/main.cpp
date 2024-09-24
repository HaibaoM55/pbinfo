#include <fstream>
using namespace std;
ifstream fin("ksum2.in");
ofstream fout("ksum2.out");
int n, k, w;
int s[100002];
int vmax = -100000000;
int main()
{
    fin >> n >> k >> w;
    for(int i = 1; i <= n; i++){
        int x;
        fin >> x;
        s[i] = s[i-1]+x;
    }
    for(int i = 1; i <= n-k+1; i++){
        for(int j = i+k-1; j <= i+w-1 && j <= n; j++){
            vmax = max(vmax, s[j]-s[i-1]);
        }
    }
    fout << vmax;
    return 0;
}
