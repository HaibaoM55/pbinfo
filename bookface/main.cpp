#include <fstream>
using namespace std;
ifstream fin("bookface.in");
ofstream fout("bookface.out");
int n;
long long x;
long long s = 0;
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
        s = 1;
        int d = 2;
        while(d*d <= x){
            int c = 0;
            long long y = 1;
            while(x%d==0){
                c++;
                x = x/d;
                y = y*d;
            }
            if(c > 0){
                y = y*y;
                y = y*d;
                s = s*(y-1)/(d-1);
            }
            d++;
        }
        if(x > 1){
            s = s*(x*x*x-1)/(x-1);
        }
        fout << s << '\n';
    }
    return 0;
}
