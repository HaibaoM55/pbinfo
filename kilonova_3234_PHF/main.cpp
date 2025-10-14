#include <iostream>
#include <math.h>
using namespace std;
int n, m, indice, nb, lg;
char c[1000004], x;
struct box{
	char p,h,f;
}vbox[1002];
char comparatie(char x, char y){
    if(x == y){
        return x;
    }
    if(x == 'P'){
        if(y == 'H') return 'H';
        if(y == 'F') return 'P';
    }
    if(x == 'H'){
        if(y == 'P') return 'H';
        if(y == 'F') return 'F';
    }
    if(x == 'F'){
        if(y == 'P') return 'P';
        if(y == 'H') return 'F';
    }
}
char solve(int k, char y){
	int a=(k-1)*lg+2, b=k*lg+1;
	if(k==nb)b=n;
	char x=y;
	for(int i=a;i<=b;i++){
		x=comparatie(x,c[i]);
	}
	return x;
}
char solve2(){
	char y=c[1];
	for(int k=1;k<=nb;k++){
		if(y=='P')y=vbox[k].p;
		else if(y=='H')y=vbox[k].h;
		else y=vbox[k].f;
	}
	return y;
}

int main(){
    cin >> n >> m;
	lg=sqrt(n);
	nb=(n-1+lg-1)/lg;
	//cutia 1: 2..lg+1, cutia 2: lg+2..2*lg+1, ..., cutia r: (r-1)*lg+2..r*lg+1,...
    cin >> (c+1);
	for(int k=1;k<=nb;k++){
		vbox[k].p=solve(k,'P');
		vbox[k].h=solve(k,'H');
		vbox[k].f=solve(k,'F');
	}
	char z = solve2();
	cout << z;
    for(int i = 1; i <= m; i++){
        cin >> indice >> x;
		if(c[indice]==x){
			cout << z;
			continue;
		}
		c[indice]=x;
		if(indice>=2){
			int k=(indice-2)/lg+1;
            vbox[k].p=solve(k,'P');
            vbox[k].h=solve(k,'H');
            vbox[k].f=solve(k,'F');
		}
		z=solve2();
		cout << z;
    }
    return 0;
}
