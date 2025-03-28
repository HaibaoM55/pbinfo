#include <fstream>
using namespace std;
ifstream fin("pareimpare.in");
ofstream fout("pareimpare.out");
int x;
int f[101];
int main()
{
    while(fin >> x){
        f[x]++;
    }
    for(int i = 1; i <= 99; i += 2){
        if(f[i]){
            fout << i << ' ';
        }
    }
    fout << '\n';
    for(int i = 98; i >= 0; i -= 2){
        if(f[i]){
            fout << i << ' ';
        }
    }
    return 0;
}
