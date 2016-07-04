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
  ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        else if (head->next->next==NULL){
        	ListNode *pre=head->next;
        	pre->next=head;
        	head->next=NULL;
        	return pre;
        }
        else{
        	ListNode *pre=head,*cur=head->next,*post=cur->next;
        	head->next=NULL;
        	while(post){
        		cur->next=pre;
        		pre=cur;
        		cur=post;
        		post=post->next;
        	}
        	cur->next=pre;
        	delete post;
        	return cur;
        }
    }

    ListNode* reverseBetween(ListNode* head, int m, int n) {
      if(head==NULL) return NULL;
      int count=0;
      ListNode*dumyP=new ListNode(0);
      dumyP->next=head;
      ListNode* cur=dumyP, *pre=dumyP;
      while(cur && count<m){
        pre=cur;
        cur=cur->next;
        count++;
      }
      ListNode* front=cur,*tail=cur;
      while(cur && count<n){
        cur=cur->next;
        count++;
      }
      tail=cur;
      ListNode *remind=cur->next;
      tail->next=NULL;
      pre->next=reverseList(front);
      cur=pre;
      while(cur->next){
        cur=cur->next;
      }
      cur->next=remind;
      return dumyP->next;
    }
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
       if(head==NULL)return NULL;
       ListNode *p=head;
       int i=1;
       for(;i<m;i++)
       p=p->next;
       for(int j=m;j<n;j++)
       {
           ListNode *q=p;
           for(int k=j;k<n;k++)
           {
               q=q->next;
           }
           swap(p->val,q->val);
           n--;
           p=p->next;
       }
       return head;
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        vector<ListNode*> range(n - m + 1);

        ListNode* iter = head;
        for(int i = 1; i < m; ++i)
            iter = iter->next;

        for(int i = m, j = 0; i <= n; ++i, ++j)
        {
            range[j] = iter;
            iter = iter->next;
        }

        for(size_t i = 0; i < range.size() / 2; ++i)
            swap(range[i]->val, range[range.size() - i - 1]->val);

        return head;
    }
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *leftI = dummy;
        for(; --m; --n) leftI = leftI->next;

        ListNode *cur = leftI->next, *rtail = cur, *pre = nullptr;
        while(n--){
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        rtail->next = cur; leftI->next = pre;

        return dummy->next;
    }
};
