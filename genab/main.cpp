#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
#define int long long
int a, b, n = 0;
int v[600000];
stack<int> st;
void bt(int rasp) {
    st.push(rasp);
    while(!st.empty()){
        int x = st.top();
        st.pop();
        if(a <= x && x <= b){
            n++;
            v[n] = x;
        }else if(x > b){
            continue;
        }
        if(x == 0){
            for(int i = 9; i >= 1; i--){
                st.push(i);
            }
        }else{
            if(x % 10 == 0){
                st.push(x*10+1);
            }else if (x % 10 == 9){
                st.push(x*10+8);
            }else{
                st.push(x*10+(x % 10)+1);
                st.push(x*10+(x % 10)-1);
            }
        }
    }
}
signed main(){
    cin >> a >> b;
    bt(0);
    sort(v+1, v+n+1);
    for(int i = 1; i <= n; i++){
        cout << v[i] << '\n';
    }
    return 0;
}
