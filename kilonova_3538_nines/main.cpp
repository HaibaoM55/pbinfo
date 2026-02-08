#include <iostream>
using namespace std;
//ifstream cin("b.txt");
//ofstream cout("a.txt");
int t;
int d, k;
typedef int NrMare[1000004];
NrMare x, y, zm, vmax;
NrMare dih;
int Compara(NrMare x, NrMare y){
  while(x[0]>1 && x[x[0]]==0)
    x[0]--; //ma asigur ca nu sunt zerouri nesemnificative
  while(y[0]>1 && y[y[0]]==0)
    y[0]--;
  if(x[0]!=y[0])
    return (x[0]<y[0]?-1:1);
  int i=x[0];
  while(x[i]==y[i] && i>0)
    i--;
  if(i==0)
    return 0;
  if(x[i]<y[i])
    return -1;
  return 1;
}
void Scadere(NrMare x, NrMare y){
  int i,j, t = 0;
  for (i = 1; i <= x[0]; i++)
    if(x[i]>=y[i])
      x[i]-=y[i];
    else
    {
      j=i+1;
      while(x[j]==0)
        x[j++]=9;
      x[j]--;
      x[i]=10+x[i]-y[i];
    }
  for (; x[0] > 1 && !x[x[0]]; x[0]--); // sa n-am zerouri nesemnificative
}
void Adunare(NrMare x,NrMare y){
  int i,t=0;
  if(x[0]<y[0])
    x[0]=y[0];
  for(i=1;i<=x[0];i++,t/=10)
  {
    t=x[i]+y[i]+t;
    x[i]=t%10;
    // echivalent x[i]=(t+=x[i]+y[i])%10
  }
  if(t)
    x[++x[0]]=t;
}
void AtribMare(NrMare Dest, NrMare Sursa){
  int i;
  for(i=0;i<=Sursa[0];i++)
    Dest[i]=Sursa[i];
}
void clearzm(int mr){
    for(int i = 0; i <= mr; i++){
        zm[i] = 0;
    }
}
int main(){
    cin >> t;
    while(t){
        t--;
        cin >> d >> k;
        if(k == d){
            x[0] = d;
            zm[0] = d;
            int z = d;
            bool doar9 = true;
            for(int i = 1; i <= d; i++){
                char c;
                cin >> c;
                x[z] = c-'0';
                zm[z] = c-'0';
                if(x[z] != 9){
                    doar9 = false;
                }
                z--;
            }
            int nr9 = 0;
            if(!doar9){
                if(x[d] == 1){
                    x[x[0]] = 0;
                    x[0]--;
                    nr9 = x[0];
                    for(int j = 1; j <= x[0]; j++){
                        x[j] = 9;
                    }
                }else{
                    int km = d;
                    while(x[km] == 9){
                        km--;
                    }
                    x[km]--;
                    for(int j = 1; j < km; j++){
                        x[j] = 9;
                    }
                    nr9 = x[0]-1;
                }
            }else{
                nr9 = x[0];
            }
            if(nr9-k+1 > 1){
                y[0] = max(nr9-k+1, 0);
                y[max(nr9-k+1, 1)] = 1;
                Adunare(x, y);
            }
            if(Compara(x, zm) == 1){
                for(int i = x[0]; i >= 1; i--){
                    cout << x[i];
                    x[i] = 0;
                    y[i] = 0;
                    zm[i] = 0;
                }
            }else{
                if(nr9-k+1 > 1){
                    y[0] = 1;
                    y[max(nr9-k+1, 1)] = 0;
                    y[1] = 1;
                    Adunare(zm, y);
                }
                for(int i = zm[0]; i >= 1; i--){
                    cout << zm[i];
                    zm[i] = 0;
                    x[i] = 0;
                    y[i] = 0;
                }
            }
            cout << '\n';
            continue;
        }
        x[0] = d;
        int z = d;
        for(int i = 1; i <= d; i++){
            char c;
            cin >> c;
            x[z] = c-'0';
            z--;
        }
        dih[0] = 1;
        dih[1] = 1;
        Scadere(x, dih);
        AtribMare(vmax, x);
        int nr9 = 0;
        for(int j = x[0]; j >= 1; j--){
            if(x[j] == 9){
                nr9++;
            }
        }
        y[0] = max(nr9-k+1, 1);
        y[y[0]] = 1;
        Adunare(vmax, y);
        y[y[0]] = 0;
        y[0] = 0;
        for(int i = 2; i <= d; i++){
            if(i == d){
                if(x[i] == 1){
                    x[0]--;
                    x[i] = 0;
                    int jm = i-1;
                    while(x[jm] != 9 && jm >= 1){
                        x[jm] = 9;
                        jm--;
                    }
                }else{
                    x[i]--;
                    int jm = i-1;
                    while(x[jm] != 9 && jm >= 1){
                        x[jm] = 9;
                        jm--;
                    }
                }
            }else{
                if(x[i] >= 1){
                    x[i]--;
                    int jm = i-1;
                    while(x[jm] != 9 && jm >= 1){
                        x[jm] = 9;
                        jm--;
                    }
                }
            }
            AtribMare(zm, x);
            nr9 = 0;
            for(int j = zm[0]; j >= 1; j--){
                if(zm[j] == 9){
                    nr9++;
                }
            }
            y[0] = max(nr9-k+1, 1);
            y[y[0]] = 1;
            Adunare(zm, y);
            y[y[0]] = 0;
            y[0] = 0;
            if(Compara(vmax, zm) == -1){
                AtribMare(vmax, zm);
            }
            clearzm(zm[0]);
        }
        for(int i = vmax[0]; i >= 1; i--){
            cout << vmax[i];
            vmax[i] = 0;
            x[i] = 0;
            zm[i] = 0;
            y[i] = 0;
        }
        cout <<'\n';
        x[0] = 0;
        zm[0] = 0;
        y[0] = 0;
    }
    return 0;
}
