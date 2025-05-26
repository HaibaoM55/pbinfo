#include <fstream>
using namespace std;
ifstream fin("afisaren.in");
ifstream fin1("afisaren.in");
ofstream fout("afisaren.out");
int n;
char x;
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        ifstream fin1("afisaren.in");
        fin1 >> n;
        while(fin1 >> x){
            fout << x;
        }
        fout << '\n';
    }
    return 0;
}
