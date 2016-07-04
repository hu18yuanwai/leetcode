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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return NULL;

        int delVal=head->val;
        ListNode *cur=head->next;
        ListNode *pre=head;
        while(cur){
            if(cur->val==delVal){
                ListNode *temp=cur;
                pre->next=cur->next;
                cur=pre->next;
                delete []temp;
            }
            else{
                delVal=cur->val;
                pre=cur;
                cur=cur->next;
            }
        }
        return head;
    }
};
