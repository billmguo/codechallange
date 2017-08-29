class Solution(object):
    def findClosestElements(self, arr, k, x):
        """
        :type arr: List[int]
        :type k: int
        :type x: int
        :rtype: List[int]
        """
        arr.sort(key=lambda t:abs(t-x))
        print arr
        print arr[:k]
        return sorted(arr[:k])

lista = [1,2,3,4,5]
print Solution().findClosestElements(lista,3,3)
