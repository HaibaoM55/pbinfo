#include <bits/stdc++.h>
using namespace std;
ifstream fin("aemi.in");
ofstream fout("aemi.out");
int n, m, t, a, b, v[100005];

struct _Heap {
  _Heap *right_child, *left_child, *parent;
  int value;
};

int get_best_child(_Heap *child_left, _Heap *child_right) {
  return min(child_left->value, child_right->value);
}
void init_heap(_Heap *Node, int left, int right) {
  if(left == right)
    Node->value = v[left];
  else {
    int mid = (left + right) / 2;
    _Heap *new_child_left = new _Heap();
    _Heap *new_child_right = new _Heap();
    Node->left_child = new_child_left;
    Node->right_child = new_child_right;
    init_heap(Node->left_child, left, mid);
    init_heap(Node->right_child, mid + 1, right);
    Node->value = get_best_child(Node->left_child, Node->right_child);
  }
}
void update_heap(_Heap *Node, int left, int right, int pos_query, int value_query) {
  if(left == pos_query && right == pos_query) {
    Node->value = value_query;
  } else {
    int mid = (left + right) / 2;
    if(pos_query <= mid)
      update_heap(Node->left_child, left, mid, pos_query, value_query);
    else
      update_heap(Node->right_child, mid + 1, right, pos_query, value_query);
    Node->value = get_best_child(Node->left_child, Node->right_child);
  }
}
int query_heap(_Heap *Node, int left, int right, int query_left, int query_right) {
  if((query_left <= left  && right <= query_right))
    return Node->value;
  else {
    int mini = INT_MAX, mid = (left + right) / 2;
    if(query_left <= mid)
      mini = min(mini, query_heap(Node->left_child, left, mid, query_left, query_right));
    if(query_right > mid)
      mini = min(mini, query_heap(Node->right_child, mid + 1, right, query_left, query_right));
    return mini;
  }
}
int main() {
  fin >> n;
  for(int i = 1; i <= n; i++)
    fin >> v[i];
  _Heap *root = new _Heap();
  root->parent = NULL;
  init_heap(root, 1, n);
  fin >> m;
  for(int i = 1; i <= m; i++) {
    fin >> t >> a >> b;
    if(t == 1) { // query
      fout << query_heap(root, 1, n, a, b) << '\n';
    } else {
      update_heap(root, 1, n, a, b);
    }
  }
  return 0;
}
