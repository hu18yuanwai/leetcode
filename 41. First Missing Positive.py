class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)==0:
            return 1
        for i in range(len(nums)):
            nums[i]=nums[i]-1

        for i in range(len(nums)):
            while nums[i]!=i and nums[i]>=0 and nums[i]<len(nums) and nums[i]!=nums[nums[i]]:
                temp=nums[i]
                nums[i]=nums[temp]
                nums[temp]=temp;

        for i in range(len(nums)):
            if nums[i]!=i:
                return i+1

        return len(nums)+1
