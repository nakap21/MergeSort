#include <bits/stdc++.h>

using namespace std;

struct ownList {
    int val;
    struct ownList *next;
};


ownList* merge(ownList* first, ownList *second) {
    ownList* help = nullptr;
    if (first->val < second->val) {
        help = first;
        first = first->next;
    } else {
        help = second;
        second = second->next;
    }
    ownList* ret = help;
    while(first != nullptr && second != nullptr) {
        if (first->val < second->val) {
            help->next = first;
            first = first->next;
            help = help->next;
        } else {
            help->next = second;
            second = second->next;
            help = help->next;
        }
    }
    if (first == nullptr) {
        help->next = second;
    } else {
        help->next = first;
    }
    return ret;
}

ownList* divi(ownList *now, int siz) {
    if (siz <= 1) {
        return now;
    }
    ownList *second = now;
    int firSiz = siz / 2;
    for (int i = 0; i < siz / 2; ++i) {
        if (i == siz / 2 - 1) {
            ownList *tmp = second;
            second = second->next;
            tmp->next = nullptr;
        } else {
            second = second->next;
        }
    }
    return merge(divi(now, firSiz), divi(second, siz - firSiz));
}

int main()
{
    ownList* head = new ownList;
    int n;
    cin >> n;
    head = nullptr;
    for (int i = 0; i < n; ++i) {
        int what;
        cin >> what;
        ownList* tmp = new ownList;
        tmp->val = what;
        tmp->next = head;
        head = tmp;
    }
    head = divi(head, n);
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}
