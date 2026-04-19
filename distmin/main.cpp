#include <iostream>
using namespace std;
int DistMin(int a[], int n, int x, int y){
    int lastX = -1, lastY = -1;
    int vmin = 2e9;
    for(int i = 0; i < n; i++){
        if(a[i] == x){
            lastX = i;
        }
        if(a[i] == y){
            lastY = i;
        }
        if(lastX != -1 && lastY != -1){
            vmin = min(vmin, max(lastX, lastY)-min(lastX, lastY));
        }
    }
    return vmin;
}/*
int v[10004] = {2,7,1,2,3,2,7,2,1,3,8,9,7};
int main(){
    cout << DistMin(v, 13, 7, 3);
    return 0;
}
*/
