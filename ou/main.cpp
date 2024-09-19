#include <fstream>
using namespace std;
ifstream cin("ou.in");
ofstream cout("ou.out");
int n;
int v[100001];
long long m[100001];
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    for(int i = 2; i <= n-1; i++){
        int p = v[i]/2;
        int cmm = min(n-i, i-1);
        cmm = min(cmm, p);
        if(cmm > 0){
            int x = v[i]/(2*cmm);
            m[i-cmm] += x;
            m[i+cmm+1] -= x;
            v[i] -= (2*cmm+1)*x;
        }
    }
    for(int i = 1; i <= n; i++){
        m[i] = m[i]+m[i-1];
        cout << (long long)v[i]+(long long)m[i] << ' ';
    }
    return 0;
}
