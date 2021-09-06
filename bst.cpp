#include <iostream>
#include <queue>
#include <vector>

using ll = long long int;

struct node {
  int data;
  node *left;
  node *right;
  node *parent;
};

class Tree {
  node *root;
  int sum;

  void print(node *leaf);
  void print_level(node *leaf);
  void Sum(node *leaf);
  bool isBST(node *leaf, int low, int high);

public:
  Tree() {
    sum = 0;
    root = nullptr;
  }
  node *Find(int key, node *leaf);
  void Insert(int key);
  void print();
  void print_level();
  int Sum();
  bool isBST();
};

// Class functions
node *Tree::Find(int key, node *leaf) {
  if (key == leaf->data)
    return leaf;
  else if (key > leaf->data)
    return (leaf->right == nullptr) ? leaf : Find(key, leaf->right);
  else
    return (leaf->left == nullptr) ? leaf : Find(key, leaf->left);
}

void Tree::Insert(int key) {
  node *temp = (node *)malloc(sizeof(node));
  temp->data = key;
  temp->right = nullptr;
  temp->left = nullptr;
  temp->parent = nullptr;
  if (root == nullptr) {
    root = temp;
    return;
  }

  node *insert_at = Find(key, root);

  // insert_at -> right = (insert_at -> data > key) ? temp : insert_at -> left =
  // temp;
  if (insert_at->data < key)
    insert_at->right = temp;
  else
    insert_at->left = temp;
  temp->parent = insert_at;
}

void Tree::print() {
  if (root == nullptr)
    return;
  print(root);
}

void Tree::print(node *leaf) {
  if (leaf == nullptr)
    return;
  printf("%d ", leaf->data);
  print(leaf->left);
  print(leaf->right);
}

void Tree::print_level() {
  if (root == nullptr)
    return;
  print_level(root);
}

void Tree::print_level(node *leaf) {
  if (leaf == nullptr)
    return;
  std::queue<node *> qu;

  node *next_line = (node *)malloc(sizeof(struct node));
  next_line->right = nullptr;
  next_line->left = nullptr;
  next_line->parent = nullptr;
  next_line->data = -1;

  bool was_next_line = false;

  qu.push(leaf);
  qu.push(next_line);

  while (!qu.empty()) {
    auto temp = qu.front();
    qu.pop();

    if (temp->data == -1) {
      printf("\n");
      was_next_line = true;

      if (qu.empty())
        break;

      temp = qu.front();
      qu.pop();
    }

    printf("%d ", temp->data);
    if (was_next_line) {
      qu.push(next_line);
      was_next_line = false;
    }
    if (temp->left != nullptr)
      qu.push(temp->left);
    if (temp->right != nullptr)
      qu.push(temp->right);
  }
}

int Tree::Sum() {
  if (root == nullptr)
    return 0;
  Sum(root);
  return sum;
}

void Tree::Sum(node *leaf) {
  if (leaf == nullptr)
    return;
  sum += leaf->data;
  Sum(leaf->left);
  Sum(leaf->right);
}

bool Tree::isBST(node *leaf, int low, int high) {
  if (leaf == nullptr)
    return true;
  if (low < leaf->data && leaf->data < high) {
    return isBST(leaf->left, low, high - leaf->data) &&
           isBST(leaf->right, low + leaf->data, high);
  }
  return false;
}

bool Tree::isBST() {
  if (root == nullptr)
    return true;
  return isBST(root, -100, 100);
}

// Main function
int main() {
  Tree t;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    t.Insert(num);
  }
  t.print();
  printf("\n");
  t.print_level();
  printf("\n");
  printf(" Sum is : %d\n", t.Sum());

  std::cout << "IS_BST : " << t.isBST() << std::endl;
}
