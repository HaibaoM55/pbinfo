#include <fstream>
using namespace std;
ofstream fout("a.out");
int main()
{
    fout << 100000 << ' ' << 300 << '\n';
    for(int i = 1; i <= 100000; i++){
        fout << i << ' ';
    }
    return 0;
}
