class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        ans=[]
        l=len(nums)
        ans=[0] * 2 * l
        for i in range(len(nums)):
            ans[i]=nums[i]
            ans[i+l]=nums[i]
        return ans
        