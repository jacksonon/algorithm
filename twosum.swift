import Cocoa

//给定 nums = [2, 7, 11, 15], target = 9
//
//因为 nums[0] + nums[1] = 2 + 7 = 9
//所以返回 [0, 1]


// 暴力破解
class Solution {
    public func twoSum(nums:[Int], target: Int) -> [Int] {
        for j in 0...nums.count {
            for k in 1...(nums.count - 1) {
                if nums[k] == target - nums[j]  {
                    return [j, k];
                }
            }
        }
        return []
    }
}

let nums = [2, 7, 11, 15]
let target = 9
let so = Solution()
print(so.twoSum(nums: nums, target: target))
