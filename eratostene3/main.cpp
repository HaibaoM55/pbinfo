#include <fstream>
using namespace std;
ifstream fin("eratostene3.in");
ofstream fout("eratostene3.out");
int n, x;
int phi(int n)
{
    int r = n , d = 2;
    while(n > 1)
    {
        if(n % d == 0)
        {
            r = r / d * (d - 1);
            while(n % d == 0)
                n /= d;
        }
        d ++;
        if(d * d > n)
            d = n;
    }
    return r;
}
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
    	fin >> x;
        fout << phi(x) << ' ';
    }
	return 0;
}
