/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    
    struct ListNode *track = head;
    int k = 1;
    
    while (track -> next != NULL)
    {
        track = track -> next;
        k++;
    }

    track = head;
    
    for (int i = 1; (i < k - n) && track != NULL; i++)
    {
        track = track -> next;
        printf("%d\n", i);
    }
    
    if (n == k)
    {
        track = track -> next;
        free(head);
        head = track;
    }
    else
    { 
        struct ListNode *keep = track -> next -> next;
        free(track -> next);
        track -> next = keep;
    }
    
    return head;
}
