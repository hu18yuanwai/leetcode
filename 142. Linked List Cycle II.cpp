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
        int n = haveCycle(head);
        if(n==-1) return NULL;
        ListNode *p1 = head, *p2 = head;
        while (n--) p2 = p2 ->next;
        while(p1 && p2){
            if (p1 == p2) return p1;
            p1 = p1 ->next;
            p2 = p2 ->next;
        }
        return NULL;
    }
private:
    int haveCycle(ListNode *head){
        if(head==NULL) return -1;
        ListNode *p1 = head,*p2 = head;
        int l1 = 0, l2 =0;
        while(p1 && p2){
            p1 = p1 ->next;
            p2 = p2 ->next;
            l1++;
            l2++;
            if(p2 == NULL) return -1;
            p2 = p2 -> next;
            l2 ++;
            if(p1 == p2) return l2 - l1;
        }
        return -1;
    }
};

class Solution{
public:
    ListNode* detectCycle(ListNode *head){
        if(head == nullptr) return head;
        ListNode *p1 =head, *p2 =head;
        while(p1 && p2){
            p1 = p1 ->next;
            p2 = p2 ->next;
            if(p2 == nullptr) return nullptr;
            p2 = p2->next;
            if(p1 == p2){
                p1 = head;
                while(p1 ! = p2){
                    p1 = p1 ->next;
                    p2 = p2 ->next;
                }
                return p1;
            }
        }
        return nullptr;
    }
};
