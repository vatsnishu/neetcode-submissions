class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i=0
        j=0
        for i in range(len(nums)):
            if nums[i]!=nums[j]:
                nums[j+1]=nums[i]
                j=j+1
        return j+1

            