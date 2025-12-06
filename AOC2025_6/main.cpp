/*PART 1:
#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("a.in");
ofstream fout("a.out");
typedef long long NrMare[100004];
void AtribMic(NrMare x, long long n){
  x[0]=0;
  if(n==0)
    x[(x[0]=1)]=0;
  else
    for(;n;n/=10)
      x[++x[0]]=n%10;
}
void Adunare(NrMare x,NrMare y){
  int i,t=0;
  if(x[0]<y[0])
    x[0]=y[0];
  for(i=1;i<=x[0];i++,t/=10){
    t=x[i]+y[i]+t;
    x[i]=t%10;
  }
  if(t)
    x[++x[0]]=t;
}
void destroy(NrMare x){
    for(int i = 0; i <= 10000; i++){
        x[i] = 0;
    }
}
long long r[7][1004];
NrMare raspuns;
NrMare x;
char y[100004];
int main(){
    for(int i = 1; i <= 4; i++){
        fin.get(y, 100004);
        fin.get();
        int l = strlen(y);
        int z = 0;
        for(int j = 0; j < l; j++){
            if('0' <= y[j] && y[j] <= '9'){
                z++;
                while('0' <= y[j] && y[j] <= '9'){
                    r[i][z] = r[i][z]*10+(y[j]-'0');
                    j++;
                }
            }
        }
        fout << z << ' ';
    }
    fin.get(y, 100004);
    fin.get();
    int l = strlen(y);
    int z = 0;
    for(int i = 0; i < l; i++){
        if(y[i] == '+'){
            z++;
            AtribMic(x, 1LL*r[1][z]+r[2][z]+r[3][z]+r[4][z]);
            Adunare(raspuns, x);
            for(int j = x[0]; j >= 1; j--){
                fout << x[j];
            }
            destroy(x);
        }else if(y[i] == '*'){
            z++;
            AtribMic(x, 1LL*r[1][z]*r[2][z]*r[3][z]*r[4][z]);
            Adunare(raspuns, x);
            for(int j = x[0]; j >= 1; j--){
                fout << x[j];
            }
            destroy(x);
        }
        fout << ' ';
    }
    fout << '\n';
    fout << z;
    for(int i = raspuns[0]; i >= 1; i--){
        fout << raspuns[i];
    }
    return 0;
}*/
//PART 2:
#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("a.in");
ofstream fout("a.out");
typedef long long NrMare[100004];
void AtribMic(NrMare x, long long n){
  x[0]=0;
  if(n==0)
    x[(x[0]=1)]=0;
  else
    for(;n;n/=10)
      x[++x[0]]=n%10;
}
void Adunare(NrMare x,NrMare y){
  int i,t=0;
  if(x[0]<y[0])
    x[0]=y[0];
  for(i=1;i<=x[0];i++,t/=10){
    t=x[i]+y[i]+t;
    x[i]=t%10;
  }
  if(t)
    x[++x[0]]=t;
}
void destroy(NrMare x){
    for(int i = 0; i <= 10000; i++){
        x[i] = 0;
    }
}
long long r[7][1004];
NrMare raspuns;
NrMare x;
char y[7][100004];

int main(){
    for(int i = 1; i <= 4; i++){
        fin.get(y[i], 100004);
        fin.get();
    }
    fin.get(y[5], 100004);
    fin.get();
    int l = max(strlen(y[1]), strlen(y[2]));
    l = max(l, (int)strlen(y[3]));
    l = max(l, (int)strlen(y[4]));
    for(int i = 0; i < l; i++){
        bool eadunare = true;
        if(y[5][i] == '+' || y[5][i] ==  '*'){
            long long nr = 0;
            if(y[5][i] == '*'){
                eadunare = false;
                nr = 1;
            }
            while(y[5][i+1] != '+' && y[5][i+1] != '*' && i < l){
                long long nr1 = 0;
                for(int j = 1; j <= 4; j++){
                    if('0' <= y[j][i] && y[j][i] <= '9'){
                        nr1 = nr1*10+y[j][i]-'0';
                    }
                }
                if(eadunare){
                    nr += nr1;
                }else{
                    nr = 1LL*nr*nr1;
                }
                i++;
            }
            AtribMic(x, nr);
            Adunare(raspuns, x);
            destroy(x);
        }
    }
    for(int i = raspuns[0]; i >= 1; i--){
        fout << raspuns[i];
    }
    return 0;
}
