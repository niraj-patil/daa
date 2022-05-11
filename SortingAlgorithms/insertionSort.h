void insertionSort(int *start,int const size){
	//If size of Array is less than 1. The array is already sorted or invalid
	if(size<=1)
		return;
	//loop through the array, at every iteration the first i-1 elements are sorted
	//to insert the ith element at the right position
	//loop through the sorted array in backwards direction and shift the elements right 
	//till we encounter a element less than the ith element
	for(int i=1;i<size;i++){
	    //the counter j is declared here as we need to access it outside the inner for-loop scope
	    //store the ith element in temp 
		int j,temp=*(start+i);
		//loop through rest of the array
		for(j=i-1;j>=0;j--){
		    //if new minimum is found update minPointer to new minimum
			if(*(start+j)>temp){
			    *(start+j+1)=*(start+j);
			}else{
			    break;
			}
		}
		*(start+j+1)=temp;
	}
}
