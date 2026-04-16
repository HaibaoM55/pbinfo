#include <fstream>
using namespace std;
ifstream fin("laser.in");
ofstream fout("laser.out");
#define int unsigned long long
int n, m;
struct punct{
    int x, y;
}a[200004], b[200004];
int sgn(long long x){
    return (x > 0)-(x < 0);
}
int det(punct a, punct b, punct c){
    return sgn((b.x - a.x)*(c.y - a.y)-(c.x - a.x)*(b.y - a.y));
}
bool segments_intersect(punct a, punct b, punct c, punct d) {
    return (det(a, b, c) != det(a, b, d))&&(det(c, d, a) != det(c, d, b));
}
punct x1;
bool intersectie(punct x, punct y, punct z){
    x1.y = z.y;
    return segments_intersect(x, y, z, x1);
}
/*bool intersectie(punct x, punct y, punct z){
    if(z.x <= max(x.x, y.x)){
        if(min(x.y, y.y) <= z.y && z.y <= max(x.y, y.y)){
            return true;
        }
    }
    return false;
}*/
signed main(){
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        fin >> a[i].x >> a[i].y;
    }
    x1.x = 500001;
    for(int i = 1; i <= m; i++){
        fin >> b[i].x >> b[i].y;
        int nr = 0;
        for(int j = 1; j < n; j++){
            if(intersectie(a[j],a[j+1],b[i])){
                nr++;
            }
        }
        fout << nr << '\n';
    }
    return 0;
}
