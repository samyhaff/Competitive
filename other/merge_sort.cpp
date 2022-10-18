#include <bits/stdc++.h>

using namespace std;

struct node {
    int val;
    node *next;
};

int get_length(node *head){
	node* curr = head;
	int i = 0;
    while (curr) {
        curr = curr->next;
        i++;
    }
	return i;
}

node* merge(node *&head1,node *&head2){
	node* new_head;
	if (!head1) return head2;
	else if (!head2) return head1;

	if (head1->val < head2->val){
		new_head = head1;
		new_head->next = merge(head1->next, head2);
	} else {
		new_head = head2;
		new_head->next = merge(head1, head2->next);
	}

	return new_head;
}

void merge_sort(node *&head){
	if(!head->next) {
		node* head1;
		node* head2 = head;
		int len = get_length(head);
		for(int i = 0; i < len / 2; i++) {
			head1 = head2;
			head2 = head2->next;
		}
		head1->next = NULL;
		head1 = head;
		merge_sort(head1);
		merge_sort(head2);
		head = merge(head1,head2);
	}
}

void merge(vector<int> &v, int l, int m, int r) {
    vector<int> tmp;
    int i, j;
    i = l;
    j = m + 1;

    while (i <= m && j <= r) {
        if (v[i] <= v[j]) tmp.push_back(v[i++]);
        else tmp.push_back(v[j++]);
    }

    while (i <= m) tmp.push_back(v[i++]);
    while (j <= r) tmp.push_back(v[j++]);

    for (int i = l; i <= r; i++) v[i] = tmp[i - l];
}

void merge_sort(vector<int> &v, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        merge_sort(v, l, m);
        merge_sort(v, m + 1, r);
        merge(v, l, m, r);
    }
}

int main() {
    vector<int> v = {5, 4, 3, 2, 1};
    merge_sort(v, 0, v.size() - 1);
    for (auto x: v) cout << x << " ";
    cout << endl;

    return 0;
}
