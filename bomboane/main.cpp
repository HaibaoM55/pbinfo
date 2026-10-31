#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("bomboane.in");
ofstream fout("bomboane.out");
int n, t, m;
int s[1004], d[1004], b[1004];
pair<int, int> v[1004];
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i].first;
        t += v[i].first;
        v[i].second = i;
    }
    if(t % n != 0){
        fout << "-1";
        return 0;
    }
    int p = t/n;
    while(true){
        sort(v+1, v+n+1);
        if(v[1].first == v[n].first){
            break;
        }
        int x = min(v[n].first - p, p - v[1].first);
        m++;
        s[m] = v[n].second;
        d[m] = v[1].second;
        b[m] = x;
        v[n].first -= x;
        v[1].first += x;
    }
    fout << m << '\n';
    for(int i = 1; i <= m; i++){
        fout << s[i] << ' ' << d[i] << ' ' << b[i] << '\n';
    }
    return 0;
}
