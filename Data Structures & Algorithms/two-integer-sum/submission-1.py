class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        dic={}
        out=[]
        for i in range(len(nums)):
            diff=target-nums[i]

            if diff not in dic:
                dic[nums[i]]=i
            else:
                out.append(dic[diff])
                out.append(i)
                return out

        return [-1, -1]