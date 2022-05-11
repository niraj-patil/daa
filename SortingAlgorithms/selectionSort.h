void selectionSort(int *start,int const size){
	//The minPointer points to the minimum element in the unsorted section of Array   
	int *minPointer;
	//If size of Array is less than 1. The array is already sorted or invalid
	if(size<=1)
		return;
	//loop through the unsorted array such that at every ith iteration we find the ith minimum element
	//i.e. in first iteration we find the minimum element and swap it with first location
	//similarly, every ith iteration we find the ith minimum value and swap it the ith location
	//the ith lowest element is to be searched in the remaining array i.e from i+1 to last element
	//if i is the lowest element, do nothing
	for(int i=0;i<size;i++){
	    //set minPointer to ith position
		minPointer=start+i;
		//loop through rest of the array
		for(int j=i;j<size;j++){
		    //if new minimum is found update minPointer to new minimum
			if(*(start+j)<*minPointer)
				minPointer=(start+j);
		}
		//if minPointer and i do not match i.e. new min is found, swap
		if(*(start+i)!=*minPointer){
			*(start+i)=*(start+i)+*minPointer;
			*minPointer=*(start+i)-*minPointer;
			*(start+i)=*(start+i)-*minPointer;
		}
	}
}
