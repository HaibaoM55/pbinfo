#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("secventak.in");
ofstream fout("secventak.out");
int n, k;
int v[100004];
long long s[100004];
int main(){
    fin >> n >> k;
    s[0] = 0;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        v[i] = v[i]-k;
        s[i] = s[i-1]+v[i];
    }
    long long nr = 0;
    for(int i = 1; i <= n; i++) {
        long long *j = lower_bound(s+1, s+n+1, s[i]+1);
        nr += (s+n+1)-j;
    }
    fout << nr;
    return 0;
}
