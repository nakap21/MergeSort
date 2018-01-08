#include <iostream>

template <typename T>
struct ownList {
    T val;
    struct ownList *next;
};

template <typename T>
ownList<T>* merge(ownList<T>* first, ownList<T>* second) {
    if (!first) {
        return  second;
    }
    if (!second) {
        return  first;
    }
    if (first->val < second->val) {
        first->next = merge(first->next, second);
        return first;
    } else {
        second->next = merge(first, second->next);
        return second;
    }
}

template <typename T>
ownList<T>* divide(ownList<T>* now) {
    if (now == nullptr || now->next == nullptr) {
        return now;
    }
    ownList<T>* second = now;
    ownList<T>* tmp = now;
    while (tmp->next != nullptr && tmp->next->next != nullptr) {
        second = second->next;
        tmp = tmp->next->next;
    }
    tmp = second;
    second = second->next;
    tmp->next = nullptr;
    return merge(divide(now), divide(second));
}

int main() {
    ownList<int>* head = new ownList<int>;
    int n;
    std::cin >> n;
    head = nullptr;
    for (int i = 0; i < n; ++i) {
        int element;
        ownList<int>* tmp = new ownList<int>;
        std::cin >> element;
        tmp->val = element;
        tmp->next = head;
        head = tmp;
    }
    head = divide(head);
    while (head != nullptr) {
        std::cout << head->val << " ";
        ownList<int>* forDelete = head;
        head = head->next;
        delete forDelete;
    }
    return 0;
}
