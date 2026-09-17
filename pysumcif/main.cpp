def SumCif(a):
    s = 0
    while(a > 0):
        s += a%10 
        a = a//10
    return s
