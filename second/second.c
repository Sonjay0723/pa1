#include<stdio.h>
#include<stdlib.h>

typedef struct node {
  int num;
  struct node *next;
}node;

node *newNode(int item) {
  struct node *root = (node*)malloc(sizeof(node));
  root->num = item;
  root->next = NULL;
  return root;
}

node *insert(node *root, int key, int *count) {
  //printf("%s\n", "insert");
  node *new = newNode(key);
  if (root == NULL) {
    *count = *count + 1;
    return newNode(key);
  }
  else if (key < root->num) {
    new->next = root;
    *count = *count + 1;
    //printf("insert count: %d\n", *count);
    return new;
  }
  else {
    node *temp = root;
    while (temp->next != NULL && key > temp->next->num) {
      temp = temp->next;
    }

    new->next = temp->next;
    temp->next = new;
    *count = *count + 1;
    //printf("insert count: %d\n", *count);
    return root;
  }
}

node *delete(node *root, int key, int *count) {
  //printf("%s\n", "delete");
  if (root == NULL) {
    return root;
  }

  node *temp = root;
  if (key == temp->num) {
    root = temp->next;
    free(temp);
    *count = *count - 1;
    //printf("delete count: %d\n", count);
    return root;
  }

  while (temp->next != NULL) {
    //printf("%s\n", "while delete");
    if (key == temp->next->num) {
      node *temp2 = temp->next;
      temp->next = temp->next->next;
      free(temp2);
      *count = *count - 1;
      //printf("delete count: %d\n", count);
      break;
    }
    temp = temp->next;
  }

  return root;
}

int main(int argc, char **argv) {
  FILE *fp = fopen(argv[1], "r");
  char var;
  int item;
  int count = 0;

  if (!fp) {
    return 0;
  }

  node *head;
  while (!feof(fp)) {
    fscanf(fp, "%c\t", &var);
    fscanf(fp, "%d\n", &item);

    if (var == 'i') {
      count++;
      head = newNode(item);
      break;
    }
  }

  //printf("%s\n", "done 1");
  //int *countPtr = &count;
  while (!feof(fp)) {
    fscanf(fp, "%c\t", &var);
    fscanf(fp, "%d\n", &item);

    if (var == 'i') {
      head = insert(head, item, &count);
    }
    else {
      head = delete(head, item, &count);
    }
  }

  printf("%d\n", count);
  if (count == 0) {
    return 0;
  }
  //printf("*: %d\n", *count);
  //printf("&: %d\n", &count);
  node *temp = head;
  node *temp2;
  while (temp->next != NULL) {
    //printf("%s\n", "loop");
    if (temp->next != NULL && temp->num != temp->next->num) {
      printf("%d\t", temp->num);
    }
    temp2 = temp;
    temp = temp->next;
    free(temp2);
  }
  printf("%d\n", temp->num);

  fclose(fp);
  return 0;
}
