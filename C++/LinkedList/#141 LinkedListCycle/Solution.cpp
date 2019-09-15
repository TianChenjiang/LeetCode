#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
  
class Solution {
public:
    bool hasCycle(ListNode *head) {
        vector<ListNode*> nodes = {head};
        while (head->next) {
           if (find(nodes.begin(), nodes.end(), head) == nodes.end()) {
               return true;
           }
           head = head->next;
           nodes.push_back(head);
       }
       return false;
    }
};