#include <algorithm>
void ordonare(int a[], int n){
	sort(a, a+n);
    int z = n-1;
    for(int i = 0; i <= z; i++){
    	swap(a[i], a[z]);
        z--;
    }
}
