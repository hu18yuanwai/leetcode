class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
      if(head==NULL) return head;
      ListNode*less=NULL,*large=NULL,*ret=NULL,*cur=head;
      ListNode*curLess=NULL,*curLar=NULL;
      while(cur){
        if(cur->val<x){
          if(less==NULL){
            less=cur;
            curLess=less;
          }
          else{
            curLess->next=cur;
            curLess=cur;
          }
        }

        else{
          if(large==NULL){
            large=cur;
            curLar=large;
          }
          else{
            curLar->next=cur;
            curLar=cur;
          }
        }
        cur=cur->next;
      }
      if(less==NULL){
        curLar->next=NULL;
        ret=large;
      }
      else if(large==NULL){
        curLess->next=NULL;
        ret=less;
      }
      else{
        curLess->next=large;
        curLar->next=NULL;
        ret=less;
      }
      return ret;
    }
};


class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if(head == NULL)
            return head;

        ListNode *sm = new ListNode(0), *sm_tail = sm;
        ListNode *bg = new ListNode(0), *bg_tail = bg;
        ListNode *cur = head;

        while(cur) {
            if(cur->val < x) {
                sm_tail->next = cur;
                cur     = cur->next;
                sm_tail = sm_tail->next;
                sm_tail->next = NULL;
            }else{
                bg_tail->next = cur;
                bg_tail = bg_tail->next;
                cur = cur->next;
                bg_tail->next = NULL;
            }
        }
        sm_tail->next = bg->next;
        return sm->next;
    }
};

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
    ListNode* partition(ListNode* head, int x) {
      if(head==NULL) return head;
      ListNode *less=new ListNode(0),*large=new ListNode(0);
      ListNode *less_tail=less,*large_tail=large,*cur=head;
      while(cur){
        if(cur->val<x){
          less_tail->next=cur;
          less_tail=cur;
        }
        else{
          large_tail->next=cur;
          large_tail=cur;
        }
        cur=cur->next;
      }
      large_tail->next=NULL;
      less_tail->next=large->next;
      return less->next;
    }
};
