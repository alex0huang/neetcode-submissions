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
        if (!head) return nullptr;

        Node* cur = head;

        // 1. 在每个节点后面插入一个复制节点
        while (cur) {
            Node* copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;
        }

        // 2. 设置复制节点的 random
        cur = head;
        while (cur) {
            if (cur->random)
                cur->next->random = cur->random->next; 
            cur = cur->next->next;
        }

        // 3. 拆分链表（恢复原链表 + 拿出新链表）
        cur = head;
        Node* newHead = head->next;
        while (cur) {
            Node* copy = cur->next;
            cur->next = copy->next;
            copy->next = (copy->next ? copy->next->next : nullptr);
            cur = cur->next;
        }

        return newHead;
    }
};

