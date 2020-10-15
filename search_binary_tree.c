/** BY @OscarScrooge*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "treechart.h"


NODE *newNode();
NODE *addNode(NODE* root, int id);
NODE *deleteNode(NODE *root,int id);
void preorder(NODE *root);
void inorder(NODE *root);
void posorder(NODE *root);
int heigh(NODE *root);

int main() {

  NODE *root=NULL;
  int i =1;
  int id=1, toDelete, toFind;

   while(i!=0){
      printf("\n ID: ");
      scanf("%d",&id);
      root = addNode(root,id);
      printf("\nDo you want continue?: 1: YES  0: NO: ");
      scanf("%d",&i);

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
    printf("\n Delete node: ");
    scanf("%d", &toDelete);
    deleteNode(root,toDelete);
    chart(root);
  return 0;
}

NODE *addNode(NODE* root, int id){

   if(root==NULL){
       root = newNode(id);
   }else{
     if(id>root->id){
          root->rightChild=addNode(root->rightChild,id);
     }else{
          root->leftChild=addNode(root->leftChild,id);
     }

   }

   return root;

}

NODE *newNode(int id){

        NODE *newNode = NULL;
        newNode = malloc(sizeof(NODE));
        newNode->id = id;
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

NODE *deleteNode(NODE *root,int id){
      bool bo = false;
      NODE *otro=NULL,*aux=NULL,*aux1=NULL;

      if(root!=NULL){
         if( id < root->id){
            root->leftChild= deleteNode(root->leftChild,id);
         }else if( id > root->id){
            root->rightChild= deleteNode(root->rightChild,id);
         }else{
            otro = root;
            if(otro->rightChild == NULL){
               root = otro -> leftChild;
            }else if(otro->leftChild == NULL){
               root = otro -> rightChild;
            }else{
               aux = root->leftChild;
               bo= false;
               while( aux-> rightChild !=NULL){
                   aux1 = aux;
                   aux = aux->rightChild;
                   bo = true;
               }
               root->id = aux->id;
               otro = aux;
               if(bo==true){
                  aux1->rightChild= aux->leftChild;
               }else{
                  root->leftChild = aux->leftChild;
               }
            }
         }
         free(otro);
      }else{
        printf("\nID not founded\n");
      }
      return root;
}

