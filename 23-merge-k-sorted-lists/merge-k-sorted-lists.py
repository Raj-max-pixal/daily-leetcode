import heapq

class Solution:
    def mergeKLists(self, lists: list[Optional[ListNode]]) -> Optional[ListNode]:
        min_heap = []
        
        # Push the first node of each list into the heap
        for i, l in enumerate(lists):
            if l:
                # Store (value, index, node) to handle tie-breaking cleanly
                heapq.heappush(min_heap, (l.val, i, l))
                
        dummy = ListNode(0)
        curr = dummy
        
        while min_heap:
            val, i, node = heapq.heappop(min_heap)
            curr.next = node
            curr = curr.next
            
            if node.next:
                heapq.heappush(min_heap, (node.next.val, i, node.next))
                
        return dummy.next