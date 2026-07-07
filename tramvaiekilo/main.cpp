#include <fstream>
#include <algorithm>
using namespace std;
#define int long long
ifstream fin("tramvaie.in");
ofstream fout("tramvaie.out");
int n, m, q;
struct poz{
    int x, y;
}start, finish;
int v1[100004], v2[100004];
int dist(poz a, poz b){
    return abs(a.x-b.x)+abs(a.y-b.y);
}
signed main(){
    fin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        fin >> v2[i];
    }
    for(int i = 1; i <= m; i++){
        fin >> v1[i];
    }
    sort(v1+1, v1+m+1);
    sort(v2+1, v2+n+1);
    v1[0] = -2e9;
    v2[0] = -2e9;
    v1[m+1] = 2e9;
    v2[n+1] = 2e9;
    while(q){
        q--;
        fin >> start.x >> start.y >> finish.x >> finish.y;
        int rasp = 0;
        int p1 = 1, p2 = m, p=0;
        while(p1 <= p2){
            int mij = (p1+p2)/2;
            if(v1[mij] <= start.x){
                p = mij;
                p1 = mij+1;
            }else{
                p2 = mij-1;
            }
        }
        int minx = min(start.x-v1[p], v1[p+1]-start.x);
        p1 = 1, p2 = n, p=0;
        while(p1 <= p2){
            int mij = (p1+p2)/2;
            if(v2[mij] <= start.y){
                p = mij;
                p1 = mij+1;
            }else{
                p2 = mij-1;
            }
        }
        int miny = min(start.y-v2[p], v2[p+1]-start.y);
        rasp += min(minx, miny);
        p1 = 1, p2 = m, p=0;
        while(p1 <= p2){
            int mij = (p1+p2)/2;
            if(v1[mij] <= finish.x){
                p = mij;
                p1 = mij+1;
            }else{
                p2 = mij-1;
            }
        }
        minx = min(finish.x-v1[p], v1[p+1]-finish.x);
        p1 = 1, p2 = n, p=0;
        while(p1 <= p2){
            int mij = (p1+p2)/2;
            if(v2[mij] <= finish.y){
                p = mij;
                p1 = mij+1;
            }else{
                p2 = mij-1;
            }
        }
        miny = min(finish.y-v2[p], v2[p+1]-finish.y);
        rasp += min(minx, miny);
        fout << min(rasp, dist(start, finish)) << '\n';
    }
    return 0;
}
