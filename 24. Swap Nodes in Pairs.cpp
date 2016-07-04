struct ListNode {
      int val;
      struct ListNode *next;
};

ListNode* swapPairs(ListNode* head) {
    if(head==NULL || head->next==NULL) return head;
    ListNode *node1=head->next,*node2=head->next->next;
    node1->next=head;
    head->next=swapPairs(node2);
    return node1;
}


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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL)
            return NULL;

        ListNode *pPrePre = NULL;
        ListNode *pPre = NULL;
        ListNode *p = head;

        while(p && p->next)
        {
            pPre = p;
            p = p->next;

            ListNode *pNext = p->next;

            if (pPre == head)
                head = p;

            if (pPrePre)
                pPrePre->next = p;

            p->next = pPre;
            pPre->next = pNext;

            pPrePre = pPre;
            p = pNext;
        }

        return head;
    }
};
