#include <iostream>
using namespace std;
int x, y;
int nr = 0;
void yamal_e_smecher(int a, int b){
    if(a < x){
        yamal_e_smecher(a+1, b);
    }
    if(b < y){
        yamal_e_smecher(a, b+1);
    }
    if(a == x && b == y){
        nr++;
    }
}
int main(){
    cin >> x >> y;
    yamal_e_smecher(0, 0);
    cout << nr;
    return 0;
}
