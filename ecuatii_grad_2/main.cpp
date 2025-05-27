#include <fstream>
#include <string.h>
#include <math.h>
#include <iomanip>
using namespace std;
ifstream fin("ecuatii.in");
ofstream fout("ecuatii.out");
char x[267];
int main(){
    fin.get(x, 256);
    int l = strlen(x);
    bool neg = false;
    int a = 0, b = 0, c = 0;
    int nr = 1, j =0 ;
    if(x[0] == '-'){
        neg = true;
        j++;
    }
    bool este1;
    este1 = true;
    while('0' <= x[j] && x[j] <= '9'){
        a = a*10+x[j]-'0';
        j++;
        este1 =false;
    }
    if(este1){
        a = 1;
    }
    if(neg){
        a = -a;
    }
    j += 3;
    if(x[j] == '-'){
        neg = true;
        j++;
    }else{
        neg = false;
        j++;
    }
    este1 = true;
    while('0' <= x[j] && x[j] <= '9'){
        b = b*10+x[j]-'0';
        j++;
        este1 = false;
    }
    if(este1){
        b = 1;
    }
    if(neg){
        b = -b;
    }
    j++;
    if(x[j] == '-'){
        neg = true;
        j++;
    }else{
        neg = false;
        j++;
    }
    while('0' <= x[j] && x[j] <= '9'){
        c = c*10+x[j]-'0';
        j++;
    }
    if(neg){
        c = -c;
    }
    int delta = b*b-4*a*c;
    if(delta < 0){
        fout << "-1";
    }else if(delta == 0){
        double x = -b;
        x = x/(2*a);
        fout << fixed << setprecision(2) << x;
    }else{
        double sq = sqrt(delta);
        double x = -b-sq;
        x = x/(2*a);
        double xmin = x, xmax = x;
        x = -b+sq;
        x = x/(2*a);
        xmin = min(x, xmin);
        xmax = max(x, xmax);
        fout << fixed << setprecision(2) << xmin << ' ' << xmax;
    }
    return 0;
}
