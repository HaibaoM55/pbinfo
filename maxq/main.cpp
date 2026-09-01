#include <fstream>
using namespace std;
ifstream fin("maxq.in");
ofstream fout("maxq.out");
int n, m, x, y, z;
int v[200004];
long long aib[200004];
void update(int poz, int delta){
    for(; poz <= n; poz += poz & (-poz)){
        aib[poz] += 1LL*delta;
    }
}
long long query(int poz){
    long long s = 0;
    for(; poz > 0; poz -= poz & (-poz)){
        s += aib[poz];
    }
    return s;
}
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        update(i, v[i]);
    }
    fin >> m;
    for(int i = 1; i <= m; i++){
        fin >> z >> x >> y;
        x++;
        if(z == 0){
            update(x, y-v[x]);
            v[x] = y;
        }else{
            y++;
            long long s = 0, smax = 0;
            long long vmax = 0;
            for(int j = x; j <= y; j++){
                s += v[j];
                smax = max(smax, s);
                if(s < 0){
                    s = 0;
                }
            }
            if(smax < 0) smax = 0;
            fout << smax << '\n';
        }
    }
    return 0;
}
