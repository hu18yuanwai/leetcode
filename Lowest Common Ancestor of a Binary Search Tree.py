class TreeNode(object):
	def __init__(self, x):
		self.val = x
        self.left = None
        self.right = None

def maxNode(p,q):
	if p.val>q.val:
		return p.val
	return q.val


def minNode(p,q):
	if p.val<q.val:
		return p.val
	return q.val


class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
    	if root==None or p==None or q==None:
    		return None
    	elif root.val<maxNode(p,q) and root.val>minNode(p,q):
    		return root
    	elif root.val>maxNode(p,q):
    		return self.lowestCommonAncestor(root.left,p,q)
    	elif root.val<minNode(p,q):
    		return self.lowestCommonAncestor(root.right,p,q)
    	elif root.val==p.val:
    		return p
    	elif root.val==q.val:
    		return q