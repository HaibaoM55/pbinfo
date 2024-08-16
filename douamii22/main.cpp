#include <iostream>
using namespace std;
int n;
int f(int m){
    int div = (m - 1) / 2 + (m - 1) / 3 + (m - 1) / 337 - (m - 1) / 6 - (m - 1) / 674 - (m - 1) / 1011 + (m - 1) / 2022;
    return (m - 1) - div;
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x, nr;
        cin >> x;
        int p1 = 1;
        int p2 = 100000000;
        while(p1 <= p2){
            int mij = (p1+p2)/2;
            if(f(mij) < x){
                p1 = mij+1;
            }else{
                p2 = mij-1;
            }
        }
        cout << p2 << " ";
    }
    return 0;
}
