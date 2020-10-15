/** BY @OscarScrooge*/

#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "treeChart.h"


NODE* newNode(int id);
NODE* add(NODE* node, int id);
NODE* deleteNode(NODE* root, int id);
NODE *rebalance(NODE *root);
NODE* rightRotation(NODE* node);
NODE* leftRotation(NODE* node);
NODE* rightLeftRotation(NODE* node);
NODE* leftRightRotation(NODE* node);
int getBalance(NODE *node);
int search(NODE *root, int valor);
int heigh(NODE *root);
void options(NODE *root);


int main()
{
  NODE *root = NULL;
  options(root);
  return 0;
}


void options(NODE *root){
    int option = 0,i=0;
    int toDelete,toFind;
    int treeValues[17]={58,43,75,86,65,70,67,73,93,69,25,66,68,47,62,10,60};
    printf("\nChoose and option:\n1- Add Node\n2- Delete node\n3- Search node\n4- Exit\nOption: ");
    scanf("%d", &option);
    switch(option){
    case 1:
        system("cls");
        while(i <17){
                root = add(root, treeValues[i]);
                chart(root);
                i++;
        }
        system("cls");
        options(root);
        break;
    case 2:
        system("cls");
            printf("ID of node to delete: ");
            scanf("%d", &toDelete);
            if(toDelete!=0){
                 root = deleteNode(root, toDelete);
                 chart(root);
            }

        options(root);
        break;
    case 3:
        system("cls");
        printf("ID of node to search: ");
        scanf("%d", &toFind);
        int find = search(root, toFind);
        if(find == 0){
            printf("ID %d not founded\n", toFind);
        }else{
            printf("ID %d founded\n", toFind);
        }
        printf("\nPress enter to continue...\n");
        getchar();
        getchar();
        options(root);
        break;
    case 4:
        system("cls");
        printf("Exit\n");
        system("exit");
        break;
    default:
        printf("\nChoose the right option\n");
        getchar();
        getchar();
        options(root);
    }
}

NODE* add(NODE* node, int id)
{

    if (node == NULL){
        return(newNode(id));
    }else{
        if(search(node, id) == 0){
            if (id < node->id){
                node->leftChild  = add(node->leftChild, id);
            }else if (id > node->id){
                node->rightChild = add(node->rightChild, id);
            }
            else{
                printf("node duplicated\n");
                return node;
            }
            node = rebalance(node);

        }else{
            printf("node duplicated\n");
            printf("\nPress enter to continue...\n");
            getchar();
            getchar();
        }
    }
    return node;
}

NODE* newNode(int id)
{
    NODE* newNode = (NODE*) malloc(sizeof(NODE));
    newNode->id   = id;
    newNode->leftChild  = NULL;
    newNode->rightChild = NULL;
    return(newNode);
}

NODE *rebalance(NODE *root){

     NODE *node = root;


               int balanceFactor = getBalance(node);


              if(balanceFactor < -1){

                       balanceFactor =  getBalance(node->leftChild);
                       if(balanceFactor <=0){
                            /*LEFT ROTATION*/
                          return leftRotation(node);
                      }else{
                           /*LEFT-RIGHT  ROTATION*/
                          return rightLeftRotation(node);
                      }


              }else if(balanceFactor >1){

                       balanceFactor =  getBalance(node->rightChild);
                       if(balanceFactor >=0){
                            /*LEFT ROTATION*/
                            return rightRotation(node);
                       }else{
                           /*RIGHT-LEFT ROTATION*/
                           return leftRightRotation(node);

                       }

              }

       return node;
}

NODE* deleteNode(NODE* root, int id){
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
                      root->leftChild = rebalance(  root->leftChild);
                   }else{
                      root->leftChild = aux->leftChild;
                   }
                }
    			free(otro);
             }
             if(root!= NULL){
                root = rebalance(root);
             }

          }else{
            printf("\nID not founded\n");
          }
          return root;
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


NODE* rightRotation(NODE* node){

    NODE* node1;
    node1 = node->rightChild;
    node->rightChild = node1->leftChild;
    node1 ->leftChild = node;
    return node1;

}

NODE* leftRotation(NODE* node){

    NODE* node1;
    node1 = node ->leftChild;
    node->leftChild = node1->rightChild;
    node1 ->rightChild = node;
    return node1;

}

NODE* rightLeftRotation(NODE* node){

    NODE* node1;
    NODE* node2;

    node1 = node ->leftChild;
    node2 = node1 -> rightChild;

    node1->rightChild = node2->leftChild;
    node2 ->leftChild = node1;
    node->leftChild = node2->rightChild;
    node2->rightChild = node;

    return node2;
}

NODE* leftRightRotation(NODE* node){

    NODE* node1;
    NODE* node2;

    node1 = node ->rightChild;
    node2 = node1 -> leftChild;

    node1->leftChild = node2->rightChild;
    node2 ->rightChild = node1;
    node->rightChild = node2->leftChild;
    node2->leftChild = node;
    return node2;
}

int getBalance(NODE *node)
{
    if (node == NULL){
        return 0;
    }
    int al;
    al= heigh(node->rightChild) - heigh(node->leftChild) ;
    return al;
}

int search(NODE *root, int valor){

    if(root == 0){
        return 0;
    }else{
        if(root->id == valor){
            return 1;
        }else{
            if(valor > root->id && root->rightChild != 0){
                return  search(root->rightChild, valor);
            }else if(valor < root->id && root->leftChild != 0){
                return search(root->leftChild, valor);
            }
        }
    }
    return 0;
}

