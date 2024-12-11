
f = open("input.txt")
l1,l2 = [],[]
for line in f:
    a,b = map(int, line.split('   '))
    l1.append(a)
    l2.append(b)

l1.sort()
l2.sort()
s = 0
for i in range(len(l1)):
    s+=abs(l1[i]-l2[i])
print(s)
