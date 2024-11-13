#include <fstream>
using namespace std;
ifstream cin("coada2.in");
ofstream cout("coada2.out");
long long x, y, z;
long long s = 0;
int main()
{
    cin >> x >> y >> z;
    /*
    Andrei este în fața lui Mihai la coadă, iar între
    cei doi se afla alte x persoane, Mihai a observat că în total,
    ​în fata lui , se afla ​y ​persoane, iar Andrei a observat că în spatele ​lui se află z persoane.
    */
    s = (y-1)+(z-1)-x+2;
    if(y >= x && z > x){
        cout << s;
    }else{
        cout << -1;
    }
    return 0;
}
