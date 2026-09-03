#include <fstream>
using namespace std;
ifstream fin("mister.in");
ofstream fout("mister.out");
int n, k;
int a[200005], b[200005], t[200005];
int x, y, p1, p2;
int main(){
    fin>>n>>k;
    for(int i = 1; i <= n; i++){
        fin >> b[i];
    }
    p1=1; p2=n;
    x=0; y=-1;
    for(int i = 1; i <= n; i++){
        if(x <= y && t[x] == i-k){
            a[t[x]] = p2;
            p2--;
            x++;
        }
        while(y-x+1 > b[i]-1){
            a[t[y]] = p1;
            p1++;
            y--;
        }
        y++;
        t[y]=i;
    }
    while(x <= y){
        a[t[x]]=p2;
        p2--;
        x++;
    }
    for(int i = 1; i <= n; i++){
        fout << a[i] << ' ';
    }
    return 0;
}
