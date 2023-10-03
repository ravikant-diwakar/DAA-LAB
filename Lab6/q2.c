#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent characters and their frequencies
struct SYMBOL {
    char alphabet;
    int frequency;
};

// Define a structure for a node in the Huffman tree
struct Node {
    char alphabet;
    int frequency;
    struct Node *left;
    struct Node *right;
};

// Function to perform in-order traversal of the Huffman tree and print the characters
void inOrderTraversal(struct Node *root) {
    if (root) {
        inOrderTraversal(root->left);
        if (root->alphabet != '-')
            printf("%c ", root->alphabet);
        inOrderTraversal(root->right);
    }
}

// Function to create a new node for the Huffman tree
struct Node *createNode(char alphabet, int frequency) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->alphabet = alphabet;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to construct the Huffman tree
struct Node *constructHuffmanTree(struct SYMBOL arr[], int n) {
    struct Node *nodes[n];
    
    // Create nodes for each symbol
    for (int i = 0; i < n; i++) {
        nodes[i] = createNode(arr[i].alphabet, arr[i].frequency);
    }
    
    while (n > 1) {
        int min1 = 0, min2 = 1;
        
        // Find two nodes with the lowest frequencies
        for (int i = 2; i < n; i++) {
            if (nodes[i]->frequency < nodes[min1]->frequency) {
                min2 = min1;
                min1 = i;
            } else if (nodes[i]->frequency < nodes[min2]->frequency) {
                min2 = i;
            }
        }
        
        // Create a new node with '-' as the alphabet to represent internal nodes
        struct Node *internalNode = createNode('-', nodes[min1]->frequency + nodes[min2]->frequency);
        internalNode->left = nodes[min1];
        internalNode->right = nodes[min2];
        
        // Remove the used nodes and add the internal node
        nodes[min1] = internalNode;
        nodes[min2] = nodes[n - 1];
        n--;
    }
    
    struct Node *huffmanRoot = nodes[0];
    return huffmanRoot;
}

int main() {
    int n;
    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);

    struct SYMBOL *symbols = (struct SYMBOL *)malloc(n * sizeof(struct SYMBOL));

    printf("Enter the alphabets: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &symbols[i].alphabet);
    }

    printf("Enter its frequencies: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &symbols[i].frequency);
    }

    // Construct the Huffman tree
    struct Node *huffmanRoot = constructHuffmanTree(symbols, n);

    // Perform in-order traversal of the Huffman tree
    printf("In-order traversal of the tree (Huffman): ");
    inOrderTraversal(huffmanRoot);
    printf("\n");

    // Clean up memory
    free(symbols);

    return 0;
}
