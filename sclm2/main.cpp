#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("sclm2.in");
ofstream fout("sclm2.out");
int n;
int v[100004], aib[100004], dp[100004];
void transforma(){
    int copie[100004];
    for(int i = 1; i <= n; i++){
        copie[i] = v[i];
    }
    sort(copie+1, copie+n+1);
    for(int i = 1; i <= n; i++){
        int p1 = 1, p2 = n, p = 1;
        while(p1 <= p2){
            int mij = (p1+p2)/2;
            if(copie[mij] >= v[i]){
                p = mij;
                p2 = mij-1;
            }else{
                p1 = mij+1;
            }
        }
        v[i] = p;
    }
}
void update(int pos, int delta) {
    for (; pos <= n; pos += pos & (-pos)) {
        aib[pos] = max(aib[pos], delta);
    }
}
int query(int pos){
    int sum = 0;
    for (; pos > 0; pos -= pos & (-pos)) {
        sum = max(aib[pos], sum);
    }
    return sum;
}
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    transforma();
    int vmax = 0;
    for(int i = 1; i <= n; i++){
        int r = query(v[i]);
        dp[i] = r+1;
        update(v[i], dp[i]);
        vmax = max(vmax, dp[i]);
    }
    fout << vmax;
    return 0;
}
