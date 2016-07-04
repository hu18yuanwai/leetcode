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
    ListNode* sortList(ListNode* head) {
        
    }
};


// quick sort is not fit to this problem.
class Solution {
public:
	void Swap(int& a, int& b){
		int temp=a;
		a=b;
		b=temp;
	}

	ListNode* Partion(ListNode* head,ListNode* end){
		if(head==end) return head;
		ListNode* indexNode = head;
		Swap(indexNode->val,end->val);
		ListNode *small=NULL,*preSmall=small;
		while(indexNode!=end){
			if(indexNode->val<end->val){
				preSmall=small;
				if(small==NULL){
					small=head;
				}
				else{
					small=small->next;
				}

				if(small!=indexNode){
					Swap(indexNode->val,small->val);
				}
			}
			indexNode=indexNode->next;
		}
		preSmall=small;
		if(small==NULL){
			small=head;
		}
		else{
			small=small->next;
		}
		Swap(small->val,end->val);
		return preSmall;
	}

	void QuickSortList(ListNode* head,ListNode* end){
		if(head==NULL || end == NULL || head == end) return;

		ListNode* preSmall = Partion(head,end);
		if(preSmall!=NULL){
			QuickSortList(head,preSmall);
			if(preSmall->next!=end)
				QuickSortList(preSmall->next->next,end);
		}
		else{
			QuickSortList(head->next,end);
		}
	}

    ListNode* sortList(ListNode* head) {
        if(head == NULL) return head;
        ListNode* LastNode=head;
        while(LastNode->next) LastNode=LastNode->next;
        QuickSortList(head,LastNode);
        return head;
    }
};