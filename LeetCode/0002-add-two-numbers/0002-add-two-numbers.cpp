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

 using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        const int NMAX = 103;
        int s1[NMAX]{}, s2[NMAX]{}, res[NMAX]{};

        int len1 =0, len2 = 0;
        while(l1)
        {
            s1[len1++] = l1->val;

            l1 = l1->next;
        }

        while(l2)
        {
            s2[len2++] = l2->val;

            l2 = l2->next;
        }
        
        int maxSize = max(len1, len2);

        // reverse order 할 필요 없음
        // List가 역순으로 들어온다는 말은
        // 1의 자리부터 들어온다 -> 그냥 저장하고 계산하면 된다. 깊게 생각할 필요 없음
        // {
        //     int l = 0, r =maxSize-1;
        //     while(l<r)
        //     {
        //         swap(s1[l],s1[r]);
        //         swap(s2[l++],s2[r--]);
        //     }
        // }
        
        for(int i =0 ;i<maxSize;i++)
        {
            cout << s1[i] << " ";
        }
        cout << "\n";
        for(int i =0 ;i<maxSize;i++)
        {
            cout << s2[i] << " ";
        }
        cout << "\n";

        // [0 ~maxSize)

        int carry = 0;
        for(int i = 0;i<maxSize;i++)
        {
            int sum = s1[i] + s2[i] + carry;

            carry = sum / 10;

            res[i] = sum % 10;   
        }

        // 최상위 1로 올림 발생

        if(carry > 0)
            res[maxSize++] = carry;

        ListNode* prevNode = nullptr;
        ListNode* newNode;
        for(int i =maxSize - 1; i>=0;i--)
        {
            newNode = new ListNode(res[i], prevNode);

            prevNode = newNode;
        }

        return newNode;
    }
};