ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *helper=new ListNode(0);
        ListNode *head=helper;
        while(l1 && l2)
        {
             if(l1->val<l2->val) helper->next=l1,l1=l1->next;
             else helper->next=l2,l2=l2->next;
             helper=helper->next;
        }
        if(l1) helper->next=l1;
        if(l2) helper->next=l2;
        return head->next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
  if(lists.size()==0) return NULL;
  if(lists.size()==1) return lists[0];
  vector<ListNode*> lists1;
  vector<ListNode*> Lists2;

  for(int i=0;i<lists.size()/2;i++){
    lists1.push_back(lists[i]);
  }

  for(int i=lists.size()/2;i<lists.size();i++){
    lists2.push_back(lists[i]);
  }
  return mergeTwoLists(mergeKLists(lists1),mergeKLists(Lists2));
}

//方法2,优先队列
struct cmp1{
    bool operator ()(ListNode* a,ListNode* b){
        return a->val>b->val;//最小值优先
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
  if(lists.size()==0) return NULL;
  if(lists.size()==1) return lists[0];
  ListNode *helper=new ListNode(0);
  ListNode *ret=helper;
  priority_queue<ListNode*,vector<ListNode*>,cmp1>que1;
  for(int i=0;i<lists.size();i++){
    if(lists[i]!=NULL){
      que1.push(lists[i]);
    }
  }
  while(!que1.empty()){
    ret->next=que1.top();
    que1.pop();
    ret=ret->next;
    if(ret->next!=NULL){
      que1.push(ret->next);
    }
  }
  return helper->next;
}
