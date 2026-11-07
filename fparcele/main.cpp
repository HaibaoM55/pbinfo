#include <algorithm>
void parcele(int x, int y, int &p, int &l){
    l = __gcd(x, y);
    p = x/l*y/l;
}
