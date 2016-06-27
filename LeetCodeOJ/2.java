/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if(l1 == null && l2 == null){
            return null;
        }
        int result = 0, cf = 0;
        ListNode p1 = l1;
        ListNode p2 = l2;
        ListNode head = null;
        ListNode temp1 = null, temp2 = null;
        
        while(p1  != null && p2 != null){
            result = p1.val + p2.val + cf;
            if(result > 9){
                cf = 1;
                result -= 10;
            }
            else
                cf = 0;
            temp1 = new ListNode(result);
            temp1.next = null;
            if(head == null)
                head = temp1;
            else
                temp2.next = temp1;
            temp2 = temp1;
            p1 = p1.next;
            p2 = p2.next;
        }
        if(p1 == null && p2 == null){
            if(cf == 1){
                temp1 = new ListNode(cf);
                temp1.next = null;
                temp2.next = temp1;
            }
            return head;
        }
        if(p1 == null){
            while(p2 != null){
                result = p2.val + cf;
                if(result > 9){
                    cf = 1;
                    result -= 10;
                }
                else
                    cf = 0;
                temp1 = new ListNode(result);
                temp1.next = null;
                temp2.next = temp1;
                temp2 = temp1;
                p2 = p2.next;
            }
            if(cf == 1){
                temp1 = new ListNode(cf);
                temp1.next = null;
                temp2.next = temp1;
            }
            return head;
        }
        else{
            while(p1 != null){
                result = p1.val + cf;
                if(result > 9){
                    cf = 1;
                    result -= 10;
                }
                else
                    cf = 0;
                temp1 = new ListNode(result);
                temp1.next = null;
                temp2.next = temp1;
                temp2 = temp1;
                p1 = p1.next;
            }
            if(cf == 1){
                temp1 = new ListNode(cf);
                temp1.next = null;
                temp2.next = temp1;
            }
            return head;
        }
    }
}
