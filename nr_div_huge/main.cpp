#include <fstream>
using namespace std;
ifstream fin("nr_div_huge.in");
ofstream fout("nr_div_huge.out");
int N;
int k, n;
int prm[4000];
int nrp = 0;
char ciur[32000];
int main()
{
    for(int i = 2; i <= 32000; i++){
        if(ciur[i] == 0){
            nrp++;
            prm[nrp] = i;
            for(int j = i; j <= 32000/i; j++){
                ciur[j*i] = 1;
            }
        }
    }
    fin >> N;
    for(int i = 1; i <= N; i++){
        fin >> n >> k;
        long long ex[10];
        int fp[10];
        int cfp=0;
        int x = k;
        int d = 1;
        while(prm[d]*prm[d] <= x){
            int p = 0;
            while(x%prm[d] == 0){
                p++;
                x /= prm[d];
            }
            if(p > 0){
                cfp++;
                fp[cfp] = prm[d];
                ex[cfp] = p;
            }
            d++;
        }
        if(x > 1){
            cfp++;
            fp[cfp] = x;
            ex[cfp] = 1;
        }
        for(int j = 1; j <= cfp; j++){
            ex[j] = ex[j]*(n+1);
        }
        int ex1[10], fp1[10];
        int cfp1=0;
        x = k+1;
        d = 1;
        while(prm[d]*prm[d] <= x){
            int p = 0;
            while(x%prm[d] == 0){
                p++;
                x /= prm[d];
            }
            if(p > 0){
                cfp1++;
                fp1[cfp1] = prm[d];
                ex1[cfp1] = p;
            }
            d++;
        }
        if(x > 1){
            cfp1++;
            fp1[cfp1] = x;
            ex1[cfp1] = 1;
        }
        long long ext[20];
        int fpt[20];
        int cfpt=0;
        int p1 = 1, p2 = 1;
        while(p1 <= cfp && p2 <= cfp1){
            if(fp[p1] < fp1[p2]){
                cfpt++;
                fpt[cfpt] = fp[p1];
                ext[cfpt] = ex[p1];
                p1++;
            }else if(fp[p1] > fp1[p2]){
                cfpt++;
                fpt[cfpt] = fp1[p2];
                ext[cfpt] = ex1[p2];
                p2++;
            }else{
                cfpt++;
                fpt[cfpt] = fp[p1];
                ext[cfpt] = ex[p1]+ex[p2];
                p1++;
                p2++;
            }
        }
        while(p1 <= cfp){
            cfpt++;
            fpt[cfpt] = fp[p1];
            ext[cfpt] = ex[p1];
            p1++;
        }
        while(p2 <= cfp1){
            cfpt++;
            fpt[cfpt] = fp1[p2];
            ext[cfpt] = ex1[p2];
            p2++;
        }
        ext[1]--;
        long long s = 1;
        for(int j = 1; j <= cfpt; j++){
            s = s*(1+ext[j]);
            s = s % 1000000007;
        }
        fout << s << '\n';
    }
    return 0;
}
