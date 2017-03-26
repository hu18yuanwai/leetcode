class Solution
{
public:
    void reorderList(ListNode* head)
    {
        if (!longerThan(head, 2))
        {
            return;
        }

        // list has 3 or more elements.
        auto p = head;
        auto q = head->next;
        while (q != nullptr && q->next != nullptr)
        {
            p = p->next;
            q = q->next->next;
        }

        // 以p作为原来链表最后节点的话，
        // 如果链表长度为偶数，那么两个子链表长度相等。
        // 否则前面的链表比后面的链表多一个节点。
        auto head2 = p->next;
        p->next = nullptr;

        head2 = reverseList(head2);
        head = insertList(head, head2);
    }

private:
    bool longerThan(ListNode *head, int len)  // whether the list is longer than 'len'.
    {
        int cnt = 0;
        while (head != nullptr)
        {
            cnt++;
            if (cnt > len)
            {
                return true;
            }
        }
        return false;
    }

    ListNode* reverseList(ListNode *head)
    {
        if (head == nullptr)
        {
            return head;
        }

        auto p = head;
        auto q = head->next;
        head->next = nullptr;
        while (q != nullptr)
        {
            auto tmp = q->next;
            q->next = p;
            p = q;
            q = tmp;
        }
        return p;
    }

    ListNode* insertList(ListNode *head, ListNode *head2)
    {
        auto p = head;
        while (head2 != nullptr)
        {
            auto node = head2;
            head2 = head2->next;

            node->next = p->next;
            p->next = node;
            p = p->next->next;
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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next ==NULL) return head;
        ListNode* quick=head, *slow=head,*pre_slow = head;
        while(quick!=nullptr){
            pre_slow = slow;
            slow = slow->next;
            quick = quick->next;
            if(quick!=nullptr){
                quick = quick->next;
            }
        }
        ListNode* l2 = reverse(slow);
        pre_slow->next = NULL;
        insertList(head,l2);
    }
private:
    ListNode* reverse(ListNode* head){
      if(head==NULL || head->next==NULL) return;
      ListNode *re=reverse(head->next);
      ListNode *cur=re;
      while(cur->next){
        cur=cur->next;
      }
      cur->next=head;
      head->next=NULL;
      return re;
    }

    ListNode* insertList(ListNode *head, ListNode *head2)
    {
        auto p = head;
        while (head2 != nullptr)
        {
            auto node = head2;
            head2 = head2->next;

            node->next = p->next;
            p->next = node;
            p = p->next->next;
        }
        return head;
    }
};
