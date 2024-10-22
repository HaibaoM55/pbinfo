#include <fstream>
using namespace std;
ifstream fin("nevricos.in");
ofstream fout("nevricos.out");
char ch;
int nr=0;
long long secv1=0, secv2=0;
long long f1, f2;
int main()
{
    int i = 0;
    while(fin >> ch){
        nr=nr*10+(ch-'0');
        if(nr == 15 || nr == 24){
            secv1++;
        }
        nr = ch-'0';
        if(ch == '1'){
            f1++;
        }else if(ch == '2'){
            f2++;
        }
        else if(ch == '5'){
            secv2 += f1;
        }else if(ch == '4'){
            secv2 += f2;
        }
    }
    fout << secv1 << '\n';
    fout << secv2;
    return 0;
}
