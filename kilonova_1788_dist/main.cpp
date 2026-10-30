#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("dist.in");
ofstream fout("dist.out");
int n;
pair<int, int> v[100004];
bool ver(int x){
    int vmin = 2e9,vmax = -2e9;
    int st = 1, dr = 1;
    while(dr <= n){
        while(st <= dr && v[st].first+x <= v[dr].first){
            vmin = min(v[st].second, vmin);
            vmax = max(v[st].second, vmax);
            st++;
        }
        if(!(vmax-x < v[dr].second && v[dr].second < vmin+x)){
            return true;
        }
        dr++;
    }
    return false;
}
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i].first >> v[i].second;
    }
    sort(v+1, v+n+1);
    int rasp = 0;
    int p1 = 1, p2 = 2000000;
    while(p1 <= p2){
        int mij = (p1+p2)/2;
        if(ver(mij)){
            rasp = mij;
            p1 = mij+1;
        }else{
            p2 = mij-1;
        }
    }
    fout << rasp;
	return 0;
}
