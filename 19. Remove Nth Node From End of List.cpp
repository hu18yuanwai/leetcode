ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode * curr=head;
       int len=0;
       while(curr){
           curr=curr->next;
           len++;
       }

       int pos=len-n+1;

       if(pos==1){
           return head->next;
       }

       ListNode *pre=head;
       curr=head;
       pos--;
       while(pos--){
           pre=curr;
           curr=curr->next;
       }
       pre->next=curr->next;

       return head;
}


ListNode *removeNthFromEnd(ListNode *head, int n) {
       // Start typing your C/C++ solution below
       // DO NOT write int main() function
       if (head == NULL)
           return NULL;

       ListNode *pPre = NULL;
       ListNode *p = head;
       ListNode *q = head;
       for(int i = 0; i < n - 1; i++)
           q = q->next;

       while(q->next)
       {
           pPre = p;
           p = p->next;
           q = q->next;
       }

       if (pPre == NULL)
       {
           head = p->next;
           delete p;
       }
       else
       {
           pPre->next = p->next;
           delete p;
       }

       return head;
   }
