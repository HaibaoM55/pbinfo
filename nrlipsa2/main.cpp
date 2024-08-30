#include <fstream>
using namespace std;
ifstream fin("nrlipsa2.in");
ofstream fout("nrlipsa2.out");
bool f[204];
int x;
int main()
{
    while(fin >> x){
        if(-100 <= x && x <= 100){
            f[x+100]=true;
        }
    }
    for(int i = 0; i <= 200; i++){
        if(f[i] == false){
            fout << i-100;
            return 0;
        }
    }
    fout << "nu exista";
    return 0;
}
