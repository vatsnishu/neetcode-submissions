class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        place_index=0
        for i in range(len(nums)):

            
            if nums[i]!=nums[place_index]:

                nums[place_index+1]=nums[i]
                place_index=place_index+1
         

        return place_index+1

