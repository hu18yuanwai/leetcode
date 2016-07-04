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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headB==headA) return headA;
        if(headA==NULL || headB==NULL) return NULL;
        int lenA=0,lenB=0;
        ListNode*curA=headA;
        ListNode*curB=headB;
        while(curA){
        	lenA++;
        	curA=curA->next;
        }
        while(curB){
        	lenB++;
        	curB=curB->next;
        }
        curA=headA;
        curB=headB;
        int lenDis=lenA>lenB?lenA-lenB:lenB-lenA;
        if(lenA>lenB){
        	while(lenDis--){
        		curA=curA->next;
        	}
        	while(curA && curB){
        		if(curA==curB) return curA;
        		curA=curA->next;
        		curB=curB->next;
        	}
        }
        else{
        	while(lenDis--){
        		curB=curB->next;
        	}
        	while(curA && curB){
        		if(curA==curB) return curA;
        		curA=curA->next;
        		curB=curB->next;
        	}
        }
        return NULL;
    }
};