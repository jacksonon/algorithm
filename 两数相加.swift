import Cocoa

/*
 给出两个非空的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储一位数字。
 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 示例：
 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 输出：7 -> 0 -> 8
 原因：342 + 465 = 807
 */

// 链表
public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
}

/* 何为哑结点(虚节点)？
“是链表中的一个概念,大致意思就是在一个链表的前边添加一个节点,存放位置是数据结点之前,头结点之后。好处就是加入哑结点之后就可以使所有数据结点都有前驱结点,这样就会方便执行链表的一些操作。哑节点的使用可以对代码起到简化作用(省略当函数的入口参数为空时的判断)默认是null.”
*/
class Solution {
    func addTwoNumbers(l1: ListNode?, l2: ListNode?) -> ListNode? {
        let dummpHead = ListNode(0)
        var p = l1, q = l2, curr = dummpHead
        var carry = 0
        while p != nil || q != nil {
            let x = (p != nil) ? p!.val : 0 // 不为nil强制解包
            // let y = (q != nil) ? q!.val : 0
            // 使用 swift if let 解包
            var y = 0
            if let nq = q {
                y = nq.val
            }
            let sum = carry + x + y
            carry = sum / 10 // 计算进位
            curr.next = ListNode(sum % 10)
            curr = curr.next! // curr.next 有值，强制解包
            if let np = p {
                p = np.next
            }
            if let nq = q {
                q = nq.next
            }
        }
        if carry > 0 {
            curr.next = ListNode(carry)
        }
        return dummpHead.next
    }
}

let l1 = ListNode(2)
l1.next = ListNode(4)
l1.next?.next = ListNode(3)

let l2 = ListNode(5)
l2.next = ListNode(6)
l2.next?.next = ListNode(4)

print(l1.val)
print(l2.val)

let so = Solution()
let l3 = so.addTwoNumbers(l1: l1, l2: l2)
print("\(l3?.val), \(l3?.next?.val), \(l3?.next?.next?.val)")
print(so.addTwoNumbers(l1: l1, l2: l2)!.val)

