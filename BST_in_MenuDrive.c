  
/* menu:-Insetion
        -Deletion
        -Search the Node
        -Height of the BST
        -Number of the leaf Node
        -Total number of NODE
        -Display(inorder)*/
 
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *left, *right;

} * node;
node root=NULL;
int h;

int height(node head){
    if(head==NULL)
        return 0;
    int left=height(head->left);
    int right=height(head->right);
    if(left>right){
        h=1+left;
    }
    else
    {
     h=1+right;
    }
    return h;

}

 node InPre(node head) {
    while (head && head->right != NULL){
      head= head->right;
    }
    return head;
}

node InSucc(node head) {
    while (head && head->left!=NULL){
        head= head->left;
    }
    return head;
}
node Delete(node head, int key) {
    node q;

    if (head == NULL){
        return NULL;
    }

    if (head->left == NULL && head->right == NULL){
        if (head == root){
            root = NULL;
        }
        free(head);
        return NULL;
    }

    if (key < head->data){
        head->left= Delete(head->left, key);
    } else if (key > head->data){
        head->right = Delete(head->right, key);
    } else {
        if (height(head->left)>height(head->right)){
            q = InPre(head->left);
            head->data = q->data;
            head->left = Delete(head->left, q->data);
        } else {
            q = InSucc(head->right);
            head->data = q->data;
            head->right = Delete(head->right, q->data);
        }
    }
    return head;
}


int count_leaves(node head){
  if(head==NULL){
    return 0;
  }
  if(head->left==NULL&&head->right==NULL)
  {

    return 1;
  }
  else
    return count_leaves(head->left)+count_leaves(head->right);

}



int tcount(node temp){

    int l,r;
    if(temp==NULL){
        return 0;
    }
    else{
        l=tcount(temp->left);
        r=tcount(temp->right);
        return (1+l+r);
    }
}

int search(node head,int key){
    if(head==NULL){
        return 0;

    }
    if(head->data==key){
        return 1;

    }
    else if(head->data>key){
        search(head->left,key);
    }
  else if(head->data<key)
  {

    search(head->right,key);

  }

}

node  create(int k){
    node newnode;
    newnode=(node)malloc(sizeof(struct Node));
    newnode->data=k;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

node insert(node head,int k){
    if(head==0){
        return create(k);
    }
     if(k<head->data){
        head->left=insert(head->left,k);
    }
    else if(k>head->data){
        head->right=insert(head->right,k);
    }
    return head;

}

void inorder(node root){

    if(root!=NULL){
      inorder(root->left);
      printf("%d\n",root->data);
      inorder(root->right);
    }


}

int main(){

    //node root=NULL;
int a,b,f,h,u,x;
    while(1){
            printf("1>insert\n2>display\n3>cnt the leaf nodes\n4>height\n5>search\n6>total count\n7>delete\n8>exit\n");
    scanf("%d",&a);
        switch(a){
            case 1:printf("enter the element to insert");
                   scanf("%d",&b);
                  root=insert(root,b);
                  break;
            case 2:inorder(root);
                   break;
            case 3:
                   printf("%d\n",count_leaves(root));
                   break;
            case 4: printf("%d\n",height(root));
                    break;
            case 5:printf("enter the element to search");
                    scanf("%d",&h);
                    int y=search(root,h);
                    if(y==1)
                        printf("element found\n");
                        else
                            {printf("element not found\n");

                    }
                    break;
            case 6: u=tcount(root);
                           printf("%d\n",u);
                           break;
            case 7:printf("enter the element to delete");
                           scanf("%d",&x);
                           root=Delete(root,x);
                           break;
            case 8:exit(0);

            default:printf("invalid");
        }
    }






}
