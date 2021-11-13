#include<iostream>

using namespace std;

void shuffle(int deck[], int _size);

void print(const int deck[], int _size);

bool compareDeck(const int deck_1[], const int deck_2[], int _size);

int main()
{
	int n;
	cin >> n;
	int N = 2*n;
  
  //mang co dinh
	int _DECK_[N];
	for(int i=0; i<N; i++)
	{
		_DECK_[i] = i+1;
	}
  
  //mang thay doi
	int deck[N];
	for (int i=0; i<N; i++)
	{
		deck[i] = i+1;
	}
	
	print(deck,N); //mang ban dau
	
	//neu trung bo luc dau thi dung
	int turn = 0;
	do
	{
		shuffle(deck, N);
		print(deck, N);
		turn++;
	}
	while (!compareDeck(deck, _DECK_, N));
  
	cout << turn <<endl;
	
	return 0;
}

void shuffle(int deck[], int _size)
{
	int temp[_size];
	int j = 1;
	for(int i=0 ; i<_size/2 ; i++)
	{
		temp[2*i+1] = deck[i];
		j=j+2;
	}
	
	j=0;
	for(int i=_size/2 ; i<_size ; i++)
	{
		temp[j] = deck[i];
		j=j+2;
	}
	
	for(int i=0; i<_size; i++)
	{
		deck[i] = temp [i];
	}
}

void print(const int deck[], int _size)
{
	for(int i=0; i<_size; i++)
	{
		cout << deck[i] << " ";
	}
	cout<<endl;
}

bool compareDeck(const int deck_1[], const int deck_2[], int _size)
{
	int i=0;
	while(i<_size && deck_1[i] == deck_2[i])
	{
		i++;
	}
	if(i == _size) return true;
}
