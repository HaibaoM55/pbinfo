#include <iostream>
using namespace std;
int x, y, z;
int nrm = 0;
int a, b, c;
int nri = 0;
int main(){
    cin >> x >> y >> z;
    if(y > z){
        swap(y, z);
    }
    int p1 = y/x;
    int p2 = z/x;
    if(p1*x < y){
        p1++;
    }
    nri = p2-p1+1;
    cin >> a >> b >> c;
    if(b > c){
        swap(b, c);
    }
    p1 = b/a;
    p2 = c/a;
    if(p1*a < b){
        p1++;
    }
    nrm =p2-p1+1;
    if(nrm > nri){
        cout << "Maria ";
        cout << nrm;
    }else if(nrm == nri){
        cout << "Egalitate ";
        cout << nrm;
    }else{
        cout << "Ioana ";
        cout << nri;
    }
    return 0;
}
