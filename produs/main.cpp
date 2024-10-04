#include <iostream>
using namespace std;
int n, m, p;
int s[10004];
int s1[10004];
long long nr = 0;
int main()
{
    cin >> n >> p;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        s[x]++;
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        int x;
        cin >> x;
        s1[x]++;
    }
    for(int i = 1; i <= 10000; i++){
        s1[i] = s1[i-1]+s1[i];
    }
    nr = s[0]*s1[10000];
    for(int i = 1; i <= 10000; i++){
        int nrc = p/i;
        if(p % i == 0){
            nrc--;
        }
        if(nrc > 10000){
            nrc = 10000;
        }
        nr = nr+(s1[nrc]*s[i]);
    }
    cout << nr;
    return 0;
}
