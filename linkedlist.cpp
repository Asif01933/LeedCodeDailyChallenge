/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        if(head==NULL){
            return NULL;
        }
        if(fast->next == NULL || fast->next->next == NULL){
            return NULL;
        }
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow){
                break;
            }
        }
        if(fast!=slow){
            return NULL;
        }
        ListNode* dummy=head;
        while(dummy!=slow){
            dummy=dummy->next;
            slow=slow->next;
        }
        return slow;
        
        
    }
};