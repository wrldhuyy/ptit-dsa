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
void removeDuplicate(node*& l){
	node* p = l;
	int pos1 = 1;
	while(p != NULL){
		node* q = p;
		int pos2 = pos1;
		while(q->next != NULL){
			if(q->next->data == p->data){
				if (q->next->next == NULL)
                    l = deleteTail(l);
                else
                    l = deleteAt(l, pos2);
			} else{
				q = q->next;
				pos2++;
			}
		}
		p = p->next;
		pos1++;
	}
	
}
void printList(node* l){
	while(l != NULL){
		cout << l->data <<" ";
		l = l->next;
	}
}
int main(){
	int n;
	cin >> n;
	node* First = NULL;
	for(int i = 0; i<n;i++){
		int x;
		cin >> x;
		First = addTail(First, x);
	}
	  removeDuplicate(First);
    printList(First);

    return 0;
}
