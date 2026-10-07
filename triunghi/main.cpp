#include <iostream>
using namespace std;
double x, y, z;
int main(){
    cin >> x >> y >> z;
    if(z >= x+y || x >= z+y || y >= x+z || x <= 0 || y <= 0 || z <= 0){
        cout << "nu";
    }else{
        cout << "da";
    }
    return 0;
}
