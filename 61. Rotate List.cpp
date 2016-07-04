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
     ListNode *rotateRight(ListNode *head, int k) {
         if(head == NULL || k <= 0){
             return head;
         }
         int count = 1;
         ListNode *pre = head,*cur;
         while(pre->next){
             count++;
             pre = pre->next;
         }
         pre->next = head;
         k = k % count;
         int index = 1;
         pre = cur = head;
         //右移k位
         while(index <= (count - k)){
             pre = cur;
             cur = cur->next;
             index++;
         }

         pre->next = NULL;
         head = cur;
         return head;
     }
 };
