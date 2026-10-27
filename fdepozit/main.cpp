#include <algorithm>
int depozit(int x, int y, int z){
    int r = x*y/__gcd(x, y);
    r = r*z/__gcd(r, z);
    return r;
}
