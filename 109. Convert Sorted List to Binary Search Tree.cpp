class Solution {
public:
	ListNode* find_mid(ListNode* head,ListNode* end){
		if(head==NULL || end==NULL) return NULL;
		ListNode* slow=head,* quick= head,* preSlow =NULL;
		while(slow!=end && quick!=end){
			preSlow = slow;
			slow=slow->next;
			quick=quick->next;
			if(quick!=end)// it is not if(quick)
				quick=quick->next;
		}
		return preSlow;
	}

	TreeNode* constructTree(ListNode* head, ListNode* end){
		if(head == NULL) return NULL;
		if(head == end){
			TreeNode* root = new TreeNode(head->val);
			return root;
		}
		ListNode* midPre = find_mid(head, end);
		ListNode* mid = midPre->next;

		TreeNode* root = new TreeNode(mid->val);

		if(mid!=head)
			root->left = constructTree(head, midPre);
		if(mid!=end)
			root->right = constructTree(mid->next,end);
		return root;
	}

    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode* cur = head;
        while(cur->next) cur=cur->next;
        return constructTree(head,cur);
    }
};


//http://www.jianshu.com/p/559f68c13283
class Solution
{
public:
    TreeNode* sortedListToBST(ListNode* head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        else if (head->next == nullptr)
        {
            return new TreeNode(head->val);
        }

        // 让p->next为中间节点，p->next->next为右半边链表，p为左半边链表的尾节点。
        auto p = head;
        auto q = head->next->next;
        while (q != nullptr && q->next != nullptr)
        {
            p = p->next;
            q = q->next->next;
        }

        // 用p->next构造根节点，它左边的链表构造左子树，右边的链表构造右子树。
        auto node = new TreeNode(p->next->val);
        node->right = sortedListToBST(p->next->next);
        p->next = nullptr;
        node->left = sortedListToBST(head);
        return node;
    }
};
