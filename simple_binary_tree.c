/** BY @OscarScrooge*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "treechart.h"


NODE *newNode();
NODE *addNode(NODE* root);
void preorder(NODE *root);
void inorder(NODE *root);
void posorder(NODE *root);
int heigh(NODE *root);

int main() {

  NODE *root=NULL;
  int i =0;

   while(i<2){

      root = addNode(root);
      i++;
    }
    printf("\nTree heigh: ");
    printf("%d ",heigh(root));
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPosorder: ");
    posorder(root);
    printf("\nInorder: ");
    inorder(root);

    chart(root);
  return 0;
}

NODE *addNode(NODE* root){

  int resp;

  if(root==NULL){
    printf("Add a root \n");
    root = newNode();
  }else{

      printf("Add left node? 1 YES -0 NO: ");
      scanf("%d",&resp);
      if(resp==1){
        root->leftChild=newNode();
        root->leftChild = addNode(root->leftChild);
      } else{
        root->leftChild=NULL;
      }

      printf("Add right node? 1 YES -0 NO: ");
      scanf("%d",&resp);
      if(resp==1){
        root->rightChild=newNode();
        root->rightChild = addNode(root->rightChild);
      } else{
        root->rightChild=NULL;
      }
  }



  return root;

}

NODE *newNode(){

        NODE *newNode = NULL;
        newNode = malloc(sizeof(NODE));
        printf("ID: ");
        scanf("%d",&newNode->id);
        newNode->leftChild=NULL;
        newNode->rightChild=NULL;

        return newNode;
}

void preorder(NODE *root){

     if(root!=NULL){
         printf("%d  ",root->id);
         preorder(root->leftChild);
         preorder(root->rightChild);
     }

}

void inorder(NODE *root){

     if(root!=NULL){
         inorder(root->leftChild);
         printf("%d  ",root->id);
         inorder(root->rightChild);
     }
}

void posorder(NODE *root){

      if(root!=NULL){
              posorder(root->leftChild);
              posorder(root->rightChild);
              printf("%d  ",root->id);
      }
}

int heigh(NODE *root){
      int h=0;
      if(root!=NULL){
          int hi=0,hd=0;
          hi++;
          hi+=heigh(root->leftChild);
          hd++;
          hd+=heigh(root->rightChild);
          if(hi>hd){
             h = hi;
          }else{
             h= hd;
          }

      }
    return h;
}

