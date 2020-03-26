#include <iostream>
#include <cstdlib>
#include <cmath>
#include "introsort.h"

using namespace std;

template<class T>
void Introspective::Replace(T tab[], T pierwszy, T drugi){
	
	T temp = tab[pierwszy];
	tab[pierwszy] = tab[drugi];
	tab[drugi] = temp;
}

template<class T>
void Introspective::MedianOfThree(T tab[], T &L, T &H){

	if(tab[++L-1]>tab[--H])
		Replace(tab, L-1, H);
	if(tab[L-1]>tab[H/2])
		Replace(tab, L-1, H/2);
	if(tab[H/2]>tab[H])
		Replace(tab, H/2, H-1);
	Replace(tab, H/2, H-1);
}

template<class T>
T Introspective::Partition(T tab[], T low, T high){
	
	int i, j;
	
	if(high>=3)
		MedianOfThree(tab, low, high);
	
	for(i=low, j=high-2; ;){
		for(;tab[i]<tab[high-1]; ++i);
		for(;j>=low && tab[j]>tab[high-1];--j);
		if(i<j)
			Replace(tab,i++,j--);
		else break;
	}
	Replace(tab, i, high-1);
	
	return i;
}

template<class T>
void Introspective::Heapify(T* heap, T i, T n){
	int Left = 2*i;
	int Right = 2*i+1;
	int Smallest = i;
	
	if(Left<=n && heap[Left]<heap[i])
		Smallest = Left;
	if(Right<=n && heap[Right]<heap[Smallest])
		Smallest = Right;
	
	if(Smallest!=i){
		int temp = heap[Smallest];
		heap[Smallest] = heap[i];
		heap[i] = temp;
		//Replace(heap, Smallest, i);
		Heapify(heap, Smallest, n);
	}	
}

template<class T>
void Introspective::HeapSort(T* heap, T n){
	for(int i=n/2;i>=1;i--)
		Heapify(heap, i, n);
}

template<class T>
void Introspective::InsertionSort(T tab[], T high){
	
	T temp;
	int i, j;
	
	for(i=1; i<high; i++){
		temp=tab[i];
		for(j=i;j>0 && temp<tab[j-i]; --j)
			tab[j] = tab[j-1];
		tab[j] = temp;
	}
}

template<class T>
void Introspective::IntroSort(T tab[], T high, T M){
	if(M<=0){					//sprawdzenie czy jest najgorszy warunek sortowania, jesli jest
		HeapSort(tab, high-1);	//sortowanie przebiega heapsortem, jesli nie - quicksortem
		return;
	}
	
	int mid = Partition(tab, 0, high);
	
	if(mid>9)
		IntroSort(tab, mid, M-1);
	if(high-mid-1>9)
		IntroSort(tab+mid+1, high-mid-1, M-1);
}

template<class T>
void Introspective::HybridIntroSort(T tab[], T high){
	IntroSort(tab, high, (int)floor(2*log(high)/M_LN2));
	InsertionSort(tab, high);
}