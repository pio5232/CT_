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
    ListNode *detectCycle(ListNode *head) {

     // has cycle => return cycle begin
     // has no cycle => return null   

        unordered_set<ListNode*> hash_set;

        ListNode* cur = head;
        
        while(cur)
        {
            auto [iter, ret] = hash_set.insert(cur);

            // cycle
            if(ret == false)
                return *iter;

            cur = cur->next;
        }

        // no cycle
        return cur;
    }
};