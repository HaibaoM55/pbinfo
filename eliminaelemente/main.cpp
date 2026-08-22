#include <algorithm>
int EliminaElemente(int a[], int n, int m){
	int f[1004];
    for(int i = 0; i <= 1000; i++){
    	f[i] = 0;
    }
    for(int i = 0; i < n; i++){
    	f[a[i]]++;
    }
    sort(f, f+1001);
    for(int i = 0; i <= 1000; i++){
        if(f[i] > m){
        	break;
        }else{
            m -= f[i];
        	f[i] = 0;
        }
    }
    int rasp = 0;
    for(int i = 0; i <= 1000; i++){
        if(f[i]){
        	rasp++;
        }
    }
    return rasp;
}
