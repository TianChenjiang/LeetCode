// Given a non-empty, singly linked list with head node head, return a middle node of linked list.

// If there are two middle nodes, return the second middle node.

#include<iostream>
#include<sstream>
#include<vector>
#include<string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int length = 0;
        int cnt = 0;
        ListNode* cur = head;
        while (cur) {
            cur = cur->next;
            length++;
        }
    
        while (head != NULL) {
            cnt++;
            if (cnt == length/2) {
                return head->next;
            }
            head = head->next;
        }
        return NULL;
    }
};


int main() {
    string line;
    cin >> line;

    stringstream stream(line);
    string word;
    vector<int> numList;
    char delim = ',';
    while (getline(stream, word, delim)) {
        numList.push_back(stoi(word));
    }
}