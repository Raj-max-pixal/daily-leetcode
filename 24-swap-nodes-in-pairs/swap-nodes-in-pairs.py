# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def swapPairs(self, head: ListNode | None) -> ListNode | None:
        # Create a dummy node to act as the predecessor of the head
        dummy = ListNode(0, head)
        prev = dummy
        
        while prev.next and prev.next.next:
            # Identify the two nodes to swap
            first = prev.next
            second = prev.next.next
            
            # Reversing / Swapping the pointers
            first.next = second.next
            second.next = first
            prev.next = second
            
            # Move the prev pointer forward by two nodes for the next pair
            prev = first
            
        return dummy.next