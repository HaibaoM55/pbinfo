/*PART 1:
#include <fstream>
#include <string.h>
using namespace std;
#define LIMIT 496
ifstream fin("a.in");
ofstream fout("a.out");
struct redtile{
    int x, y;
}v[500];
char x[50];
long long modul(long long r){
    if(r < 0){
        return -r;
    }
    return r;
}
int main(){
    for(int i = 1; i <= LIMIT; i++){
        fin.get(x, 50);
        fin.get();
        int l = strlen(x);
        int nrz = 0;
        v[i].x = 0;
        v[i].y = 0;
        for(int j = 0; j < l; j++){
            if(x[j] == ','){
                nrz++;
                continue;
            }
            if(nrz == 0){
                v[i].x = v[i].x*10+x[j]-'0';
            }else{
                v[i].y = v[i].y*10+x[j]-'0';
            }
        }
    }
    long long vmax = 0;
    for(int i = 1; i <= LIMIT; i++){
        for(int j = i+1; j <= LIMIT; j++){
            vmax = max(vmax, (modul(v[i].x-v[j].x)+1LL)*(modul(v[i].y-v[j].y)+1LL));
        }
    }
    fout << vmax;
    return 0;
}
*/
//PART 2:
#include <fstream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define LIMIT 496
ifstream fin("a.in");
ofstream fout("a.out");
struct redtile{
    int x, y;
}v[500];
char x[50];
long long modul(long long r){
    if(r < 0){
        return -r;
    }
    return r;
}
int main(){
    for(int i = 1; i <= LIMIT; i++){
        fin.get(x, 50);
        fin.get();
        int l = strlen(x);
        int nrz = 0;
        v[i].x = 0;
        v[i].y = 0;
        for(int j = 0; j < l; j++){
            if(x[j] == ','){
                nrz++;
                continue;
            }
            if(nrz == 0){
                v[i].x = v[i].x*10+x[j]-'0';
            }else{
                v[i].y = v[i].y*10+x[j]-'0';
            }
        }
    }
    vector<int> xs, ys;
    for(int i = 1; i <= LIMIT; i++){
        xs.push_back(v[i].x);
        ys.push_back(v[i].y);
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    map<int, int> xmap, ymap;
    for(int i = 0; i < xs.size(); i++) xmap[xs[i]] = i;
    for(int i = 0; i < ys.size(); i++) ymap[ys[i]] = i;
    int n = xs.size();
    int m = ys.size();
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for(int i = 1; i <= LIMIT; i++){
        grid[xmap[v[i].x]][ymap[v[i].y]] = 1;
    }
    for(int i = 1; i <= LIMIT; i++){
        int next = (i % LIMIT) + 1;
        int cx1 = xmap[v[i].x], cy1 = ymap[v[i].y];
        int cx2 = xmap[v[next].x], cy2 = ymap[v[next].y];

        if(cx1 == cx2){
            for(int cy = min(cy1, cy2); cy <= max(cy1, cy2); cy++){
                grid[cx1][cy] = 1;
            }
        }else{
            for(int cx = min(cx1, cx2); cx <= max(cx1, cx2); cx++){
                grid[cx][cy1] = 1;
            }
        }
    }
    for(int cx = 0; cx < n; cx++){
        for(int cy = 0; cy < m; cy++){
            if(grid[cx][cy] == 1) continue;
            int crossings = 0;
            for(int i = 1; i <= LIMIT; i++){
                int next = (i % LIMIT) + 1;
                int cy1 = ymap[v[i].y], cy2 = ymap[v[next].y];
                int cx1 = xmap[v[i].x], cx2 = xmap[v[next].x];

                if((cy1 <= cy && cy2 > cy) || (cy2 <= cy && cy1 > cy)){
                    double x_cross = cx1 + (double)(cx2 - cx1) * (cy - cy1) / (cy2 - cy1);
                    if(x_cross < cx){
                        crossings++;
                    }
                }
            }

            if(crossings % 2 == 1){
                grid[cx][cy] = 1;
            }
        }
    }
    vector<vector<int>> prefix(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + grid[i-1][j-1];
        }
    }
    long long vmax = 0;
    for(int i = 1; i <= LIMIT; i++){
        for(int j = i+1; j <= LIMIT; j++){
            int cx1 = xmap[v[i].x], cy1 = ymap[v[i].y];
            int cx2 = xmap[v[j].x], cy2 = ymap[v[j].y];
            int minx_c = min(cx1, cx2);
            int maxx_c = max(cx1, cx2);
            int miny_c = min(cy1, cy2);
            int maxy_c = max(cy1, cy2);
            int cnt = prefix[maxx_c+1][maxy_c+1] - prefix[minx_c][maxy_c+1] - prefix[maxx_c+1][miny_c] + prefix[minx_c][miny_c];
            int expected = (maxx_c - minx_c + 1) * (maxy_c - miny_c + 1);
            if(cnt == expected){
                long long arie = (modul(v[i].x-v[j].x)+1LL)*(modul(v[i].y-v[j].y)+1LL);
                vmax = max(vmax, arie);
            }
        }
    }
    fout << vmax;
    return 0;
}
