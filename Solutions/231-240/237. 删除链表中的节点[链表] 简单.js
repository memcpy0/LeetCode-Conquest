/*
** Problem: https://leetcode-cn.com/problems/delete-node-in-a-linked-list/
** Article: https://memcpy0.blog.csdn.net/article/details/108183127
** Author: memcpy0
*/
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} node
 * @return {void} Do not return anything, modify node in-place instead.
 */
 var deleteNode = function(node) {
    node.val = node.next.val;
    node.next = node.next.next;
};