int cifmaxpar(int x){
    if(x > 9){
        if(x % 2 == 0){
            return max(x%10, cifmaxpar(x/10));
        }
        return cifmaxpar(x/10);
    }else{
        if(x % 2 == 0){
            return x%10;
        }else{
            return -1;
        }
    }
}
/*#include <iostream>
using namespace std;

int main(){
    cout << cifmaxpar(2154);
}*/
