/*
Question:
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.
*/
#include <iostream>
#include <unordered_map>
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    bool hasCycle_1(ListNode *head) //Method 1(Using floyd's cycle finding algorithm)
    {
        if(head==NULL || head->next==NULL)
            return false;
        ListNode * slow=head,*fast=head;
        while(fast !=NULL && fast->next !=NULL)
        {
            fast=fast->next ->next;
            slow=slow->next;
            if(slow==fast)
                return true;
        }
        return false;
    }
    bool hasCycle_2(ListNode *head) //Method 2: Using hashmap
    {
        ListNode *tmp=head;
        std::unordered_map<ListNode *,int>occ;
        while(tmp!=NULL)
        {
            if(occ[tmp])
                return true;
            occ[tmp]++;
            tmp=tmp->next;
        }
        return false;
    }
};
