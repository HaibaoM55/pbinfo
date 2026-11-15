#include <iostream>
using namespace std;
int n, m, x;
bool f[200004];
int dr[200004], b[200004];
int r = 0, frst = 2e9, lst = 0;
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> x;
        if(!f[x]){
            f[x] = true;
            r++;
            frst = min(frst, x);
            lst = max(lst, x);
        }
    }
    if(r == 1){
        cout << 0;
        return 0;
    }else if(r == m){
        cout << m-1 << '\n';
        for(int i = 0; i < m-1; i++){
            cout << i << ' ';
        }
        return 0;
    }
    bool continuous = true;
    for(int i = 1; i <= m; i++){
        if(f[i] && (i < frst || i > lst)){
            continuous = false;
        }else if(!f[i] && (frst <= i && i <= lst)){
            continuous = false;
        }
    }
    if(continuous){
        cout << lst-frst << '\n';
        for(int i = frst; i < lst; i++){
            cout << i << ' ';
        }
        return 0;
    }
//    st[0] = 0;
//    for(int j = 1;  j <= m; j++){
//        if(f[j]){
//            st[j] = j;
//        }else{
//            st[j] = st[j-1];
//        }
//    }
    b[m] = m;
    for(int j = m-1; j >= 0; j--){
        if(f[j]){
            dr[j] = b[j+1];
            b[j] = j;
        }else{
            dr[j] = b[j+1];
            b[j] = b[j+1];
        }
    }
    int vmin = 2e9, vmini = 0;
    for(int i = 0; i < m; i++){
        int p = m-dr[i]+i;
        //cout << i << ' ' << dr[i] << '\n';
        if(p < vmin){
            vmin = p;
            vmini = i;
        }
    }
    if(lst-frst < vmin){
        cout << lst-frst << '\n';
        for(int i = frst; i < lst; i++){
            cout << i << ' ';
        }
        return 0;
    }
    cout << vmin << '\n';
    for(int i = dr[vmini]; i < m; i++){
        cout << i << ' ';
    }
    for(int i = 0; i < vmini; i++){
        cout << i << ' ';
    }
	return 0;
}
