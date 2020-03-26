#include <iostream>
#include <cstdlib>
#include "mergesort.h"

using namespace std;

template<class T>
void MergeSort::PrivateSort(T tab[], T low, T mid, T high, T c[]){
	
	int i = low;
	int j = mid + 1;
	int k = low;
	
	while(i<=mid && j<=high){
		
		if(tab[i]<tab[j])
			c[k++] = tab[i++];
		else
			c[k++] = tab[j++];
	}
	
	while(i<=mid)
		c[k++] = tab[i++];
	
	while(j<=high)
		c[k++] = tab[j++];
	
	for(i=low;i<k;++i)
		tab[i] = c[i];
}

template<class T>
void MergeSort::PublicSort(T tab[], T low, T high, T c[]){
	
	if(low<high){
		
		int mid = (low + high)/2;
		
		PublicSort(tab, low, mid, c);
		PublicSort(tab, mid + 1, high, c);
		PrivateSort(tab, low, mid, high, c);
	}
}