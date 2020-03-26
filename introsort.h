
class Introspective{
	
	template<class T>
	void Replace(T tab[], T pierwszy, T drugi);
	
	template<class T>
	void MedianOfThree(T tab[], T &low, T &high);
	
	template<class T>
	T Partition(T tab[], T low, T high);
	
	template<class T>
	void Heapify(T tab[], T i, T high);
	
	template<class T>
	void HeapSort(T tab[], T high);
	
	template<class T>
	void InsertionSort(T tab[], T high);
	
	template<class T>
	void IntroSort(T tab[], T high, T M);
	
	public:
	template <class T>
	void HybridIntroSort(T tab[], T high);
};

