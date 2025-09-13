#include <iostream>
using namespace std;
int a, b, nr = 0;
bool ciur[100004];
int main(){
    cin >> a >> b;
    if(a > b){
        swap(a, b);
    }
    for(int i = 2; i <= b; i++){
        if(ciur[i] == false){
            if(i >= a){
                nr++;
            }
            for(int j = i; j <= b/i; j++){
                ciur[j*i] = true;
            }
        }
    }
    cout << nr;
    return 0;
}
