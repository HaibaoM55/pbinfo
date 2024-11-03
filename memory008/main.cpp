#include <fstream>
using namespace std;
ifstream fin("memory008.in");
ofstream fout("memory008.out");
int n;
unsigned long long x, r;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        r = r^x;
    }
    cout << r;
    return 0;
}
