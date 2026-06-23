class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = head;

        if(head->next==NULL) return NULL;
        
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        //if(slow->next==NULL) head = head->next;
        //else 
        prev->next = prev->next->next;
        return head;
    }
};