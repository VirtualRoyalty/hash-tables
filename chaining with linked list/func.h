#pragma once
#include <iostream>
using namespace std;

int hashfun(int x, int N)
{
	x = x % N;
	return x;
}

struct HASH_ELEM {
	int hash_key;
	int val;
	HASH_ELEM *next = NULL;
};
typedef HASH_ELEM *PNode;


void insert_hash(int key, int N, PNode& elem, int(*hashfun)(int, int))
{
	if (elem == NULL)
	{
		elem = new HASH_ELEM;
		elem->val = key;
		elem->hash_key = hashfun(key, N);
		elem->next = NULL;
		return;
	}
	insert_hash(key, N, elem->next, hashfun);
	return;
}


void printELEM(PNode elem)
{
	cout << elem->val << "->";
	if (elem->next != NULL)
	{
		printELEM(elem->next);
	}
	return;
}

void printTABLE(PNode* table, int N)
{
	for (auto i = 0; i < N; i++)
	{
		cout << table[i]->hash_key << ": ";
		printELEM(table[i]);
		cout << endl;
	}
	return;
}