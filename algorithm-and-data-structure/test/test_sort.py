import sort
import random


def get_random_arr(n):
    return [random.randint(0, 100) for _ in range(n)]


def test_merge_sort():
    for _ in range(500):
        r = random.randint(0, 100)
        arr = get_random_arr(r)
        assert sort.mergesort(arr) == sorted(arr)


def test_quicksort():
    for _ in range(500):
        r = random.randint(0, 100)
        arr = get_random_arr(r)
        arr_copy = arr[:]

        sort.quicksort(arr, 0, len(arr) - 1)
        assert arr == sorted(arr_copy)


def test_insertion_sort():
    for _ in range(500):
        r = random.randint(0, 100)
        arr = get_random_arr(r)
        arr_copy = arr[:]

        sort.insertion_sort(arr)
        assert arr == sorted(arr_copy)


def test_counting_sort():
    for _ in range(500):
        r = random.randint(0, 100)
        arr = get_random_arr(r)
        assert sort.counting_sort(arr, 100) == sorted(arr)
