struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // Create dummy node to handle edge cases easily
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;

    struct ListNode *fast = &dummy;
    struct ListNode *slow = &dummy;

    // Advance fast pointer by n + 1 steps
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    // Move fast to the end, maintaining the gap of (n + 1)
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // Delete the nth node from the end
    struct ListNode *nodeToDelete = slow->next;
    slow->next = slow->next->next;
    free(nodeToDelete);

    return dummy.next;
}