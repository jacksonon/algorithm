/*
 给出两个非空的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储一位数字。
 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 示例：
 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 输出：7 -> 0 -> 8
 原因：342 + 465 = 807
 */

class ListNode {
    public var val: Int
    // 结构体不能有存储属性
    public var next: ListNode?
    public init(val: Int) {
        self.val = val
        self.next = nil
    }
}

class Solution {
    func addTwoNumbers(l1: ListNode?, l2: ListNode?) -> ListNode? {
        return nil
    }
}
