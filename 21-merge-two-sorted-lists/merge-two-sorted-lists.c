struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // Create a dummy node to act as the start of the merged list
    struct ListNode dummy;
    dummy.next = NULL;
    
    // Pointer to track the tail of the merged list
    struct ListNode *tail = &dummy;

    // Traverse both lists and attach the smaller value node to tail
    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Attach any remaining nodes from list1 or list2
    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    // Return the merged list starting after the dummy head
    return dummy.next;
}