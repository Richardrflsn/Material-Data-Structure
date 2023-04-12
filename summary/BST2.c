#include <stdio.h>
#include <stdlib.h>

struct Node{
	int key;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
};

struct Node *ROOT = NULL;

struct Node* create_node(int key){
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	node->key = key;
	node->left = node->right = node->parent = NULL;
	return node;
}

struct Node* insert(struct Node *curr, int key){
	if( !curr ){
		return create_node(key);
	}
	else if( key == curr->key ){
		printf("Duplicate key: %d! Terminate insert process!\n", key);
	}
	else if( key < curr->key ){
		struct Node *leftChild = insert(curr->left, key);
		curr->left = leftChild;
		leftChild->parent = curr;
	}
	else if( key > curr->key ){
		struct Node *rightChild = insert(curr->right, key);
		curr->right = rightChild;
		rightChild->parent = curr;
	}
	
	return curr;
}

void pre_order(struct Node *curr){
	if( curr ){
		printf("%d ", curr->key);
		pre_order(curr->left);
		pre_order(curr->right);
	}
}

void post_order(struct Node *curr){
	if ( curr )
	{
		post_order(curr->left);
		post_order(curr->right);
		printf("%d ", curr->key);
	}
	
}

void in_order(struct Node *curr){
	if( curr ){
		in_order(curr->left);
		printf("%d ", curr->key);
		in_order(curr->right);
	}
}

struct Node* getRightMostNode(struct Node *curr){
	struct Node *temp = curr->left;
	while(temp->right){
		temp = temp->right;
	}
	return temp;
}

struct Node* delete_node(struct Node *curr, int key){
	if( !ROOT ){
		printf("There is no data!\n");
	}
	else if( !curr ){
		printf("Data does not exist!\n");
	}
	else if( key < curr->key ){
		curr->left = delete_node(curr->left, key);
	}
	else if( key > curr->key ){
		curr->right = delete_node(curr->right, key);
	}
	else if( key == curr->key ){
		if( !curr->left && !curr->right ){
			free(curr);
			curr = NULL;
		}
		else if( !curr->left ){
			struct Node *replacement = curr->right;
			replacement->parent = curr->parent;
			free(curr);
			return replacement;
		}
		else if( !curr->right ){
			struct Node *replacement = curr->left;
			replacement->parent = curr->parent;
			free(curr);
			return replacement;
		}
		else{
			struct Node *replacement = getRightMostNode(curr);
			curr->key = replacement->key;
			curr->left = delete_node(curr->left, replacement->key);
		}
	}
	return curr;
}

int main(){
	
	ROOT = insert(ROOT, 50); 
    ROOT = insert(ROOT, 30);
    ROOT = insert(ROOT, 20);
    ROOT = insert(ROOT, 40);
    ROOT = insert(ROOT, 70);
    ROOT = insert(ROOT, 60);
    ROOT = insert(ROOT, 80);
//	ROOT = insert(ROOT, 80);
	printf("inorder BST: ");
	in_order(ROOT);
	printf("\npreorder BST: ");
	pre_order(ROOT);
	printf("\npostorder BST: ");
	post_order(ROOT);
	
	printf("\n");

	ROOT = delete_node(ROOT, 20);	
	in_order(ROOT); printf("\n");
	
	ROOT = delete_node(ROOT, 30);	
	in_order(ROOT); printf("\n");
	
	ROOT = delete_node(ROOT, 50);	
	in_order(ROOT); printf("\n");
	
	ROOT = delete_node(ROOT, 60);	
	in_order(ROOT); printf("\n");

	ROOT = delete_node(ROOT, 80);	
	in_order(ROOT); printf("\n");

	ROOT = delete_node(ROOT, 70);	
	in_order(ROOT); printf("\n");

	ROOT = delete_node(ROOT, 40);	
	in_order(ROOT); printf("\n");
	
	return 0;
}
