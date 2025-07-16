#include <iostream>
using namespace std;
int mp(int x){
    if(x < 12){
        return mp(mp(x+2));
    }else{
        return x-1;
    }
}/*
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
*/
