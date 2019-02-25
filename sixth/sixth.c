#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int num;
  struct node *left;
  struct node *right;
}node;

node *newNode(int item){
  struct node *root = (node*)malloc(sizeof(node));
  root->num = item;
  root->left = NULL;
  root->right = NULL;
  return root;
}

void printInOrder(node *root)
{
    if (root != NULL)
    {
        printInOrder(root->left);
        printf("%d\t", root->num);
        printInOrder(root->right);
    }
}

node *insert(node *root, int key) {
  if (root == NULL) {
    return newNode(key);
  }

  if (key < root->num) {
    root->left = insert(root->left, key);
  }
  else if (key > root->num) {
    root->right = insert(root->right, key);
  }

  return root;
}

int main(int argc, char **argv) {
  FILE *fp = fopen(argv[1], "r");

  if (!fp) {
    printf("%s\n", "error");
    return 0;
  }

  char var;
  int item;
  node *head;

  fscanf(fp, "%c\t", &var);
  fscanf(fp, "%d\n", &item);
  if (var == 'i') {
    head = newNode(item);
  }

  while (!feof(fp)) {
    fscanf(fp, "%c\t", &var);
    fscanf(fp, "%d\n", &item);

    if (var == 'i') {
      head = insert(head, item);
    }
  }

  printInOrder(head);

  fclose(fp);
  return 0;
}
