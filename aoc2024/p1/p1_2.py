f = open("input.txt")
l1,l2 = [],[]
for line in f:
    a,b = map(int, line.split('   '))
    l1.append(a)
    l2.append(b)

l1.sort()
l2.sort()
s = 0
p_a = 0
p_b = 0
s_in=0
repeat_count=1
while(p_a < len(l1) and p_b < len(l2)):
    if p_a > 0 and l1[p_a -1] == l1[p_a]:
        repeat_count += 1
        p_a+=1
        continue
    else:
        s += s_in * repeat_count
        repeat_count = 1
        s_in = 0

    while  p_b < len(l2) and l1[p_a] >= l2[p_b]:
        if l1[p_a] == l2[p_b]:
            s_in += l1[p_a]
        p_b += 1
    p_a += 1 
if s_in != 0:
    s += s_in * repeat_count
print(s)
