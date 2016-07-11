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