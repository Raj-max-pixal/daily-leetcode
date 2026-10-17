# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseKGroup(self, head: ListNode | None, k: int) -> ListNode | None:
        # Check if there are at least k nodes left in the linked list
        curr = head
        count = 0
        while curr and count < k:
            curr = curr.next
            count += 1
            
        # If less than k nodes remain, return head as-is
        if count < k:
            return head
        
        # Reverse the first k nodes
        prev = None
        curr = head
        for _ in range(k):
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
            
        # 'head' is now the tail of the reversed group; connect it to the recursive result
        head.next = self.reverseKGroup(curr, k)
        
        # 'prev' is the new head of this reversed group
        return prev