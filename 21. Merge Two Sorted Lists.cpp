struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    ListNode * returnNode=NULL;
    if(l1->val<l2->val){
      returnNode=l1;
      returnNode->next=mergeTwoLists(l1->next,l2);
    }

    else{
      returnNode=l2;
      returnNode->next=mergeTwoLists(l1,l2->next);
    }
    return returnNode;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    ListNode *returnNode=NULL,*curNode=NULL,*p1=l1,*p2=l2;
    while(p1 && p2){
      if(returnNode==NULL){
        if(p1->val<p2->val){
          returnNode=curNode=p1;
          p1=p1->next;
          curNode->next=NULL;
        }
        else{
          returnNode=curNode=p2;
          p2=p2->next;
          curNode->next=NULL;
        }
      }
      else{
        if(p1->val<p2->val){
          curNode->next=p1;
          curNode=p1;
          p1=p1->next;
          curNode->next=NULL;
        }
        else{
          curNode->next=p2;
          curNode=p2;
          p2=p2->next;
          curNode->next=NULL;
        }
      }
    }
  if(p1){
      curNode->next=p1;
    }
  if(p2){
      curNode->next=p2;
    }
    return returnNode;
}

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
