int Max()
{
    int vmax = t[0];
    for(int i = 1; i < n; i++){
    	vmax = max(vmax, t[i]);
    }
    return vmax;
}
// returneaza prima pozitie unde se gaseste val in t,
// sau returneaza -1 daca val nu apare in t
int Cauta(int val)
{
    for(int i = 0; i < n; i++){
        if(t[i] == val){
        	return i;
        }
    }
    return -1;
}
