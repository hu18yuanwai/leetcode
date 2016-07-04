ListNode* reverse(ListNode* head){
  if(head==NULL || head->next==NULL) return head;
  ListNode *re=reverse(head->next);
  ListNode *cur=re;
  while(cur->next){
    cur=cur->next;
  }
  cur->next=head;
  head->next=NULL;
  return re;
}

ListNode* reverseKGroup(ListNode* head, int k) {
      int len=0;
      ListNode * cur= head;
      while(cur){
        cur=cur->next;
        len++;
      }

      if(len<k) return head;

      int count=k;
      cur=head;
      while(--count){
          cur=cur->next;
      }

      ListNode* part2=reverseKGroup(cur->next,k);
      cur->next=NULL;
      ListNode* re=reverse(head);
      cur=re;
      while(cur->next){
        cur=cur->next;
      }
      cur->next=part2;

      return re;
}
