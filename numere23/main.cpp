#include <fstream>
using namespace std;
ifstream fin("numere23.in");
ofstream fout("numere23.out");
int n, k, c;
int v[10004];
int a[10004];
bool ciur[100004];
int nrp = 0, prm[40004];
bool este3prim(int nr){
    if(nr == 1){
        return false;
    }
    int d = 2;
    int k = 0;
    while(nr > 1)
    {
        if(nr % d == 0)
        {
            while(nr % d == 0)
            {
                k++;
                nr /= d;
            }
        }
        d++;
        if(n>1 && d * d > nr){
            d = nr;
        }
        if(k > 3){
            return false;
        }
    }
    return true;
}
int main()
{
    fin >> n >> k >> c;
    int x = 1;
    for(int i = 1; i <= n; i++){
        while(!este3prim(x)){
            x++;
        }
        a[i] = x;
        x++;
    }
    if(c == 1){
        x--;
        fout << x;
    }else{
        int x = 1;
        int no = 2;
        int kk = 0;
        v[1] = 2;
        int i = 1;
        while(no <= n){
            int m = 0;
            for(i; i <= n; i++){
                if(v[i] == 0){
                    m++;
                }
                if(m == k){
                    v[i] = a[no];
                    no++;
                    break;
                }
                if(i == n){
                    i = 1;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            fout << v[i] << ' ';
        }
    }
    return 0;
}
