#include <fstream>
#include <cassert>
#include <cstring>

using namespace std;
ifstream fin("catchy.in");
ofstream fout("catchy.out");

struct cuvant {char c[28]; int nr; };
struct cuvant1 {int poz, nr;};
cuvant D[120004];
cuvant1 B[1504];
int nrd, K, nrb, nrmax, N, exmax;

char s[1504];
char sep[]=":,;)(.?!><}{ ";
int cauta(char *p)
{
    int st=-1, dr=nrd, mijloc;
    while (dr-st>1){
        mijloc=(st+dr)/2;
        if (strcmp(D[mijloc].c, p)<0){
            st=mijloc;
        }else{
            dr=mijloc;
        }
    }
    return dr;
}

void insereaza (char *p, int poz)
{
    int i;
    for (i=nrd; i>poz; i--){
        D[i]=D[i-1];
    }
    D[poz].nr=1;
    strcpy(D[poz].c,p);
    nrd++;
}


int cautab(int p)
{
    int st=-1, dr=nrb, mijloc;
    while (dr-st>1){
        mijloc=(st+dr)/2;
        if (B[mijloc].poz<p){
            st=mijloc;
        }
        else{
            dr=mijloc;
        }
    }
    return dr;
}

void insereazaB (int poz, int Bpoz)
{
    int i;
    for (i=nrb; i>Bpoz; i--) B[i]=B[i-1];
    B[Bpoz].nr=1;
    B[Bpoz].poz=poz;
    nrb++;
}

int main()
{
    int i, j, buna, minim, poz, Bpoz;
    char *p;
    fin >> K;
    fin.get();
    for(i=0; i<K; i++){
        fin.getline(s,1504);
        p=strtok(s,sep);
        while (p){
            poz=cauta(p);
            if (poz==nrd || strcmp(D[poz].c,p)){
                insereaza(p, poz);
            }else{
                D[poz].nr++;
            }
            p=strtok(NULL,sep);
        }
      }
    fin>>N;
    fin.get();
    for (i=1; i<=N; i++){
        fin.getline(s,1504);
        p=strtok(s,sep);
        buna=1; nrb=0;
        while (p){
            poz=cauta(p);
            if (poz==nrd || strcmp(D[poz].c,p)){
                buna=0; break;
            }
            Bpoz=cautab(poz);
            if (Bpoz==nrb || B[Bpoz].poz!=poz){
                insereazaB(poz, Bpoz);
            }
            else{
              B[Bpoz].nr++;
            }
            p=strtok(NULL,sep);
         }
        if (buna){
            minim=120000+1;
            for (j=0; j<nrb; j++)
                    if (D[B[j].poz].nr/B[j].nr<minim)
                        minim=D[B[j].poz].nr/B[j].nr;
            if (minim>exmax) {exmax=minim; nrmax=i;}
        }
    }
    fout<<nrmax<<'\n'<<exmax<<'\n';
    fout.close();
    return 0;
}
