#include <iostream>
using namespace std;
int n;
int main()
{
    cin >> n;
    for(int i = 2; i*i <= 2*n; i++){
        int pv = n-((i+1)*i/2);
        if(pv % i == 0){
            for(int x = pv/i+1; x <= pv/i+i; x++){
                cout << x << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
