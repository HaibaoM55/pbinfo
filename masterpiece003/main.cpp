#include <iostream>
using namespace std;
int n, k;
int prm[16] = {0,2,3,5,7,11,13,17,19,23,29,31};
int f[16] = {0,1,1,1,1,1,1,1,1,1,1};
unsigned long long s[100004];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    s[1] = 1;
    cout << s[1] << ' ';
    for(int i = 2; i <= n; i++){
        s[i] = 18446744073709551615;
        for(int j = 1; j <= k; j++){
            int p1 = f[j], p2 = i-2;
            while(p1 <= p2){
                int mij = (p1+p2)/2;
                if(s[mij]*prm[j] < s[i-1]){
                    p1 = mij+1;
                }else if(s[mij]*prm[j] == s[i-1]){
                    p1 = mij+1;
                    p2 = mij;
                }
                else{
                    p2 = mij-1;
                }
            }
            f[j] = p1;
            s[i] = min(s[i],s[p1]*prm[j]);
        }
        cout << s[i] << ' ';
    }
    return 0;
}
