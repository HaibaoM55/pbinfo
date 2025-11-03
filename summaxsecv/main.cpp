#include <iostream>
#include <stack>
using namespace std;
int n;
int v[100004];
int st[100004], dr[100004];
long long rasp;
stack<int> stiva, stiva2;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    for(int i = 1; i <= n; i++){
        while(!stiva.empty() && v[i] > v[stiva.top()]){
            stiva.pop();
        }
        if(stiva.empty())
            st[i] = i - 1;
        else{
            st[i] = i - stiva.top() - 1;
        }
        stiva.push(i);
    }
    for(int i = n; i >= 1; i--){
        while(!stiva2.empty() && v[i] > v[stiva2.top()]){
            stiva2.pop();
        }
        if(stiva2.empty()){
            dr[i] = n - i;
        }else{
            dr[i] = stiva2.top() - i - 1;
        }
        stiva2.push(i);
    }
    long long s = 0;
    for(int i = 1 ; i <= n; i++){
        s = s+1LL*(st[i]+1)*(dr[i]+1)*v[i];
    }
    cout << s;
    return 0;
}
