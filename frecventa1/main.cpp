#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("frecventa1.in");
ofstream cout("frecventa1.out");
struct benone{
    int val;
    int ap=0;
}v[100004];
int n,x;
bool compara(benone a, benone b){
    if(a.ap == b.ap){
        return a.val < b.val;
    }
    return a.ap > b.ap;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        v[x].val = x;
        v[x].ap++;
    }
    sort(v+1, v+100001, compara);
    for(int i = 1; i <= 100000; i++){
        if(v[i].ap > 0){
            cout << v[i].val << ' ';
        }else{
            break;
        }
    }
    return 0;
}
