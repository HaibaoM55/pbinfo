def CifMax(a):
    s = 0
    while(a > 0):
        s = max(s, a%10) 
        a = a//10
    return s
