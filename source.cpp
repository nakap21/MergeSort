#include <iostream>

template <typename T>
struct ownList {
    T val;
    struct ownList *next;
};

template <typename T>
ownList<T>* mergeSort(ownList<T>* first, ownList<T>* second) {
    ownList<T>* help = new ownList<T>;
    ownList<T>* ret = help;
    while(first != nullptr && second != nullptr) {
        if (first->val < second->val) {
            help->next = first;
            first = first->next;
        } else {
            help->next = second;
            second = second->next;
        }
        help = help->next;
    }
    if (first == nullptr) {
        help->next = second;
    } else {
        help->next = first;
    }
    help = ret;
    ret = ret->next;
    delete help;
    return ret;
}

template <typename T>
ownList<T>* merge(ownList<T>* now) {
    if (now == nullptr || now->next == nullptr) {
        return now;
    }
    ownList<T>* second = now;
    ownList<T>* tmp = now;
    while (tmp->next != nullptr && tmp->next->next != nullptr) {
        second = second->next;
        tmp = tmp->next;
        tmp = tmp->next;
    }
    tmp = second;
    second = second->next;
    tmp->next = nullptr;
    return mergeSort(merge(now), merge(second));
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
    head = merge(head);
    while (head != nullptr) {
        std::cout << head->val << " ";
        ownList<int>* forDelete = head;
        head = head->next;
        delete forDelete;
    }
    return 0;
}
