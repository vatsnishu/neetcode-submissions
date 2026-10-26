# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# class Solution:
#     def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
#         q=collections.deque()
#         q.append(root)
#         arr=[]
        
#         while len(q):
            
#             for i in range(len(q)):
#                 curr=q.popleft()
#                 if curr:
#                     if curr.left:
#                         q.append(curr.left)
#                     if curr.right:
#                         q.append(curr.right)
     
#             if curr:
#                 arr.append(curr.right.val)
#         return arr

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        q = deque([root])

        while q:
            rightSide = None
            qLen = len(q)

            for i in range(qLen):
                node = q.popleft()
                if node:
                    rightSide = node
                    q.append(node.left)
                    q.append(node.right)
            if rightSide:
                res.append(rightSide.val)
        return res