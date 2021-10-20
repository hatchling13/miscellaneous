def heap(A, n):
    build_heap(A, n)

    i = n

    while i >= 1:
        temp = A[0]
        A[0] = A[i]
        A[i] = temp

        heapify(A, 0, i - 1)
        i -= 1

def build_heap(A, n):
    i = n // 2

    while i >= 0:
        heapify(A, i, n)
        i -= 1

def heapify(A, k, n):
    left = 2 * k + 1
    right = 2 * k + 2

    smaller = 0

    if right <= n:
        if A[left] < A[right]:
            smaller = left
        else:
            smaller = right

    elif left <= n:
        smaller = left

    else:
        return

    if A[smaller] < A[k]:
        temp = A[smaller]
        A[smaller] = A[k]
        A[k] = temp

        heapify(A, smaller, n)

A = input().split()
A = list(map(int, A))

heap(A, len(A) - 1)
print(A)