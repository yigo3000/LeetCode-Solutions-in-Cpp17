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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (empty(lists)) return nullptr;
        return mergeSomeLists(lists, 0, size(lists));
    }

    ListNode* mergeSomeLists(vector<ListNode*>& lists, int l, int r)
    {
        if (l == r - 1) return lists[l];
        int m = l + (r - l) / 2;
        ListNode* l1 = mergeSomeLists(lists, l, m);
        ListNode* l2 = mergeSomeLists(lists, m, r);
        return mergeTwoLists(l1, l2);
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        l2->next = mergeTwoLists(l2->next, l1);
        return l2;
    }
};