/*
 * Problem: 146. LRU Cache
 * Link: https://leetcode.com/problems/lru-cache/
 * Difficulty: medium
 * Approach: Hash map + doubly linked list
 * Complexity: Time : O(1) for get/put, Space : O(capacity)
 */

#include <unordered_map>

class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr) {}
    };

    int capacity_;
    std::unordered_map<int, Node*> cache_;
    Node* head_;
    Node* tail_;

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAfterHead(Node* node) {
        node->next = head_->next;
        node->prev = head_;
        head_->next->prev = node;
        head_->next = node;
    }

    void moveToFront(Node* node) {
        removeNode(node);
        insertAfterHead(node);
    }

    Node* removeLeastRecentlyUsed() {
        Node* node = tail_->prev;
        removeNode(node);
        return node;
    }

public:
    LRUCache(int capacity) : capacity_(capacity) {
        head_ = new Node(0, 0);
        tail_ = new Node(0, 0);
        head_->next = tail_;
        tail_->prev = head_;
    }

    ~LRUCache() {
        Node* current = head_;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    int get(int key) {
        auto it = cache_.find(key);
        if (it == cache_.end()) {
            return -1;
        }

        moveToFront(it->second);
        return it->second->value;
    }

    void put(int key, int value) {
        auto it = cache_.find(key);
        if (it != cache_.end()) {
            it->second->value = value;
            moveToFront(it->second);
            return;
        }

        Node* node = new Node(key, value);
        cache_[key] = node;
        insertAfterHead(node);

        if (static_cast<int>(cache_.size()) > capacity_) {
            Node* lru = removeLeastRecentlyUsed();
            cache_.erase(lru->key);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
