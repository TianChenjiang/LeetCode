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
    ListNode(int x): val(x), next(NULL) {};
};

class Solution{
public:
    ListNode* middle(ListNode* head){
        int length = 0;
        int count = 0;
        ListNode* dummyNode = head;
        while (dummyNode != NULL) {
            dummyNode = dummyNode->next;
            length++;
        }
        if (length == 1) {
            return head;
        }
        
        while (head != NULL && count != length/2) {
            head = head->next;
            count++;
            
            return head->next;
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