class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        dic={}
        for i in range(len(nums)):
            diff= target-nums[i]
            if diff in dic.keys():
                return [dic[diff],i]
            
            dic[nums[i]]=i
        return [-1, -1]
            
            