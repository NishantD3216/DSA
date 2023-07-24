#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *left, *right;
};
struct node *newNode (int item)
{
  struct node *temporary = (struct node *) malloc (sizeof (struct node));
  temporary->data = item;
  temporary->left = temporary->right = NULL;
  return temporary;
}

// Here we print the preorder recursively
void preorder (struct node *root, FILE *fp2)
{
  if (root != NULL)
    {
      printf ("%d ", root->data);
      fprintf (fp2,"%d ", root->data);
      preorder (root->left,fp2);
      preorder (root->right,fp2);
    }
}

void inorder (struct node *root, FILE *fp4)
{
  if (root != NULL)
    {
      inorder (root->left,fp4);
      printf ("%d ", root->data);
      fprintf (fp4,"%d ", root->data);
      inorder (root->right,fp4);
    }
}

void postorder (struct node *root, FILE *fp3)
{
  if (root != NULL)
    {
      postorder (root->right,fp3);
      printf ("%d ", root->data);
      fprintf (fp3,"%d ", root->data);
      postorder (root->left,fp3);
    }
}

struct node *insert (struct node *node, int data)
{
  if (node == NULL)
    return newNode (data);
  if (data < node->data)
    node->left = insert (node->left, data);
  else if (data > node->data)
    node->right = insert (node->right, data);

  return node;
}

int main ()
{
  struct node *root = NULL;
  root = insert (root, 9);
  int rnum;
  FILE *fp1,*fp2,*fp3,*fp4;
  int upper=100,lower=1;
  fp1=fopen("random.txt","w");
  fp2=fopen("pre_order.txt","w");
  fp3=fopen("post_order.txt","w");
  fp4=fopen("in_order.txt","w");
  printf("Random numbers are\n");
  for(int i=0;i<10;i++)
  {

      printf("%d\t",rnum);
      rnum = (rand()%(upper-lower+1))-lower;
      fprintf(fp1,"%d ",rnum);
      insert (root, rnum);
  }

  int ch;
  while(1)
  {
      printf("\n 1.Display Pre order 2. Display post order 3. Display in order 4. Exit\n");
      scanf("%d",&ch);
      switch(ch)
        {
      case 1:printf ("The pre order is :\n");
        preorder (root,fp2);
        break;
      case 2:printf("The post order is :\n");
        postorder(root,fp3);
        break;
      case 3:printf("The in order is :\n");
        inorder(root,fp4);
        break;
      case 4: exit(0);
        }
  }
  fclose(fp1);
  fclose(fp2);
  fclose(fp3);
  fclose(fp4);
  return 0;

}
