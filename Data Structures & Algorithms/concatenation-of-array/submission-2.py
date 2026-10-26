class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        l= len(nums) 
        ans= 2 * l * [0]
        for i in range(len(nums)):
            ans[i]=nums[i]
            ans[i+l]=nums[i]
        return ans 
