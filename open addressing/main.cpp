#include "funcs.h"


int linearhash(int x, int N, int try_count)
{
	x = (x % N + try_count)%N;
	return x;
}

int quadrohash(int x, int N, int try_count)//N должно быть простое
{
	x = (x % N + (try_count)*(try_count)) % N;
	return x;
}


int doublehash(int x, int N, int try_count)//N должно быть простое , 1<=M<N 
{
	int M = 97;
	x = (x % N + (try_count)*(1 + x % M)) % N;
	return x;
}


void insert_hash(int key,int N,int *table,int (*hashfun)(int,int,int))
{
	int probe = 0;
	int hash_key = hashfun(key, N, probe);
	while (table[hash_key] != NULL)
	{
		probe++;
		if (probe >= N)
		{
			cout << "overflow" << endl;
			return;
		}
		hash_key= hashfun(key, N, probe);
	}
	table[hash_key] = key;
	return;
}


int main()
{
	const int N = 101;
	const int M = 71;
	int mas[M];
	for (auto i = 0; i < M; i++)
		mas[i] =0 +rand()%223;
	int *p = new int[N];
	for (auto i = 0; i < N; i++) 
	{
		p[i] = NULL;
	}
	for (auto i = 0; i < M; i++)
	{
		insert_hash(mas[i], N, p, doublehash);
	}
	for (auto i = 0; i < M; i++)
		cout << mas[i] << " ";
	cout << endl;
	for (auto i = 0; i < N; i++)
	{
		if (p[i] == NULL)
		{
			cout << i << ": NULL " <<  endl;
		}
		else
		{
			cout << i << ": " << p[i] << " " << endl;
		}
		
	}
		
	getchar();
	return 0;
}