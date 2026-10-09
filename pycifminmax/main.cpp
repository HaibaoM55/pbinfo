def CifMinMax(a):
    s = 0
    minim = 10
    maxim = 0
    if(a == 0):
        return 0,0
    while(a > 0):
        maxim = max(maxim, a%10)
        minim = min(minim, a%10);
        a = a//10
    return minim, maxim
