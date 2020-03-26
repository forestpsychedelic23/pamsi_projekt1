#include <iostream>
#include <cstdlib>
#include "quicksort.h"

using namespace std;

template<class T>
void QuickSort::Replace(T tab[], T pierwszy, T drugi){
	T temp = tab[pierwszy];
	tab[pierwszy]=tab[drugi];
	tab[drugi]=temp;
}

template<class T>
T QuickSort::Divide(T tab[], T low, T high){
	
	int mid_index = (high - low)/2 + low;	//znajduje indeks elementu ktory dzieli tablice
	int mid = tab[mid_index];
	Replace(tab, mid_index, high);			//przeniesienie elementu na koniec
	int temp_pos = low;						//aktualna pozycja
	
	for(int i=low;i<high;++i){
		if(tab[i]<mid){
			Replace(tab, i, temp_pos);
			++temp_pos;
		}
	}
	
	Replace(tab, temp_pos, high);			//przeniesienie
	
	return(temp_pos);
}

template<class T>
void QuickSort::Sort(T tab[], T low, T high){
	
	while(low<high){
		int mid = Divide(tab, low, high);	//dzielenie tablicy
		
		if((mid-low)<=(high-mid)){
			Sort(tab, low, mid);			//sort lewej czesci
			low = mid + 1;
		}
		else{
			Sort(tab, mid + 1, high);		//sort prawej czesci
			high = mid - 1;
		}
	}
	return;
	
}