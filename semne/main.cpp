#include <iostream>
#include <string.h>
using namespace std;
int n;
int main()
{
    cin >> n;
    int r = n%4;
    if(r == 1){
        cout << "+";
    }else if(r == 2){
        cout << "---+";
    }else if(r == 3){
        cout << "-+--+";
    }
    for(int i = 0; i < n/4; i++){
        cout << "+--+";
    }
    return 0;
}
