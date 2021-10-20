def bubble(A, n):
    i = n

    while i >= 2:
        j = 0

        while j < i:
            if A[j] > A[j + 1]:
                temp = A[j]
                A[j] = A[j + 1]
                A[j + 1] = temp
            
            j += 1
            
        i -= 1

A = input().split()
A = list(map(int, A))

bubble(A, len(A) - 1)
print(A)