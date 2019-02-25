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

node *insert(node *root, int key) {
  if (root == NULL) {
    return newNode(key);
  }
  else {
    node *temp = root;
    //*collisions = *collisions + 1;
    while (temp->next != NULL) {
      if (key == temp->num) {
        return root;
      }
      //printf("%s\n", "insert loop");
      temp = temp->next;
    }

    //printf("%s\n", "insert 2");
    temp->next = newNode(key);
    return root;
  }
}

int search(node *root, int key) {
  if (root == NULL) {
    return 0;
  }
  else {
    node *temp = root;
    while (temp != NULL) {
      if (temp->num == key) {
        //printf("search num: %d\n", key);
        return 1;
      }
      temp = temp->next;
    }
    return 0;
  }
}

int main(int argc, char **argv) {
  FILE *fp = fopen(argv[1], "r");
  node *hashtable[10000];
  int i;
  for (i = 0; i < 10000; i++) {
    hashtable[i] = NULL;
  }
  if (!fp) {
    return 0;
  }

  char var;
  int item;
  int key;
  int searches = 0;
  int collisions = 0;
  //node *head;

  while (!feof(fp)) {
    fscanf(fp, "%c\t", &var);
    fscanf(fp, "%d\n", &item);

    key = item % 10000;
    if (key < 0) {
      key = key * -1;
    }

    if (var == 'i') {
      if (hashtable[key] == NULL) {
        node *temp = NULL;
        hashtable[key] = insert(temp, item);
      }
      else {
        node *temp = hashtable[key];
        hashtable[key] = insert(temp, item);
        collisions++;
      }
    }
    else {
      searches = searches + search(hashtable[key], item);
      //printf("search method: %d\n", searches);
    }
  }

  /*node *temp2 = hashtable[1];
  while (temp2 != NULL) {
    printf("printing: %d\n", temp2->num);
    temp2 = temp2->next;
  }*/
  printf("%d\n", collisions);
  printf("%d\n", searches);

  for (i = 0; i < 10000; i++) {
    free(hashtable[i]);
  }
  fclose(fp);
  return 0;
}
