class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        //if(head==nullptr) return head;
        ListNode* helper = new ListNode(0);
        ListNode* cur = head, *pre = helper,* next = nullptr;
        while(cur){
            next = cur->next;
            if(!pre || !pre->next || pre->next->val >= cur->val) pre = helper;
            while(pre->next!=nullptr && pre->next->val<cur->val)
                pre = pre->next;
            cur ->next = pre->next;
            pre->next = cur;
            cur = next;
        }
        return helper->next;
    }
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        //if(head==nullptr) return head;
        ListNode *h=new ListNode(0);
        ListNode *cur=head;
        ListNode *prev=h;
        ListNode *next=NULL;
        while(cur){
            next=cur->next;
            if(!prev||!prev->next||prev->next->val>=cur->val)prev=h;//I add this line
            while(prev->next&&prev->next->val<cur->val){
                prev=prev->next;
            }
            cur->next=prev->next;
            prev->next=cur;
            //pre = helper;// I erase this line;
            cur=next;
        }
        return h->next;
  }
};

ListNode *insertionSortList(ListNode *head) {
    ListNode result(INT_MIN);

    while (head) {
        ListNode* iter = &result;
        while (iter->next && iter->next->val < head->val) {
            iter = iter->next;
        }
        ListNode* next = head->next;
        head->next = iter->next;
        iter->next = head;
        head = next;
    }

    return result.next;
}

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* new_head = new ListNode(0);
        new_head -> next = head;
        ListNode* pre = new_head;
        ListNode* cur = head;
        while (cur) {
            if (cur -> next && cur -> next -> val < cur -> val) {
                while (pre -> next && pre -> next -> val < cur -> next -> val)
                    pre = pre -> next;
                /* Insert cur -> next after pre.*/
                ListNode* temp = pre -> next;
                pre -> next = cur -> next;
                cur -> next = cur -> next -> next;
                pre -> next -> next = temp;
                /* Move pre back to new_head. */
                pre = new_head;
            }
            else cur = cur -> next;
        }
        ListNode* res = new_head -> next;
        delete new_head;
        return res;
    }
};
