#include <iostream>
#include <algorithm>
using namespace std;
int n;
int nr = 0;
int v[1001];
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    sort(v+1, v+n+1);
    for(int i = 1; i <= n-1; i++){
        for(int j = i+1; j <= n; j++){
            int p1 = 1, p2 = n, mij;
            int s = v[i]+v[j];
            //cautam cel mai mare numar care este mai mic decat s (v[i]+v[j])
            while(p1 <= p2){
                mij = (p1+p2)/2;
                if(v[mij] < s){
                    p1 =  mij+1;
                }else{
                    p2 = mij-1;
                }
            }
            nr += p2-j;
        }
    }
    cout << nr;
    return 0;
}
