/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        
        vector<ListNode*> vec;
        int start_index = 0;
        int end_index;

        ListNode* cur = head;
        while(cur)
        { 
            vec.push_back(cur);
            cur = cur->next;
        }

        end_index = vec.size() -1;
        cur = head;
        cur->next = vec[start_index++];
        int idx = end_index;
        while(start_index <= end_index)
        {
            if(idx == end_index)
            {
                cur->next = vec[end_index--];
                cur = cur->next;
                idx = start_index;
            }
            else if(idx == start_index)
            {
                cur->next = vec[start_index++];
                cur = cur->next;
                idx = end_index;
            }
        }
        cur->next = nullptr;
    }
};