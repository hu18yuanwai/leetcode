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



class Solution
{
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode *resHead = nullptr;
        ListNode *resTail = nullptr;

        auto kth = findKthNode(head, k);
        while (kth != nullptr)
        {
            auto first = head;
            auto last = kth;
            head = kth->next;
            last->next = nullptr;

            reverseList(first);
            appendToList(resHead, resTail, last, first);
            kth = findKthNode(head, k);
        }

        appendToList(resHead, resTail, head, nullptr);
        return resHead;
    }

private:
    ListNode* findKthNode(ListNode *head, int k)
    {
        for (int i = 1; i < k && head != nullptr; i++)
        {
            head = head->next;
        }
        return head;
    }

    ListNode* reverseList(ListNode *head)
    {
        ListNode *res = nullptr;
        while (head != nullptr)
        {
            auto node = head;
            head = head->next;

            node->next = res;
            res = node;
        }
        return res;
    }

    void appendToList(ListNode *&head1, ListNode *&tail1, ListNode *head2, ListNode *tail2)
    {
        if (head1 == nullptr)
        {
            head1 = head2;
            tail1 = tail2;
        }
        else
        {
            tail1->next = head2;
            tail1 = tail2;
        }
    }
};
