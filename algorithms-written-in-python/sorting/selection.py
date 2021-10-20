def selection(A, n):
    i = n

    while i >= 2:
        a = 0
        j = 0
        k = 0

        while j <= i:
            if a < A[j]:
                a = A[j]
                k = j
            j += 1
            
        temp = A[i]
        A[i] = A[k]
        A[k] = temp
        i -= 1
        j = 0

A = input().split()
A = list(map(int, A))

selection(A, len(A) - 1)
print(A)