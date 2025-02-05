#include <fstream>
using namespace std;
ifstream fin("cifreord1.in");
ofstream fout("cifreord1.out");
int x;
int f[10];
int main()
{
    while(fin >> x){
        do{
            f[x%10]++;
            x = x/10;
        }while(x > 0);
    }
    int z = 1;
    for(int i = 9; i >= 0; i--){
        for(int j = 1; j <= f[i]; j++){
            fout << i << ' ';
            z++;
            if(z == 21){
                z = 1;
                fout << '\n';
            }
        }
    }
    return 0;
}
