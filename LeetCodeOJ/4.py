class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        m = len(nums1)
        n = len(nums2)
        if((m + n)%2 == 1):
            return self.find_k(nums1, nums2, (m+n+1)/2)
        else:
            return (self.find_k(nums1, nums2, (m+n)/2) + self.find_k(nums1, nums2, (m+n)/2+1))/2.0

    def find_k(self, nums1, nums2, k):
        a = 0
        b = 0
        c = 0
        k_value = 0.0
        while(a < len(nums1) and b < len(nums2) and c < k):
            if nums1[a] < nums2[b]:
                k_value = nums1[a]
                a += 1
            else:
                k_value = nums2[b]
                b += 1
            c += 1
        if c == k:
            return k_value
        elif a == len(nums1):
            while(b < len(nums2) and c < k):
                k_value = nums2[b]
                b += 1
                c += 1
            return k_value
        elif b == len(nums2):
            while(a < len(nums1) and c < k):
                k_value = nums1[a]
                a += 1
                c += 1
            return k_value

class Solution2:
    def findMedianSortedArrays(self, A, B):
        """
        Merge two arrays to get the median, O((m+n)/2)
        Algorithm: Find k-th element in 2 array
        A: A_left A[m/2] A_right
        B: B_left B[n/2] A_right
        if A[m/2]>B[n/2] and k>m/2+n/2, then disregard B_left and B[n/2]
        if A[m/2]>B[n/2] and k<=m/2+n/2, then disregard A_right and A[m/2]
        if A[m/2]<=B[n/2] and k>m/2+n/2, then disregard A_left and A[m/2]
        if A[m/2]<=B[n/2] and k<=m/2+n/2, then disregard B_right and B[n/2]
        whether to disregard A[m/2] or B[n/2] takes time to consider

        T(N) = T(3/4 N) + O(1), thus T(N) = O(lg N) where N = |A|+|B|
        O(log (m+n)), thus binary search.
        :param A: list
        :param B: list
        :return: float
        """
        m = len(A)
        n = len(B)
        if ((m+n)&1 == 0):
            return (self.find_kth(A, B, (m+n)/2)+self.find_kth(A, B, (m+n)/2-1))/2.0
        else:
            return self.find_kth(A, B, (m+n)/2)

    def find_kth(self, A, B, k):
        """
        :param A:
        :param B:
        :param k: index starting from 0
        :return:
        """
        if not A:  return B[k]
        if not B:  return A[k]
        if k == 0: return min(A[0], B[0])

        m, n = len(A), len(B)
        # pay attention to consider the equal sign. Assigning equal sign is an art.
        if A[m/2] >= B[n/2]:
            if k > m/2+n/2:
                return self.find_kth(A, B[n/2+1:], k-n/2-1)  # exclude B[n/2] to make progress
            else:
                return self.find_kth(A[:m/2], B, k)  # exclude A[m/2] to make progress
        else:
            return self.find_kth(B, A, k)
