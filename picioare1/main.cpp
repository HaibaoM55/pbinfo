#include <iostream>
using namespace std;
int c, p;
int g, o;
int main(){
    cin >> c >> p;
    //c=g+o=>g=c-o;
    //p/2=g+2o=c-o+2o=c+o
    //o = p/2-c;
    o = p/2-c;
    g = c-o;
    cout << g << ' ' << o;
    return 0;
}
