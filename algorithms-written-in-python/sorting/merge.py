def merge_sort(A, p, r):
    if p < r:
        q = (p + r) // 2
        merge_sort(A, p, q)
        merge_sort(A, q + 1, r)
        merge(A, p, q, r)

def merge(A, p, q, r):
    i = p
    j = q + 1
    
    result = list()

    while i <= q and j <= r:
        if (A[i] <= A[j]):
            result.append(A[i])
            i += 1
        else:
            result.append(A[j])
            j += 1

    while i <= q:
        result.append(A[i])
        i += 1

    while j <= r:
        result.append(A[j])
        j += 1

    k = p

    for l in result:
        A[p] = l
        p += 1

def start():
    C = input('Input numbers for C : ').split()
    C = list(map(int, C))
    
    D = input('Input numbers for D : ').split()
    D = list(map(int, D))
    
    A = C + D

    s = bool(int(input('Normal process = 0, Abnormal process = 1 : ')))
    
    if s:
        p = int(input('start : '))
        r = int(input('end : '))
    
    else:
        p = 0
        r = len(A) - 1

    merge_sort(A, p, r)
    
    print(A)

i = int(input('How many time : '))

for x in range(0, i):
    start()