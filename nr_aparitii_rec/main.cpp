#include <string>
unsigned nr_aparitii(char *sir, char *secventa){
	string sirs = sir;
    string secv = secventa;
    int l = sirs.size();
    int l1 = secv.size();
    int nr = 0;
    for(int i = 0; i < l-l1+1; i++){
        if(sirs.substr(i, l1) == secv){
        	nr++;
        }
    }
    return nr;
}
