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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL){
            return NULL;
        }
        int result = 0, cf = 0;
        struct ListNode *p1 = l1;
        struct ListNode *p2 = l2;
        struct ListNode *head = NULL;
        struct ListNode *temp1, *temp2;
        
        while(p1 && p2){
            result = p1 -> val + p2 ->val + cf;
            if(result > 9){
                cf = 1;
                result -= 10;
            }
            else
                cf = 0;
            temp1 = new ListNode(result);
            if(head == NULL)
                head = temp1;
            else
                temp2 -> next = temp1;
            temp2 = temp1;
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        if(p1 == NULL && p2 == NULL){
            if(cf == 1){
                temp1 = new ListNode(cf);
                temp2 -> next = temp1;
            }
            return head;
        }
        if(p1 == NULL){
            while(p2){
                result = p2 -> val + cf;
                if(result > 9){
                    cf = 1;
                    result -= 10;
                }
                else
                    cf = 0;
                temp1 = new ListNode(result);
                temp2 -> next = temp1;
                temp2 = temp1;
                p2 = p2 -> next;
            }
            if(cf == 1){
                temp1 = new ListNode(cf);
                temp2 -> next = temp1;
            }
            return head;
        }
        else{
            while(p1){
                result = p1 -> val + cf;
                if(result > 9){
                    cf = 1;
                    result -= 10;
                }
                else
                    cf = 0;
                temp1 = new ListNode(result);
                temp2 -> next = temp1;
                temp2 = temp1;
                p1 = p1 -> next;
            }
            if(cf == 1){
                temp1 = new ListNode(cf);
                temp2 -> next = temp1;
            }
            return head;
        }
    }
};
