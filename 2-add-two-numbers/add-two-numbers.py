class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        # Create a "dummy" head to start our new list
        dummy = ListNode(0)
        current = dummy
        carry = 0
        
        # Keep going as long as there are nodes to add OR a carry left
        while l1 or l2 or carry:
            # Get the values, or 0 if we reached the end of a list
            v1 = l1.val if l1 else 0
            v2 = l2.val if l2 else 0
            
            # Add digits and the carry
            total = v1 + v2 + carry
            carry = total // 10  # This gets the tens digit (the carry)
            new_digit = total % 10 # This gets the ones digit
            
            # Add the new digit to our results list
            current.next = ListNode(new_digit)
            current = current.next
            
            # Move to the next nodes if they exist
            if l1: l1 = l1.next
            if l2: l2 = l2.next
            
        return dummy.next