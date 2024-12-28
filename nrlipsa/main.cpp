#include <fstream>
using namespace std;
ifstream fin("nrlipsa.in");
ofstream fout("nrlipsa.out");
int n, x;
bool f[1004];
int main()
{
    fin >> n;
    while(fin >> x){
        if(x < 1000){
            f[x] = true;
        }
    }
    int nr = 2;
    int x,y;
    for(int i = 999; i >= 100 && nr > 0; i--){
        if(f[i] == false){
            if(nr == 2){
                x = i;
                nr = 1;
            }else{
                y = i;
                nr = 0;
            }
        }
    }
    if(nr == 0){
        fout << x << ' ' << y;
    }else{
        fout << "NU";
    }
    return 0;
}
