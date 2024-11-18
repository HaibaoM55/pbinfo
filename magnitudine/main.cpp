#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("magnitudine.in");
ofstream fout("magnitudine.out");
long long n;
int k, v[20];
int nrcif = 0;
int main()
{
    fin >> n >> k;
    long long x = n;
    do{
        nrcif++;
        v[nrcif] = x%10;
        x = x/10;
    }while(x > 0);
    sort(v+1, v+nrcif+1);
    if(k == 0){
        fout << v[nrcif]-v[1];
    }else if(k == 1){
        fout << min(v[nrcif]-v[2], v[nrcif-1]-v[1]);
    }else{
        int r = min(v[nrcif-2]-v[1], v[nrcif]-v[3]);
        r = min(r, v[nrcif-1]-v[2]);
        fout << r;
    }
    return 0;
}
