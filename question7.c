struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;
    
    while (curr != NULL) {
        next = curr->next;  
        curr->next = prev;  
        prev = curr;        
        curr = next;
    }
    return prev;  
}

int pairSum(struct ListNode* head) {
    struct ListNode *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* secondHalf = reverseList(slow);
    struct ListNode* firstHalf = head;

    int maxTwinSum = 0;
    while (secondHalf != NULL) {
        maxTwinSum = (maxTwinSum > firstHalf->val + secondHalf->val) ? maxTwinSum : firstHalf->val + secondHalf->val;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    
    return maxTwinSum;
}
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}
