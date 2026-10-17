class Solution:
    def singleNumber(self, nums: list[int]) -> int:
        ones=00
        twos=00
        for num in nums:
            ones=(num^ones)&~twos
            twos=(num^twos)&~ones

        return ones
        