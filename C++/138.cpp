/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        Node* res = new Node(head->val);
        Node* oldCur = head->next, *newCur = res;

        unordered_map<Node*, int> m1{{head,0}};
        unordered_map<int, Node*> m2{{0, res}};
        int cnt1 = 0, cnt2 = 0;

        while (oldCur) {
            Node* newNode = new Node(oldCur->val);
            m1[oldCur] = ++cnt1;
            m2[++cnt2] = newNode;
            newCur->next = newNode; newCur = newNode;
            oldCur = oldCur->next;
        }

        oldCur = head, newCur = res;
        if (head->random) res->random = m2[m1[head->random]];
        while (oldCur) {
            if (oldCur->random) newCur->random = m2[m1[oldCur->random]];
            newCur = newCur->next;
            oldCur = oldCur->next;
        }
        return res;
    }
};