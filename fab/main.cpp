#include <map>
int FAB(int a[],int n,int b[], int m){
    map<int, int> f;
    for(int i = 1; i <= n; i++){
    	f[a[i]]=i;
    }
    for(int k = 1; k <= m; k++){
    	bool ok = false;
        for(int i = 1; i <= n; i++){
            if(f[b[k]-a[i]] != 0 && f[b[k]-a[i]] != i){
            	ok = true;
                break;
            }
        }
        if(!ok){
        	return 0;
        }
    }
    return 1;
}
