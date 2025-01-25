#include <fstream>
#include <math.h>
using namespace std;
ifstream fin("becuri.in");
ofstream fout("becuri.out");
int n, nr = 0;
int main()
{
    fin >> n;
    nr = sqrt(n);
    fout << nr;
    return 0;
}
