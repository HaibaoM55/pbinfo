int NrXDivImp(int a[], int st, int dr, int x){
   if (st == dr){
       if(a[st] == x){
            return 1;
       }else{
            return 0;
       }
   }
   int mij = (st+dr)/2;
   return NrXDivImp(a, st, mij, x) + NrXDivImp(a, mij+1, dr, x);
}
