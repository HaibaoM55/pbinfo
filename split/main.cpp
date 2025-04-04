#include <fstream>
using namespace std;
ifstream fin("split.in");
ofstream fout("split.out");
long long n;
long long a[5004];
long long vmax1[5004], vmin1[5004];
long long vmaxn[5004], vminn[5004];
long long smax=0,smaxi,smaxj,smaxk;
long long vmaxd, vmaxs;
int main(){
    fin >> n;
    for(long long i = 1; i <= n; i++){
        fin >> a[i];
    }
    vmax1[1] = a[1];
    vmin1[1] = a[1];
    for(long long i = 2; i <= n; i++){
        vmax1[i] = max(a[i], vmax1[i-1]);
        vmin1[i] = min(a[i], vmin1[i-1]);
    }
    vmaxn[n] = a[n];
    vminn[n] = a[n];
    for(long long i = n-1; i >= 1; i--){
        vmaxn[i] = max(a[i], vmaxn[i+1]);
        vminn[i] = min(a[i], vminn[i+1]);
    }
    for(long long i = 4; i <= n-4; i++){
        long long vmin=min(a[i], a[i-1]);
        long long vmax=max(a[i], a[i-1]);
        vmaxs=0;
        vmaxd=0;
        long long poz, poz2;
        for(long long j = i-2; j >= 2; j--){
            if(vmax-vmin+vmax1[j]-vmin1[j] >= vmaxs){
                vmaxs=vmax-vmin+vmax1[j]-vmin1[j];
                poz=j;
            }
            vmax=max(vmax, a[j]);
            vmin=min(vmin, a[j]);
        }
        vmin = min(a[i+1], a[i+2]);
        vmax = max(a[i+1], a[i+2]);
        for(long long j = i+2; j <= n-2; j++){
            vmin=min(vmin, a[j]);
            vmax=max(vmax, a[j]);
            if(vmax-vmin+vmaxn[j+1]-vminn[j+1] > vmaxd){
                vmaxd=vmax-vmin+vmaxn[j+1]-vminn[j+1];
                poz2=j;
            }
        }
        if(vmaxd+vmaxs > smax){
            smax=vmaxd+vmaxs;
            smaxi=poz;
            smaxj=i;
            smaxk=poz2;
        }
    }
    fout << smax << '\n';
    fout << smaxi << ' ' << smaxj << ' '<<smaxk;
    return 0;
}
