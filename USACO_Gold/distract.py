def answer(banana_list):
   

def cycles(a, b):
    # Returns True if a and b will cycle indefinitely
    (a,b) = maximin(a,b) #make a the max
    (c,d) = maximin(a-b, a+b)
    while ((c,d) != (a,b) | c != d):
        (c,d) = maximin(c-d,c+d)
    if (c == d):
        return False
    else :
        return True 

def maximin(a,b):
    #Returns (a,b) if a > b, and (b,a) if a < b
    if a > b:
        return (a,b)
    else :
        return (b,a)

a = input("Give a,b ")
a.split(" ")
print(cycles(int(a[0]),int(a[1])))
