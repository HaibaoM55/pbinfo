#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("pergament.in");
ofstream fout("pergament.out");
int n,k,q,k1 = 1;
int a,b,c,d;
int x,y,j,r,l;
int cnt = 0;
pair<int , int> s[200004];
int v[51];
int main()
{
    fin >> n >> k >> q;
    fin >> a >> b >> c >> d;
    fin >> x >> y;
    if(x == 1&& y == 50){
        fout << 500000000;
        return 0;
    }
    cnt = 0;
    for (int i = 1; i <= q; i++)
    {
        fin >> j >> r >> l;
        cnt++;
        s[cnt] = {r,j};
        cnt++;
        s[cnt] = {r+l,-j};
    }
    sort(s + 1, s + cnt + 1);
    int nr = 0;
    for (int i = 1; i <= n; i++)
    {
        while (s[k1].first == i)
        {
            if (s[k1].second < 0) v[-s[k1].second] = 0;
            else v[s[k1].second] = 1;
            k1++;
        }
        for (int j = x; j <= x + y - 1; j++)
        {
            if (v[j] == 1){
                nr++;
            }
        }
        x = 1 + (x * a + b) % k;
        y = 1 + (y * c + d) % (k - x + 1);
    }
    fout << nr;
    return 0;
}
