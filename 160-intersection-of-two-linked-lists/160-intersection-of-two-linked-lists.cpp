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
        unordered_set<ListNode*> s;
        
        ListNode* temp = headB;
        
        while(temp){
            s.insert(temp);
            temp = temp->next;
        }
        
        temp = headA;
        while(temp){
            if(s.find(temp) != s.end()) return temp;
            temp = temp->next;
        }
        
        return nullptr;
    }
};