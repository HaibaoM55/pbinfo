int oglindit(int x){
    int rasp = 0;
    do{
        rasp = rasp*10+x%10;
        x = x/10;
    }while(x > 0);
    return rasp;
}
