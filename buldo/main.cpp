#include <fstream>
using namespace std;
ifstream fin("buldo.in");
ofstream fout("buldo.out");
int n;
int h[100004];
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> h[i];
    }
    int p1 = 1, p2 = h[1];
    while(p1 <= p2){
        int mij = (p1+p2)/2;
        int i = mij;
        long long c = h[1]-i;
        for(int j = 2; j <= n; j++){
            c = c - i + h[j];
            if(h[j] < i && c < 0){
                break;
            }
        }
        if(c >= 0){
            p1 = mij+1;
        }else{
            p2 = mij-1;
        }
    }
    fout << p2;
    return 0;
}
