#include <fstream>
using namespace std;
ifstream  fin("bogdan.in");
ofstream fout("bogdan.out");
char r[2][3]={"NU","DA"},s[1300005];
int n,m,op,i,j,x,y,z,t;
int v[(1<<18)+2],A[100005];
void query(int p,int a,int b,int x,int y,int &z){
  if(x<=a && b<=y){z=min(z,v[p]);}
  else{
    int mij=((a+b)>>1);
    int ok=0,z1=1,z2=1;

    if(x<=mij){query((p<<1),a,mij,x,y,z1);ok=(ok|1);}
    if(ok==1 && z1==0){z=0;return;}

    if(mij+1<=y){query((p<<1)+1,mij+1,b,x,y,z2);ok=(ok|2);}
    if(ok>1 && z2==0){z=0;return;}

    if(ok==3 && A[mij]>A[mij+1]){z=0;return;}
    z=1;
  }
}
void update(int p,int a,int b,int x){
  if(a==b){v[p]=1;}
  else{ int mij=((a+b)>>1);
    if(x<=mij){update((p<<1),a,mij,x);}
    if(mij+1<=x){update((p<<1)+1,mij+1,b,x);}
    v[p]=(v[(p<<1)] && v[(p<<1)+1] && A[mij]<=A[mij+1]);
  }
}
void creare(int p,int a,int b){
  if(a==b){ v[p]=1; }
  else{  int mij=((a+b)>>1);
    creare((p<<1),a,mij);
    creare((p<<1)+1,mij+1,b);
    v[p]=(v[(p<<1)] && v[(p<<1)+1] && A[mij]<=A[mij+1]);
  }
}
int main(){ fin>>n; fin.get();
    fin.get(s,1300005); fin.get();
    j=0;
    for(int i=1;i<=n;i++){
      while(s[j]==' ')j++;
      x=0;
      while(s[j]>='0' && s[j]<='9'){
          x=x*10+(s[j]-'0');
          j++;
      }
      A[i]=x;
    }
    creare(1,1,n);
    fin>>m; fin.get();
    for(int i=1;i<=m;i++){ fin.get(s,100); fin.get();
      j=0;
      while(s[j]==' ')j++;
      op=(s[j]-'0');j++;

      while(s[j]==' ')j++;
      x=0; while(s[j]>='0' && s[j]<='9'){x=x*10+(s[j]-'0');j++;}

      while(s[j]==' ')j++;
      y=0; while(s[j]>='0' && s[j]<='9'){y=y*10+(s[j]-'0');j++;}

      if(op==1){ A[x]=y; update(1,1,n,x); }
      else{ z=1;
        if(x>y){int aux=x; x=y; y=aux;}
        query(1,1,n,x,y,z);
        fout<<r[z]<<"\n";
      }
    }
    fout.close(); fin.close(); return 0;
}
