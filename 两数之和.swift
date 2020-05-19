import Cocoa

// 题目
//给定 nums = [2, 7, 11, 15], target = 9
//
//因为 nums[0] + nums[1] = 2 + 7 = 9
//所以返回 [0, 1]

class Solution {
    // 暴力破解
    public func twoSum(nums:[Int], target: Int) -> [Int] {
        for i in 0...(nums.count - 1) {
            for j in (i + 1)...(nums.count - 1) {
                if nums[j] == target - nums[i]  {
                    return [i, j];
                }
            }
        }
        return []
    }
    
    // 两边哈希表：更有效的方法检查数组中是否存在目标元素。
    public func twoSumTwoHash(nums:[Int], target: Int) -> [Int] {
        var map = [Int: Int]()
        // 将目标存储到map中
        for index in 0...(nums.count - 1){
            // key存的是值，value存的是位置
            map[nums[index]] = index
        }
        // 再次遍历寻找
        for index in 0...(nums.count - 1) {
            // 计算目标值是多少
            let complement = target - nums[index]
            // 在map中搜索目标值 且 目标值位置不与当前位置相等
            if map.keys.contains(complement) && map[complement] != index {
                if let uc = map[complement] {
                    return [index, uc]
                }
            }
            
        }
        return []
    }
    
    // 一遍哈希表，边存边对比
    public func twoSumOneHash(nums:[Int], target: Int) -> [Int] {
        var map = [Int: Int]()
        for i in 0...nums.count-1 {
            let complement = target - nums[i]
            if map.keys.contains(complement) {
                if let comIndex = map[complement] {
                    return [comIndex, i]
                }
            }
            map[nums[i]] = i
        }
        return []
    }
}

// 在swift中如何通过value寻找key的扩展
//extension Dictionary where Value: Equatable {
//    func someKey(forValue val: Value) -> Key? {
//        return first(where: {$1 == val})?.key
//    }
//}

let nums = [2, 5, 5, 11]
let target = 10
let so = Solution()
print(so.twoSum(nums: nums, target: target))
print(so.twoSumTwoHash(nums: nums, target: target))
print(so.twoSumOneHash(nums: nums, target: target))
