#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution{
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> nodes = {head};
        while (nodes.back()-> next != NULL) {  //注意while条件的判断
            nodes.push_back(nodes.back()->next);
        }
        return nodes[nodes.size()/2];
    }
};