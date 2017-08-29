class Solution(object):
    def isPossible(self, nums):
        # Time: O(n^2)
        # Space: O(n)
        seqs = {num: [] for num in nums}
        print seqs
        for num in nums:
            shortest_seq = 0
            if num - 1 in seqs and seqs[num - 1]:
                shortest_seq = min(seqs[num - 1])
                seqs[num - 1].remove(shortest_seq)
                print seqs
            seqs[num].append(shortest_seq + 1)
            print seqs
        for seq_lengths in seqs.values():
            if seq_lengths and min(seq_lengths) < 3:
                return False
        return True
lista = [1,2,3,3,4,4,5,5]
print Solution().isPossible(lista)
