#include "func.h"
#include <iostream>
using namespace std;

int main()
{
	const int N = 17;
	const int M = 30;
	int mas[M];
	for (auto i = 0; i < M; i++)
	{
		mas[i] = i+1;
	}
	PNode *table = new PNode[sizeof(PNode)*N];
	for (auto i = 0; i < N; i++)
	{
		table[i] = NULL;
	}
	int new_key;
	for (auto i = 0; i < M; i++)
	{
		new_key = hashfun(mas[i], N);
		insert_hash(mas[i],N, table[new_key], hashfun);

	}
	printTABLE(table, N);
	getchar();
	return 0;
}