#include <iostream>
#include <cstdlib>
#include <ctime>
#include "mergesort.cpp"
#include "quicksort.cpp"
#include "introsort.cpp"

using namespace std;

int main(){
	
	MergeSort M;
	QuickSort Q;
	Introspective I;
	
	int size_, choice;
	
	cout << "Prosze wybrac rozmiar tablic. Masz do wyboru:" << endl;
	cout << "1. 10000" << endl;
	cout << "2. 50000" << endl;
	cout << "3. 100000" << endl;
	cout << "4. 500000" << endl;
	cout << "5. 1000000" << endl;
	cout << "Wybor: ";
	cin >> choice;
	cout << endl;
	
	const int choice_1 = choice;
	
	switch(choice_1){
		case 1: size_ = 10000;
		break;
		case 2: size_ = 50000;
		break;
		case 3: size_ = 100000;
		break;
		case 4: size_ = 500000;
		break;
		case 5: size_ = 1000000;
		break;
	}
	
	static const int size = size_;
	
	int ** tab = new int*[100];
	for(int i=0;i<100;++i)
		tab[i] = new int[size];
	
	int low = 0;
	int high = size - 1;
	cout << "Teraz prosze podac przypek sortowania:" << endl;
	cout << "1. Wszystkie elementy tablice losowe" << endl;
	cout << "2. 25% elementow poczatkowych posortowanych" << endl;
	cout << "3. 50% elementow poczatkowych posortowanych" << endl;
	cout << "4. 75% elementow poczatkowych posortowanych" << endl;
	cout << "5. 95% elementow poczatkowych posortowanych" << endl;
	cout << "6. 99% elementow poczatkowych posortowanych" << endl;
	cout << "7. 99.7% elementow poczatkowych posortowanych" << endl;
	cout << "8. Wszystkie elementy posortowane w odwrotnej kolejnosci" << endl;
	cout << "Wybor: ";
	
	cin >> choice;
	
	const int choice_2 = choice;
	float procent;
	
	switch(choice_2){
		case 1: procent = 0;
		break;
		case 2: procent = 0.25;
		break;
		case 3: procent = 0.5;
		break;
		case 4: procent = 0.75;
		break;
		case 5: procent = 0.95;
		break;
		case 6: procent = 0.99;
		break;
		case 7: procent = 0.997;
		break;
		case 8: procent = 1;
		break;
	}
	
	for(int j=0;j<100;++j){
		for(int i=0;i<size;++i){
			if(procent==1)
				tab[j][i] = size - i;				//posortowane od tylu
			else if(i<size*procent)
				tab[j][i] = i;
			else
				tab[j][i] = (rand() % size) + 1; 	//losowe wypelnienie
		}
	}
	
	int sort_nr;
	
	cout << "Prosze podac rodzaj sortowania:" << endl;
	cout << "1. Sortowanie przez scalanie (MergSort)" << endl;
	cout << "2. Sortowanie szybkie (QuickSort)." << endl;
	cout << "3. Sortowanie introspektywne (IntroSort)" << endl; 
	cout << "Wybor: ";

	cin >> sort_nr;
	cout << endl;
	
	switch(sort_nr){
		case 1:{
		double wyniki_1[100];
		double suma = 0;
		for(int j=0;j<100;++j){
			int * c = new int[100000000];
			clock_t begin = clock();
			M.PublicSort<int>(tab[j], low, high, c);
			clock_t end = clock();
			double AlgTime = double(end - begin)/CLOCKS_PER_SEC;
			wyniki_1[j] = AlgTime;
			cout << "Czas wykonywania algorytmu MergeSort: " << AlgTime << "s" << endl;
			delete [] c;
		}
		for(int j=0;j<100;++j){
			suma = wyniki_1[j] + suma;
		}
		cout << "Suma wynikow sortowaniem przez scalanie: " << suma << "s" << endl;
		break;
		}
		case 2:{
		double wyniki_2[100];
		double suma = 0;
		for(int j=0;j<100;++j){
			clock_t begin = clock();
			Q.Sort<int>(tab[j], low, high);
			clock_t end = clock();
			double AlgTime = double(end - begin)/CLOCKS_PER_SEC;
			wyniki_2[j] = AlgTime;
			cout << "Czas wykonywania algorytmu QuickSort: " << AlgTime << "s" << endl;	
		}
		for(int j=0;j<100;++j){
			suma = wyniki_2[j] + suma;
		}
		cout << "Suma wynikow sortowaniem szybkim(quicksort): " << suma << "s" << endl;
		break;
		}
		
		case 3:{
		double wyniki_3[100];
		double suma = 0;
		for(int j=0;j<100;++j){
			clock_t begin = clock();
			I.HybridIntroSort(tab[j], high+1);
			clock_t end = clock();
			double AlgTime = double(end - begin)/CLOCKS_PER_SEC;
			wyniki_3[j] = AlgTime;
			cout << "Czas wykonywania algorytmu introspektywnego: " << AlgTime << "s" << endl;	
		}
		for(int j=0;j<100;++j){
			suma = wyniki_3[j] + suma;
		}
		cout << "Suma wynikow sortowaniem introspektywnym: " << suma << "s" << endl;
		
		break;
		}
	}
	delete []tab;
	
	return 0;
}