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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* helper = new ListNode(0);
        helper->next =head;
        ListNode* cur = head;
        ListNode* pre = helper;
        while(cur!=nullptr){
            if(cur->val==val){
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
            }
            else{
                pre = cur;
                cur=cur->next;
            }
        }
        return helper->next;
    }
};
