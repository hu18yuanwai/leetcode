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
      if(head==NULL || head->next==NULL) return head;
      ListNode *cur=head,*pre=NULL,*ret=NULL,*preCur=NULL;
      int count;
      while(cur){
        count=0;
        int valTemp=cur->val;
        while(cur!=NULL && cur->val==valTemp){
          preCur=cur;
          cur=cur->next;
          count++;
        }
        if(count==1){
          if(ret==NULL) {
            ret=preCur;
            pre=ret;
          }
          else{
            pre->next=preCur;
            pre=preCur;
          }
        }
      }
      if(ret==NULL)//考虑这种情况
        pre->next=NULL;
      return ret;
    }
};
