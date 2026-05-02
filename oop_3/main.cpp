#pragma GCC optimize("O1")
class Stiva
{
private:
    // variabile membre
public:
    	int dr = 0;
	int stigu[100004], stigumax[100004];
	// depune valoarea x in stiva
    void Push(int x)
    {
        dr++;
        stigu[dr] = x;
        if(dr == 1){
        	stigumax[dr] = x;
        }else{
	        stigumax[dr] = max(stigumax[dr-1], x);
        }
        // TO DO
    }
    // elimina un element din stiva daca stiva nu e vida
    void Pop()
    {
        if(dr > 0){
        	dr--;
        }
        // TO DO
    }
    // returneaza varful stivei
    // daca stiva este vida, returneaza -1
    int Top()
    {
        if(dr == 0){
        	return -1;
        }
        return stigu[dr];
        // TO DO
    }
    // returneaza valoarea maxima din stiva
    // daca stiva este vida, returneaza -1
    int Max()
    {
        if(dr == 0){
        	return -1;
        }
        return stigumax[dr];
    }
    // returneaza 1 daca stiva este vida
    // returneaza 0 daca stiva nu e vida
    int Empty()
    {
        return dr == 0;
    }
};
