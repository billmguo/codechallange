If the depth of a tree is smaller than 5, then this tree can be represented by a list of three-digits integers.

For each integer in this list:

The hundreds digit represents the depth D of this node, 1 <= D <= 4.
The tens digit represents the position P of this node in the level it belongs to, 1 <= P <= 8. The position is the same as that in a full binary tree.
The units digit represents the value V of this node, 0 <= V <= 9.
Given a list of ascending three-digits integers representing a binary with the depth smaller than 5. You need to return the sum of all paths from the root towards the leaves.

class Solution(object):
    def pathSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
	dmap = {1:0}
	leaves = set{[1]}
	for num in nums:
		path, val = num/10, num%10
		lvl, seq = path/10, path%10
		parent = (lvl - 1)*10 + (seq + 1 )/2
		dmap[path] = dmap[parent] + val
		leaves.add(path)
		if parent in leaves:
			leaves.remove(parent)
	return sum(dmap[v] for v in leaves)
