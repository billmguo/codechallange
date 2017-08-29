class TreeNode(object):
     def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None

class Solution(object):
    def printTree(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[str]]
        """
        self.height = self.getmaxdepth(root)
        self.width = (1<<self.height) - 1
        self.dmap = [[""] * self.width for x in range(self.height)]
        self.dfs(root,1, self.width >> 1)
    def getmaxdepth(self, root):
        if not root: return 0
        return 1 + max(self.getmaxdepth(self,root.left),self.getmaxdepth(self,root.right))
    def dfs(self, root, depth, offset):
        if not root: return
        self.dmap[depth - 1][offset] = str(root.val)
        gap = 1 + self.width >> (depth + 1)
        self.dfs(root.left, depth + 1 , offset - gap)
        self.dfs(root.right, depth +1 , offset + gap)
