#include <fstream>
#include <algorithm>
#include <string.h>
using namespace std;
ifstream  fin("rime.in");
ofstream fout("rime.out");
char a[505][22],b[505][22],*p,s[300];
int n,k,x[506],y[506],r,aux;
int main(){
    ///citirea cuvintelor in a[1],...,a[n]
    fin>>n;
    fin.get();
    k=0;
    while(fin.get(s,300)){
        fin.get();
        p=strtok(s," ;,");
        while(p){
            k++;
            strcpy(a[k],p);
            p=strtok(0," ;,");
        }
    }
    for(int i=1;i<=n;i++){
        x[i]=i;
    }
    ///sortam indicii x[] astfel incat a[x[1]]<=a[x[2]]<=...<=a[x[n]]
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            if(strcmp(a[x[i]],a[x[j]])>0){
                aux=x[i];
                x[i]=x[j];
                x[j]=aux;
            }
        }
    }
    ///acum avem a[x[1]]<=a[x[2]]<=...<=a[x[n]]
    ///pentru fiecare cuvant a[x[i]] pastram in b[x[i]] sufixul "rima", dar schimbam majusculele cu minuscule
    for(int i=1;i<=n;i++){
        char z[22];
        strcpy(z,a[x[i]]);
        int l=strlen(z);
        for(int j=0;j<=l-1;j++){
            if(z[j]>='A'&&z[j]<='Z'){
                z[j]+=32;
            }
        }
        ///cautam ultima vocala din z[0...l-2]
        int j=l-2;
        while(j>=0 && strchr("aeiou",z[j])==0){
            j--;
        }
        ///copiem sufixul j...l in b[x[i]]
        strcpy(b[x[i]],z+j);
    }
    ///daca rimele sunt egale, atunci cuvintele sunt in aceeasi submultime

    r=0;
    for(int i=1;i<=n;i++){
        if(y[x[i]]==0){
            ///cuvant inca neasociat cu nicio submultime
            r++;
            y[x[i]]=r;
            for(int j=i+1;j<=n;j++){
                if(strcmp(b[x[i]],b[x[j]])==0){
                    y[x[j]]=r;
                }
            }
        }
    }
    fout<<r<<"\n";
    for(int i=1;i<=r;i++){
        for(int j=1;j<=n;j++){
            if(y[x[j]]==i){
                fout<<a[x[j]]<<" ";
            }
        }
        fout<<"\n";
    }
    return 0;
}
