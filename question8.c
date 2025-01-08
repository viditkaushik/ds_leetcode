struct ListNode* reverseLinkedList(struct ListNode* head, int k) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;
    int count = 0;

    while (curr != NULL && count < k) {
        next = curr->next;  
        curr->next = prev;  
        prev = curr;        
        curr = next;
        count++;
    }
    return prev;
}
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;  
    struct ListNode *groupPrev = dummy;
    
    while (groupPrev->next != NULL) {
        struct ListNode* groupEnd = groupPrev;
        for (int i = 0; i < k && groupEnd != NULL; i++) {
            groupEnd = groupEnd->next;
        }
        
        if (groupEnd == NULL) {
            break;  
        }
        struct ListNode* groupStart = groupPrev->next;
        struct ListNode* nextGroupStart = groupEnd->next;
        groupEnd->next = NULL;
        
        struct ListNode* reversedGroup = reverseLinkedList(groupStart, k);
        groupPrev->next = reversedGroup;
        
        groupStart->next = nextGroupStart;
        
        groupPrev = groupStart;
    }
    
    struct ListNode* result = dummy->next;
    free(dummy);  
    return result;
}
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}
void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}
