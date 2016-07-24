/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	if(head==NULL) return head;
    	RandomListNode *helper = new RandomListNode(0),*copycur=helper,*cur=head;
    	map<RandomListNode *,int>posAndCount;
    	map<int,RandomListNode *> countAndPos;
    	int count=1;
    	while(cur){
    		RandomListNode * cpnode = new RandomListNode(cur->label);
    		copycur->next=cpnode;
    		copycur=copycur->next;

    		posAndCount[cur]=count;
    		countAndPos[count]=copycur;

    		cur = cur->next;
    		count++;// forget!!!!!!!!!!!!
    	}

    	cur =head;
    	copycur = helper->next;

    	while(cur){
    		if(cur->random){
    			copycur->random=countAndPos[ posAndCount[cur->random] ];
    		}
    		cur=cur->next;
    		copycur=copycur->next;
    	}
    	return helper->next;
    }
};



class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        RandomListNode *pos1 = head, *pos2 = head->next;
        while (pos1 != NULL) {
            pos1->next = new RandomListNode(pos1->label);
            pos1->next->next = pos2;
            pos1 = pos2;
            if (pos2 != NULL)
                pos2 = pos2->next;
        }
        pos1 = head;  pos2 = head->next;
        while (pos1 != NULL) {
            if (pos1->random == NULL) {
                pos2->random = NULL;
            } else {
                pos2->random = pos1->random->next;
            }
            pos1 = pos1->next->next;
            if (pos2->next != NULL)
                pos2 = pos2->next->next;
        }
        RandomListNode *res = head->next;
        pos1 = head; pos2 = head->next;
        while(pos2->next != NULL) {
            pos1->next = pos2->next;
            pos1 = pos2;
            if (pos2->next != NULL)
                pos2 = pos2->next;
        }
        pos1->next = NULL;
        pos2->next = NULL;
        return res;
    }
};