#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;
};

node* createNode(int x) {
    node* p = new node;
    p->data = x;
    p->next = NULL;
    return p;
}

node* addTail(node* l, int x) {
    node* p = createNode(x);
    if (l == NULL) return p;
    node* q = l;
    while (q->next != NULL) q = q->next;
    q->next = p;
    return l;
}

node* deleteHead(node* l) {
    if (l == NULL) return NULL;
    node* temp = l;
    l = l->next;
    delete temp;
    return l;
}

node* deleteTail(node* l) {
    if (l == NULL) return NULL;
    if (l->next == NULL) {
        delete l;
        return NULL;
    }
    node* p = l;
    while (p->next->next != NULL) p = p->next;
    delete p->next;
    p->next = NULL;
    return l;
}

node* deleteAt(node* l, int k) {
    node* p = l;
    for (int i = 0; i < k - 1; i++) p = p->next;
    node* temp = p->next;
    p->next = temp->next;
    delete temp;
    return l;
}

int deleteX(node*& l, int x) {
    int cnt = 0;

    while (l != NULL && l->data == x) {
        l = deleteHead(l);
        cnt++;
    }

    if (l == NULL) return cnt;

    node* p = l;
    int pos = 1;

    while (p->next != NULL) {
        if (p->next->data == x && p->next->next == NULL) {
            l = deleteTail(l);
            cnt++;
            break;
        } else if (p->next->data == x) {
            l = deleteAt(l, pos);
            cnt++;
        } else {
            p = p->next;
            pos++;
        }
    }

    return cnt;
}

void printList(node* l) {
    while (l != NULL) {
        cout << l->data << " ";
        l = l->next;
    }
}

int main() {
    int n, x;
    cin >> n;
    node* First = NULL;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        First = addTail(First, t);
    }
    cin >> x;
    deleteX(First, x);
    printList(First);
    return 0;
}
