#include <iostream>
using namespace std;
int n, m;
int x;
bool ciur[1000004];
int main()
{
    ciur[0] = true;
    ciur[1] = true;
    for(int i = 2; i <= 1000000; i++){
        if(ciur[i] == false){
            for(int j = i; j <= 1000000/i; j++){
                ciur[j*i] = true;
            }
        }
    }
    cin >> n >> m;
    int nr = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> x;
            if(j % 2 != 0){
                if(ciur[x] == false){
                    nr++;
                }
            }
        }
    }
    cout << nr;
    return 0;
}
