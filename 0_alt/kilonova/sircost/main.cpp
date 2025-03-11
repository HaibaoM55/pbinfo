#include <fstream>
using namespace std;
ifstream fin("sircost.in");
ofstream fout("sircost.out");
long long n, v[200004], q;
long long ult[200004], m[200004], p[200004];
long long x, y;
int main()
{
    fin >> n;
    fin >> x;
    ult[0] = -1;
    for(int i = 1; i < n; i++) {
        if(i > 1){
            ult[i - 1] = ult[i - 2];
        }
        fin >> y;
        if(x == y){
          ult[i - 1] = i - 1;
        }else if(x < y) {
          p[i - 1]++;
          v[i - 1] += i;
        }else{
          m[i - 1]++;
          v[i - 1] -= i;
        }

        v[i] = v[i - 1];
        p[i] = p[i - 1];
        m[i] = m[i - 1];

        x = y;
      }
    fin >> q;
    for(int z = 1;  z <= q; z++){
        int st, dr;
        fin >> st >> dr;
        st--;
        dr-= 2;
        if(ult[dr] < st){
            fout << v[dr] - v[st - 1] - st * (p[dr] - p[st - 1] - m[dr] + m[st - 1]);
        }else{
            fout << v[dr] - v[ult[dr]] - st * (p[dr] - p[ult[dr] - 1] - m[dr] + m[ult[dr] - 1]);
        }
        fout << '\n';
    }
    return 0;
}
