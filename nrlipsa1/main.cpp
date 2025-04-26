#include <fstream>
using namespace std;
ifstream fin("nrlipsa1.in");
ofstream fout("nrlipsa1.out");
int x;
int f[104];
int main()
{
    while(fin >> x){
        if(x <= 99){
            f[x]++;
        }
    }
    int j = 0;
    for(int i = 10; i <= 98; i+=2){
        if(f[i]==0){
            j = i;
            break;
        }
    }
    for(int i = 98; i >= 10; i -= 2){
        if(f[i] == 0 && i != j){
            fout << j << ' ' << i;
            return 0;
        }
    }
    fout << "nu exista";
    return 0;
}
