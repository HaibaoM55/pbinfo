int PalRec(int a[], int st, int dr){
    if(st > dr){
    	return 1;
    }
	return (a[st]==a[dr])&&PalRec(a, st+1, dr-1);
}
