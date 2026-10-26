# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        q=collections.deque()
        q = deque([root])
        arr=[]
        
        while len(q):
            
            for i in range(len(q)):
                curr=q.popleft()
                if curr:
                    if curr.left:
                        q.append(curr.left)
                    if curr.right:
                        q.append(curr.right)
     
            if curr:
                arr.append(curr.val)
        return arr

