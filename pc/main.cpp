#include <fstream>
using namespace std;
ifstream fin("pc.in");
ofstream fout("pc.out");
int n;
int p;
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> p;
        if(p%2 == 0){
            fout << "0 ";
        }else{
            fout << "1 ";
        }
    }
    return 0;
}
