int ExistaImpareRec(int x){
    if(x == 0) return 0;
	return (x%2==1) || ExistaImpareRec(x/10);
}
