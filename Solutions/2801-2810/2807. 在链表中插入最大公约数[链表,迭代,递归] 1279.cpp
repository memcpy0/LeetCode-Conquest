/*
** Problem: https://leetcode.cn/problems/insert-greatest-common-divisors-in-linked-list/
** Article: https://memcpy0.blog.csdn.net/article/details/135435050
** Author: memcpy0
*/
// cpp
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        for (auto cur = head; cur->next; cur = cur->next->next)
            cur->next = new ListNode(gcd(cur->val, cur->next->val), cur->next);
        return head;
    }
};
// java
class Solution {
    public ListNode insertGreatestCommonDivisors(ListNode head) {
        for (ListNode cur = head; cur.next != null; cur = cur.next.next) {
            cur.next = new ListNode(gcd(cur.val, cur.next.val), cur.next);
        }
        return head;
    }
    private int gcd(int a, int b) { 
        while (a != 0) {
            int t = a;
            a = b % a;
            b = t;
        }
        return b;
    }
}
// python
class Solution:
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cur = head
        while cur.next:
            cur.next = ListNode(gcd(cur.val, cur.next.val), cur.next)
            cur = cur.next.next
        return head
// go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func insertGreatestCommonDivisors(head *ListNode) *ListNode {
    for cur := head; cur.Next != nil; cur = cur.Next.Next {
        cur.Next = &ListNode{gcd(cur.Val, cur.Next.Val), cur.Next}
    }
    return head
}
func gcd(a, b int) int {
    for a != 0 {
        a, b = b % a, a
    }
    return b
}
// rust
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn insert_greatest_common_divisors(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut cur = &mut head;
        while cur.as_ref().unwrap().next.is_some() {
            let x = cur.as_mut().unwrap();
            let next = x.next.take();
            x.next = Some(Box::new(ListNode {
                val: Self::gcd(x.val, next.as_ref().unwrap().val),
                next,
            }));
            cur = &mut cur.as_mut().unwrap().next.as_mut().unwrap().next;
        }
        head
    }
    fn gcd(mut a: i32, mut b: i32) -> i32 {
        while a != 0 {
            (a, b) = (b % a, a);
        }
        b
    }
}