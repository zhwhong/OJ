def mergesort(arr):
    """
    time: n lg(n)
    space: n
    """
    def merge(a1, a2):
        l1, l2 = len(a1), len(a2)

        if l1 * l2 == 0:
            return a1 or a2
        else:
            if a1[0] <= a2[0]:
                return a1[:1] + merge(a1[1:], a2)
            else:
                return a2[:1] + merge(a1, a2[1:])
    if len(arr) <= 1:
        return arr
    else:
        mid = len(arr) // 2

        return merge(mergesort(arr[:mid]), mergesort(arr[mid:]))


def quicksort(arr, start, end):
    """
    start, end is inclusive. you need to perform swap
    inplace sorting

    time: n^2, but n lg n in average
    space: 1
    """
    def partition(arr, start, end):
        '''choose end as pivot'''
        p = start - 1  # p is the collection boarder line
        for i in range(start, end):
            if arr[i] < arr[end]:  # only collect smaller items
                p += 1
                arr[i], arr[p] = arr[p], arr[i]
        arr[p + 1], arr[end] = arr[end], arr[p + 1]
        return p + 1

    if start >= end:  # recusion ending condition
        return
    else:
        p = partition(arr, start, end)
        quicksort(arr, start, p - 1)
        quicksort(arr, p + 1, end)


def insertion_sort(arr):
    if len(arr) <= 1:
        return arr

    for i in range(1, len(arr)):
        for j in reversed(range(i)):
            if arr[j] > arr[j + 1]:
                arr[j + 1], arr[j] = arr[j], arr[j + 1]
            else:
                break


def counting_sort(arr, k):
    """
    you need to make buckets
    so the assumption here is every number in arr is belong to 0 <= int <= k

    time: n + k
    space: n + k
    """

    bucket = [0] * (k + 1)  # 0 included

    for num in arr:
        bucket[num] += 1

    res = []
    for i, cnt in enumerate(bucket):
        res.extend([i] * cnt)

    return res
