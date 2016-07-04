class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*re=NULL,*iter_l1=l1,*iter_l2=l2,*iter_re=NULL,*current=NULL;
        int c=0;

        while(iter_l1 && iter_l2){
        	current=new ListNode(iter_l1->val+iter_l2->val+c);
        	if(current->val>=10){
        		c=1;
        		current->val=current->val-10;
        	}
        	else{
        		c=0;
        	}
        	iter_l1=iter_l1->next;
        	iter_l2=iter_l2->next;
        	current->next=NULL;
        	if(re==NULL){
        		re=current;
        		iter_re=re;
        	}
        	else{
        		iter_re->next=current;
        		iter_re=iter_re->next;
        	}
        }

        while(iter_l1){
      		current=new ListNode(iter_l1->val+c);
        	if(current->val>=10){
        		c=1;
        		current->val=current->val-10;
        	}
        	else{
        		c=0;
        	}
        	iter_l1=iter_l1->next;
        	if(re==NULL){
        		re=current;
        		iter_re=re;
        	}
        	else{
        		iter_re->next=current;
        		iter_re=iter_re->next;
        	}
        }

        while(iter_l2){
       		current=new ListNode(iter_l2->val+c);
        	if(current->val>=10){
        		c=1;
        		current->val=current->val-10;
        	}
        	else{
        		c=0;
        	}
        	iter_l2=iter_l2->next;
        	if(re==NULL){
        		re=current;
        		iter_re=re;
        	}
        	else{
        		iter_re->next=current;
        		iter_re=iter_re->next;
        	}
        }
        
        if(c){
        	current=new ListNode(c);
        	iter_re->next=current;
        	iter_re=iter_re->next;
        }

        return re;
    }
};