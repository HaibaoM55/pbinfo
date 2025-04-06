#include <fstream>
#include <algorithm>
#include <map>
using namespace std;
ifstream fin("densitate.in");
ofstream fout("densitate.out");
int n;
long long v[100004],s[100004];
map<long long, int> f;
char a,b;
int d;
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    fin >> a>>b>>d;
    int fdi = d;
    int fdd = 100;
    s[0] = 0;
    for(int i=1;i<=n;i++){
        s[i] = s[i-1];
        if(v[i] % 2 == 0){
            s[i]++;
        }
        f[100*s[i]-fdi*i]++;
    }
    long long nr = 0;
    f[0]++;
    for(auto it:f){
        int x, y;
        tie(x,y)=it;
        nr += 1LL*y*(y-1)/2;
    }
    fout << nr;
    return 0;
}
