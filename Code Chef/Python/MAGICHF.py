t=input()
t=int(t)
for case in range(t):
    nxs=input()
    n,x,s=int(nxs.split(" ")[0]),int(nxs.split(" ")[1]),int(nxs.split(" ")[2])
    l=[0]*n
    l[x-1]=1
    for i in range(s):
        ab=input()
        a,b=int(ab.split(" ")[0]),int(ab.split(" ")[1])
        l[a-1],l[b-1]=l[b-1],l[a-1]
    print(l.index(1)+1)

