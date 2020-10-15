/** BY @OscarScrooge*/

typedef struct NODE{
   int id;
  struct NODE *leftChild;
  struct NODE *rightChild;
}NODE;

void chart(NODE *root){
    //system("cls");
    FILE* file;
    file = fopen("tree.dot", "wt");
    fputs("digraph Tree{\n", file);
    if(root != 0){
        graf(root, file);
    }else{
        fputs("Empty", file);
    }
    fputs("}", file);
    fclose(file);
    system("dot -Tpng tree.dot -o tree.png");
    printf("\nBINARY TREE CREATED IN YOUR DIRECTORY \n");
    return;
}

void graf(NODE *root, FILE* file){
    if(root != 0){
        if(root->leftChild != 0){
            chartTreeS(root, root->leftChild, file);
            graf(root->leftChild, file);
        }
        if(root->rightChild  != 0){
            chartTreeS(root, root->rightChild, file);
            graf(root->rightChild, file);
        }

        if(root->leftChild == 0 && root->rightChild == 0){
            int n = root->id;
            char * cad = malloc(12 * sizeof(char));
            sprintf(cad, "%i", n);
            fputs(cad, file);
            fputs("\n", file);
        }
    }
}

void chartTreeS(NODE *root, NODE *hijo, FILE* file){
    int n = root->id;
    int n2 = hijo->id;
    char * cad = malloc(12 * sizeof(char));
    char * cad2 = malloc(12 * sizeof(char));
    sprintf(cad, "%i", n);
    sprintf(cad2, "%i", n2);
    fputs(cad, file);
    fputs("->", file);
    fputs(cad2, file);
    fputs("\n", file);
}
