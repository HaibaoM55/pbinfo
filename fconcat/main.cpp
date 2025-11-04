void FConcat(char s[], char d[]){
	int l1 = 0;
    while(s[l1] != 0){
    	l1++;
    }
    for(int i = 0; d[i] != 0; i++){
    	s[l1+i]=d[i];
        s[l1+i+1]=0;
    }
}
