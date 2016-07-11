/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //note: in function merger, the end of the linklist must be NULL, if it not NULL
 //it will be not stop, so in function mergersort,we must add NULL to the end of 
 //every little
 //splice 
class Solution {
public:
	ListNode *merger(ListNode *l1, ListNode *l2) {
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

ListNode* findMid(ListNode* head,ListNode* end){
	ListNode* p1 =head,*p2 =head,*PreP1=head;
	while(p1!=end && p2!=end){
		PreP1=p1;
		p1=p1->next;
		p2=p2->next;
		if(p2->next)
			p2=p2->next;
	}
	return PreP1;
}

ListNode* mergerSort(ListNode* head,ListNode* end){
		if(head == end) return head;
		ListNode* mid = findMid(head,end);
		ListNode* mid_next= mid->next;
		mid->next=NULL;
		end->next=NULL;//bug1 忘记写这句了，和数组不一样，这里是链表。每个新形成的小链表都要在结尾处用NULL断开。
		ListNode*left = mergerSort(head,mid);
		ListNode*right =mergerSort(mid_next,end);
		return merger(left,right);
	}

    ListNode* sortList(ListNode* head) {
        if(head==NULL) return head;
        ListNode* cur=head;
        while(cur->next){
        	cur=cur->next;
        }
        return mergerSort(head,cur);
    }
};


// quick sort is not fit to this problem, because it is too time-consuming.
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