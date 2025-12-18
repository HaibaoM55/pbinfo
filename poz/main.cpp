int poz (int x1,int y1,int l1,int i1,int x2,int y2,int l2,int i2){
    if(x1 == x2 && y1 == y2 && l1 == l2 && i1 == i2){
        return 1;
    }else if((x1 + l1 < x2 + l2 && y1 + i1 < y2 + i2 && x1 > x2 && y1 > y2) || (x1 + l1 > x2 + l2 && y1 + i1 > y2 + i2 && x1 < x2 && y1 < y2)){
        return 0;
    }else if((x1 > x2 + l2 || y2 > y1 + i1) || (x2 > x1 + l1 || y1 > y2 + i2)){
        return 2;
    }else{
        return 3;
    }
}
