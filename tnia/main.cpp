#include <fstream>
using namespace std;
ifstream fin("tnia.in");
ofstream fout("tnia.out");
int n, m;
int h[100004];
int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        fin >> h[i];
    }
    return 0;
}
