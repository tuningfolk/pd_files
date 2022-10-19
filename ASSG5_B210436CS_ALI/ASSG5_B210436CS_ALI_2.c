#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    char key;
    struct node* head;
    struct node* next;
}node;



node* LIST_SEARCH(node* root, char k);
void LIST_INSERT_AFTER(node* root, char k, char n);
void LIST_INSERT_BEFORE(node** root, char k, char n);
void LIST_DELETE(node** root, char k);
node* prev_node(node* root, char n);
node* CREATE_NODE(char k);
void PRINT_LIST(node* root);
void free_list(node* root);
void LIST_INSERT_FRONT(node** root, char k);
void LIST_INSERT_TAIL(node** root, char k);
void LIST_DELETE_FIRST(node** root);
void LIST_DELETE_LAST(node** root);

int main(){
    char ch; char k; char n;
    node* root = NULL;
    // scanf("%c %c", &ch, &k);
    scanf("%c", &ch);
    // printf("\n");
    while(ch!='e'){  
            
        if(ch == 'f'){
            scanf(" %c", &k);
            LIST_INSERT_FRONT(&root, k);
        }else if(ch == 't'){
            scanf(" %c", &k);
            LIST_INSERT_TAIL(&root, k);
        }else if (ch == 'p'){
            PRINT_LIST(root);
        }else if(ch =='i'){
            LIST_DELETE_FIRST(&root);
        }else if(ch == 'l'){
            LIST_DELETE_LAST(&root);
        }
        //q2
        else if(ch == 'a'){
            scanf(" %c %c", &k, &n);
            LIST_INSERT_AFTER(root, k, n);
        }else if(ch == 'b'){
            scanf(" %c %c", &k, &n);
            LIST_INSERT_BEFORE(&root, k, n);
        }else if(ch == 'd'){
            scanf(" %c", &k);
            LIST_DELETE(&root, k);
        }
        
        scanf("%c", &ch);
        if(ch == 'e'){
            free_list(root);
            return 0;
        }
    }
    
}

void LIST_DELETE(node** root, char k){
    node* n = LIST_SEARCH(*root, k);
    if(n == NULL){
        printf("ABSENT\n");
        return;
    }
    if(n == *root){
        node* ptr = *root;
        *root = (*root)->next;
        if(*root!=NULL){
            printf("%c\n", (*root)->key);
        }else{
            printf("LAST\n");
        }
        free(ptr);
        return;
    }else if(n->next == NULL){
        node* ptr = *root;
        while(ptr->next->next!=NULL){ //while ptr isnt the second last node
            ptr = ptr->next;
        }
        //ptr becomes the second last node
        printf("LAST\n");
        ptr->next = NULL;
        free(ptr->next);
        return;
    }
    node* before = prev_node(*root, k);
    node* after = n->next;
    free(n);
    before->next = after;
    printf("%c\n", after->key);
}

void LIST_INSERT_BEFORE(node** root, char k, char n){
    if(*root == NULL){
        printf("NULL\n");
        return;
    }
    if((*root)->key == n){
        LIST_INSERT_FRONT(root, k);
        return;
    }
    node* before = prev_node(*root, n);
    if(before == NULL){
        printf("ABSENT\n");
        return;
    }
    LIST_INSERT_AFTER(*root, k, before->key);

}
void LIST_INSERT_AFTER(node* root, char k, char n){
    if(root == NULL){
        printf("NULL\n");
        return;
    }
    node* ptr = LIST_SEARCH(root, n);
    if(ptr == NULL){
        printf("ABSENT\n");
        return;
    }
    node* new = CREATE_NODE(k);
    new->head = root;
    new->next = ptr->next;
    ptr->next = new; 
    
}

node* LIST_SEARCH(node* root, char k){
    if(root == NULL){
        return NULL;
    }
    if (root->key == k){
            return root;
    }else return LIST_SEARCH(root->next, k);
}

node* prev_node(node* root, char n){
    if(root->next->key != n){
        return prev_node(root->next, n);
    }
    else if(root->next->key == n){
        return root;
    }else if(root == NULL){
        return NULL;
    }
}

node* CREATE_NODE(char k){
    node* n = malloc(sizeof(node));
    n->head = NULL;
    n->next = NULL;
    n->key = k;
    return n;
}
 
void PRINT_LIST(node* root){
    if(root == NULL){
        printf("NULL\n");
        return;
    }
    while(root!=NULL){
        printf("%c ", root->key);
        root=root->next;
    }printf("\n");
    
}

void free_list(node* root){
    if(root == NULL) return;
    node* ptr = root->next;
    while(root!=NULL){
        free(root);
        root = ptr;
    }
}

void LIST_INSERT_FRONT(node** root, char k){
    if(*root == NULL){
        *root = CREATE_NODE(k);
        (*root)->next = NULL;
        (*root)->head = NULL;
        return;
    }
    node* n = CREATE_NODE(k);
    n->next = *root;
    n->head = NULL;

    //changing the root variable to the new node
    *root = n;

    //setting the head to the new node in every struct variable
    node* ptr = (*root)->next;
    while(ptr!=NULL){
        ptr->head = *root;
        ptr = ptr->next;
    }
}

void LIST_INSERT_TAIL(node** root, char k){
    if(*root == NULL){
        *root = CREATE_NODE(k);
        (*root)->next = NULL;
        (*root)->head = NULL;
        return;
    }
    node* n = CREATE_NODE(k);
    n->next = NULL;
    n->head = *root;
    node* ptr = *root;
    while(ptr->next !=NULL){
        ptr = ptr->next;
    }
    ptr->next = n;
}

void LIST_DELETE_FIRST(node** root){
    if(*root == NULL){
        printf("NULL\n");
        return;
    };
    node* ptr = *root;
    *root = (*root)->next;
    printf("%c\n", ptr->key);
    free(ptr);

}

void LIST_DELETE_LAST(node** root){
    if(*root == NULL){
        printf("NULL\n");
        return;
    };
    node* ptr = *root;
    while(ptr->next->next!=NULL){ //while ptr isnt the second last node
        ptr = ptr->next;
    }
    //ptr becomes the second last node
    printf("%c\n", ptr->next->key);
    ptr->next = NULL;
    free(ptr->next);
}
