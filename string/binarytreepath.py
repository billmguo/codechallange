def binarytreepath(self,node,path,res):
	if node is None
		return;
	if node.left is node.right is None:
		ans=""
		for n in path:
			ans += str(n.val) + "->"
		res.append(ans + str(node.val))
	
	if node.left:
		path.append(node)
		self.binarytreepath(node.left,path,res)
		path.pop();

	if node.right
		path.append(node)
		self.binarytreepath(node.right,path,res)
		path.pop()
