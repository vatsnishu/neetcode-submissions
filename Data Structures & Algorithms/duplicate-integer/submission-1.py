class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
     
        unique=[]
        for i in range(len(nums)):
            if nums[i] in unique:
                return True 
            
            unique.append(nums[i])
        return False if len(unique)==len(nums) else True 