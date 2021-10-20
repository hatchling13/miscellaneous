def quick(A, p, r):
    if p < r:
        q = partition(A, p, r)
        quick(A, p, q - 1)
        quick(A, q + 1, r)

def partition(A, p, r):
    a = A[r]
    i = p - 1
    j = p

    while j < r:
        if A[j] <= a:
            i += 1
            temp = A[i]
            A[i] = A[j]
            A[j] = temp
        
        j += 1

    temp = A[i + 1]
    A[i + 1] = A[r]
    A[r] = temp

    return i + 1
    

A = input().split()
A = list(map(int, A))

quick(A, 0, len(A) - 1)
print(A)