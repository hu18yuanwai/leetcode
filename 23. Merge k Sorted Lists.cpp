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


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*> &lists)
    {
        // 创建一个最小值堆，把每个链表的头节点加入堆里。
        vector<ListNode**> minHeap;
        for (auto &p : lists)
        {
            if (p != nullptr)
            {
                minHeap.push_back(&p);
            }
        }
        make_heap(minHeap.begin(), minHeap.end(), compare);

        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        while (!minHeap.empty())
        {
            // 从堆中弹出最小值
            pop_heap(minHeap.begin(), minHeap.end(), compare);
            auto p = minHeap.back();
            minHeap.pop_back();

            // 找出最小值所在链表的下一个节点，将其压入堆中。
            auto node = (*p);
            (*p) = (*p)->next;
            if ((*p) != nullptr)
            {
                minHeap.push_back(p);
                push_heap(minHeap.begin(), minHeap.end(), compare);
            }

            // 把这个最小值放到结果中
            node->next = nullptr;
            appendToList(head, tail, node);
        }
        return head;
    }

private:
    // 最小值堆的比较函数
    static bool compare(ListNode **p1, ListNode **p2)
    {
        return (*p1)->val > (*p2)->val;
    }

    // 把node添加到tail的后面，始终保持head、tail为链表的首尾节点。
    inline void appendToList(ListNode *&head, ListNode *&tail, ListNode *node)
    {
        if (head == nullptr)
        {
            head = tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }
};
