/*
给你一个字符串 s ，请你返回满足以下条件的最长子字符串的长度：每个元音字母，即 'a'，'e'，'i'，'o'，'u' ，在子字符串中都恰好出现了偶数次。
示例 1：
输入：s = "eleetminicoworoep"
输出：13
解释：最长子字符串是 "leetminicowor" ，它包含 e，i，o 各 2 个，以及 0 个 a，u 。
示例 2：
输入：s = "leetcodeisgreat"
输出：5
解释：最长子字符串是 "leetc" ，其中包含 2 个 e 。
示例 3：
输入：s = "bcbcbc"
输出：6
解释：这个示例中，字符串 "bcbcbc" 本身就是最长的，因为所有的元音 a，e，i，o，u 都出现了 0 次。

提示：
1 <= s.length <= 5 x 10^5
s 只包含小写英文字母。
*/

/* 前缀和是一个数组的某项下标之前(包括此项元素)的所有数组元素的和。
一维前缀和递推式 b[i]=b[i-1]+a[i]
二维前缀和递推式  b[x][y] = b[x-1][y] + b[x][y-1] + b[x-1][y-1] + a[x][y]
*/

// 核心解题思想：对于一个区间，我们可以用两个前缀和的差值，得到其中某个字母的出现次数。优化统计子串的时间复杂度

class Solution {
    func findTheLongestSubstring(_ s: String) -> Int {
        let cs = Array(s)
        var ans = 0, status = 0, n = cs.count
        var pos = [Int]()
        pos.append(0)
        for _ in 1..<1 << 5 {
            pos.append(-1)
        }
        for i in 0..<n {
            if cs[i] == "a" {
                status ^= 1 << 0 // 1
            } else if cs[i] == "e" {
                status ^= 1 << 1 // 2
            } else if cs[i] == "i" {
                status ^= 1 << 2 // 4
            } else if cs[i] == "o" {
                status ^= 1 << 3 // 8
            } else if cs[i] == "u" {
                status ^= 1 << 4 // 16
            }
            if ~pos[status] < 0 {
                ans = max(ans, i + 1 - pos[status])
            } else {
                // 整个字符串区间都符合规则
                pos[status] = i + 1
            }
        }
        return ans
    }
}

let s = "eleetminicoworoep"
let so = Solution()
print(so.findTheLongestSubstring(s))
