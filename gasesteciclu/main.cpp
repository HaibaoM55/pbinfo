#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int n, m, x, y;
vector<int> v[104];
int f[104];
bool viz[104];
bool found = false;
void dfs(int start){
    stack<pair<int,int>> st;
    st.push({start, 0});
    viz[start] = true;
    f[start] = -1;
    while(!st.empty() && !found){
        int node = st.top().first;
        int &idx = st.top().second;
        if(idx == (int)v[node].size()){
            st.pop();
            continue;
        }

        int p = v[node][idx];
        idx++;
        if(!viz[p]){
            viz[p] = true;
            f[p] = node;
            st.push({p, 0});
        }else if(p != f[node]){
            cout << p << ' ';
            int cur = node;
            stack<int> rev;
            while(cur != p){
                rev.push(cur);
                cur = f[cur];
            }
            while(!rev.empty()){
                cout << rev.top() << ' ';
                rev.pop();
            }
            cout << p << '\n';
            found = true;
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        f[i] = -1;
    }
    for(int i = 1; i <= n && !found; i++){
        if(!viz[i]){
            dfs(i);
        }
    }
    return 0;
}
