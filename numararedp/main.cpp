#include <iostream>
using namespace std;
long long a, b;
bool esteprim(int x){
    if(x <= 1){
        return false;
    }
    for(int i = 2; i*i <= x; i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}
void vcif(int suma, int nrcifre, int sfin){

    if(nrcifre == 18){
        return;
    }
    for(int i = 0; i <= 9; i++){

    }
}
int main(){
    cin >> a >> b;
    int nr = 0;
    for(int i = 1; i <= 153; i++){
        if(esteprim(i)){
            nr++;
            vcif(0, 0, i);
        }
    }

    return 0;
}
