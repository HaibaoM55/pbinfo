#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("gr.in");
ofstream fout("gr.out");
int n;
int a[1000004], b[1000004];
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        fin >> b[i];
    }

    return 0;
}
