/*
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

示例 1:
输入: "aba"
输出: True

示例 2:
输入: "abca"
输出: True

解释: 你可以删除c字符。

注意:
字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。
*/

class Solution {
    
    func checkPalindrome(s: [String.Element], low: Int, heig: Int) -> Bool {
        var i = low, j = heig
        while i < j {
            if s[i] != s[j] {
                return false
            }
            i += 1
            j -= 1
        }
        return true
    }
    
    func validPaindrome(s: String) -> Bool {
        let charArr = Array(s)
        var low = 0, heih = charArr.count - 1
        print("\(low) and \(heih)")
        while low < heih {
            // 取出首尾字符串
            let c1 = charArr[low], c2 = charArr[heih]
            if c1 == c2 {
                low += 1
                heih -= 1
            } else {
                return checkPalindrome(s: charArr, low: low, heig: heih - 1) || checkPalindrome(s: charArr, low: low + 1, heig: heih)
            }
        }
        return true
    }
}

let so = Solution()
print(so.validPaindrome(s: "aba"))
