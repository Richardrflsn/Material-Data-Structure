#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DATA 10

struct Node{
	int key;
	char data[100];
	struct Node *next;
};

struct HashBucket{
	int number_of_node;
	struct Node *head;
	struct Node *tail;
};

struct HashBucket HASH_TABLE[MAX_DATA];

int sum_digits(int input, int base){
	return input == 0 ? 0 : input%base + sum_digits(input/base, base);
}

int folding(char *input){
	int key;
	int charSum = 0;
	int digitSum = 0;
	
	int length = strlen(input);
	
	for(int i=0 ; i<length ; i++){
		charSum += input[i];
	}
	
	digitSum = sum_digits(charSum, MAX_DATA);
	
//	printf("charSum  = %d\n", charSum);
//	printf("digitSum = %d\n", digitSum);
//	printf("key		 = %d\n", digitSum % MAX_DATA);
	
	return digitSum % MAX_DATA;
}

int division(char *input){
	int key;
	int charSum = 0;
	
	int length = strlen(input);
	
	for(int i=0 ; i<length ; i++){
		charSum += input[i];
	}
	
	key = charSum % MAX_DATA;
	return key;
}

struct Node* create_node(char* data){
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(node->data, data);
//	node->key = division(data);
	node->key = folding(data);
//	printf("%d\n", node->key);
	node->next = NULL;
	return node;
}

void push_data(struct Node *node){
	if( HASH_TABLE[node->key].head == NULL ){
		HASH_TABLE[node->key].head = HASH_TABLE[node->key].tail = node;
	}
	else{
		HASH_TABLE[node->key].tail->next = node;
		HASH_TABLE[node->key].tail = node;
	}

	HASH_TABLE[node->key].number_of_node++;
}

void view_data(){
	for(int i=0 ; i<MAX_DATA ; i++){
		printf("  Key[%02d]: ", i);
		struct Node *curr = HASH_TABLE[i].head;
		while(curr){
			printf("%s -> ", curr->data);
			curr = curr->next;
		}
		printf("(null)\n");
	}
}

int main(){
	
	for(int i=0 ; i<MAX_DATA ; i++){
		HASH_TABLE[i].head = NULL;
		HASH_TABLE[i].tail = NULL;
		HASH_TABLE[i].number_of_node = 0;
	}
	
	push_data(create_node("Sidony Tanis"));
	push_data(create_node("Syntyche Shahjahan"));
	push_data(create_node("Dobromil Fedelma"));
	push_data(create_node("Muirne Avinash"));
	push_data(create_node("Senne Marian"));
	push_data(create_node("Taisiya Knutr"));
	push_data(create_node("Demetria Magomed"));
	push_data(create_node("Regan Till"));
	
	
	view_data();	
	return 0;

}
