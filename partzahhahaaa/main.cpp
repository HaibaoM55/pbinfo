#include <fstream>
using namespace std;
#define int long long
ifstream fin("part.in");
ofstream fout("part.out");
int n,k;
int a,b;
int parte(int p1x, int p1y, int p2x, int p2y, int px, int py){
    return (p2x-p1x)*(py-p1y)-(p2y-p1y)*(px-p1x);
}
bool seIntersecteaza(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
    int d1 = parte(x3,y3,x4,y4,x1,y1);
    int d2 = parte(x3,y3,x4,y4,x2,y2);
    int d3 = parte(x1,y1,x2,y2,x3,y3);
    int d4 = parte(x1,y1,x2,y2,x4,y4);
    if(((d1>0&&d2<0)||(d1<0&&d2>0)) && ((d3>0&&d4<0)||(d3<0&&d4>0))){
        return true;
    }
    return false;
}
int aria2(int x1,int y1,int x2,int y2,int x3,int y3){
    int r = (x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);
    if(r < 0){
        return -r;
    }else{
        return r;
    }
}
bool inTriunghi(int px, int py, int a, int b){
    if(px<0||py<0) return false;
    if(px*b+py*a>a*b) return false;
    return true;
}
bool punctStrictInTriunghi(int px, int py, int ax, int ay, int bx, int by, int cx, int cy){
    int d1 = parte(ax,ay,bx,by,px,py);
    int d2 = parte(bx,by,cx,cy,px,py);
    int d3 = parte(cx,cy,ax,ay,px,py);
    bool hasNeg = (d1<0)||(d2<0)||(d3<0);
    bool hasPos = (d1>0)||(d2>0)||(d3>0);
    return !(hasNeg && hasPos) && (d1!=0 && d2!=0 && d3!=0);
}
signed main(){
    fin>>k;
    while(k){
        fin >> a >> b >> n;
        int ariaMarex2 = a*b;
        int sumaAriix2 = 0;
        bool ok = true;
        int hx1=a, hy1=0, hx2=0, hy2=b;
        int X1[151],Y1[151],X2[151],Y2[151],X3[151],Y3[151];
        for(int i = 1; i <= n; i++){
            fin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i] >> X3[i] >> Y3[i];
            if(!inTriunghi(X1[i],Y1[i],a,b) || !inTriunghi(X2[i],Y2[i],a,b) || !inTriunghi(X3[i],Y3[i],a,b)){
                ok=false;
            }
            if(seIntersecteaza(X1[i],Y1[i],X2[i],Y2[i],hx1,hy1,hx2,hy2) || seIntersecteaza(X2[i],Y2[i],X3[i],Y3[i],hx1,hy1,hx2,hy2) || seIntersecteaza(X3[i],Y3[i],X1[i],Y1[i],hx1,hy1,hx2,hy2)){
                ok=false;
            }
            sumaAriix2 += aria2(X1[i],Y1[i],X2[i],Y2[i],X3[i],Y3[i]);
        }
        for(int i = 1; i <= n && ok; i++){
            for(int j = i+1; j <= n && ok; j++){
                if(seIntersecteaza(X1[i],Y1[i],X2[i],Y2[i],X1[j],Y1[j],X2[j],Y2[j])) ok=false;
                if(seIntersecteaza(X1[i],Y1[i],X2[i],Y2[i],X2[j],Y2[j],X3[j],Y3[j])) ok=false;
                if(seIntersecteaza(X1[i],Y1[i],X2[i],Y2[i],X3[j],Y3[j],X1[j],Y1[j])) ok=false;
                if(seIntersecteaza(X2[i],Y2[i],X3[i],Y3[i],X1[j],Y1[j],X2[j],Y2[j])) ok=false;
                if(seIntersecteaza(X2[i],Y2[i],X3[i],Y3[i],X2[j],Y2[j],X3[j],Y3[j])) ok=false;
                if(seIntersecteaza(X2[i],Y2[i],X3[i],Y3[i],X3[j],Y3[j],X1[j],Y1[j])) ok=false;
                if(seIntersecteaza(X3[i],Y3[i],X1[i],Y1[i],X1[j],Y1[j],X2[j],Y2[j])) ok=false;
                if(seIntersecteaza(X3[i],Y3[i],X1[i],Y1[i],X2[j],Y2[j],X3[j],Y3[j])) ok=false;
                if(seIntersecteaza(X3[i],Y3[i],X1[i],Y1[i],X3[j],Y3[j],X1[j],Y1[j])) ok=false;
                if(punctStrictInTriunghi(X1[i],Y1[i],X1[j],Y1[j],X2[j],Y2[j],X3[j],Y3[j])) ok=false;
                if(punctStrictInTriunghi(X2[i],Y2[i],X1[j],Y1[j],X2[j],Y2[j],X3[j],Y3[j])) ok=false;
                if(punctStrictInTriunghi(X3[i],Y3[i],X1[j],Y1[j],X2[j],Y2[j],X3[j],Y3[j])) ok=false;
                if(punctStrictInTriunghi(X1[j],Y1[j],X1[i],Y1[i],X2[i],Y2[i],X3[i],Y3[i])) ok=false;
                if(punctStrictInTriunghi(X2[j],Y2[j],X1[i],Y1[i],X2[i],Y2[i],X3[i],Y3[i])) ok=false;
                if(punctStrictInTriunghi(X3[j],Y3[j],X1[i],Y1[i],X2[i],Y2[i],X3[i],Y3[i])) ok=false;
            }
        }
        if(sumaAriix2!=ariaMarex2){
            ok=false;
        }
        fout<< ok <<'\n';
        k--;
    }
    return 0;
}
