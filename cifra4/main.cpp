#include <fstream>
using namespace std;
ifstream fin("cifra4.in");
ofstream fout("cifra4.out");
int t;
int c, n;
int main()
{
    fin >> t;
    fin >> c >> n;
    int nr = 1;
    while(n > 0){
        int x = nr;
        bool ok=true;
        int p = 1;
        do{
            if(x% 10 == c){
                ok = false;
                break;
            }
            p = p*10;
            x = x/10;
        }while(x > 0);
        if(ok){
            n--;
            nr++;
        }else{
            nr = nr+p;
        }
    }
    fout << nr-1;
    return 0;
}
