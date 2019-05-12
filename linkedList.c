#include <stdio.h>
#include <stdlib.h>

#define TRUE    1
#define FALSE   0

struct node {
    int value;
    struct node *next;
};

typedef struct node _node;

_node *addElement(int element, _node *root) {
    _node *newNode, *aux;
    
    newNode = (_node *) malloc(sizeof(_node));
    
    if (newNode != NULL) {
        newNode->value = element;
        newNode->next = NULL;
        
        if (root == NULL) {
            root = newNode;
        } else {   
            aux = root;
        
            while (aux->next != NULL) {
                aux = aux->next;
            }
            
            aux->next = newNode;    
        }
    }
    
    return root;
}

_node *removeElement(int element, _node *root) {
    _node *nodeToremoveElement, *aux;
    
    if (root != NULL) {
        if (root->value == element) {
            nodeToremoveElement = root;
            root = root->next;
            
            free(nodeToremoveElement);
        } else {
            aux = root;
            
            while (aux->next != NULL && aux->next->value != element) {
                aux = aux->next;
            }
                
            if (aux->next != NULL) {
                nodeToremoveElement = aux->next;
                aux->next = nodeToremoveElement->next;
                free(nodeToremoveElement);
            }
        }
    }
    
    return root;
}

void print(_node *root) {
    _node *aux;
    
    aux = root;
    
    printf("root -> ");
    
    while (aux != NULL) {
        printf("%d -> ", aux->value);
        aux = aux->next;
    }
    
    printf("NULL\n");
}

_node *end(_node *root) {
    _node *aux;
    
    aux = root;
    
    if (root != NULL) {
        while (aux->next != NULL) {
            aux = aux->next;
        }
    }
    
    return aux;
}

int size(_node *root) {
    _node *aux;
    int size = 0;
    
    aux = root;
    
    if (root != NULL) {
        while (aux != NULL) {
            size++;
            aux = aux->next;
        }
    }
    
    return size;
}

int main() {
    _node *root, *lastNode;
    
    root = NULL;
    
    root = addElement(5, root);
    root = addElement(11, root);
    root = addElement(3, root);
    root = addElement(2, root);
    root = addElement(1, root);
    root = addElement(9, root);
    root = addElement(50, root);
    root = addElement(30, root);
    root = addElement(53, root);
    
    print(root);
        
    printf("size: %d\n", size(root));
    
    lastNode = end(root);
    
    if (lastNode != NULL) {
        printf("last node: %d\n", lastNode->value);
    }
    else {
        printf("the list is empty\n");
    }

    root = removeElement(9, root);
    print(root);
    
    return EXIT_SUCCESS;
}
