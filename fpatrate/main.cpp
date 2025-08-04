#include <iostream>
#include <cmath>
using namespace std;
void patrate(int n, int &x, int &y){
     if(n <= 36){
        x = 0;
        y = 0;
     }else{
        for(int i = 2; i*i <= n/2; i++){
            int x2 = i*i;
            if(n % x2 == 0){
                int y2 = n/x2;
                if(y2 > x2){
                    int sq = sqrt(y2);
                    if(sq*sq == y2){
                        x = i;
                        y = sq;
                        return;
                    }
                }
            }
        }
        x = 0;
        y = 0;
     }
}/*
int main(){
    int x, y;
    patrate(800, x, y);
    cout << x << ' ' << y;
}*/
