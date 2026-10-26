# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        level=0
        q=collections.deque()
        q.append(root)
        marr=[]
        while len(q)>0:

            narr=[]
            for i in range(len(q)):
                curr= q.popleft()
                if curr:
                    narr.append(curr.val)
                    q.append(curr.left)
                    q.append(curr.right)
                level=level+1   
            if narr:
                marr.append(narr)
        
        return marr

        