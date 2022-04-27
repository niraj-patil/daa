
void merge(int *start, int const mid, int const size){
    //storing size of the left array and right array
    //if size=5. mid=size/2=5/2=2. therefor, leftSize=2
    //and rightSize=5-2=3
    int leftSize=mid;
    int rightSize=size-mid;
    //creating temporary arrys of same size
    int left[leftSize],right[rightSize];
    //filling left and right array with left and right part of the main array
    for(int i=0;i<leftSize;i++){
        *(left+i)=*(start+i);
    }
    for(int j=0;j<rightSize;j++){
        *(right+j)=*(start+mid+j);
    }
    //creating indexes to keep track of refilling of the main array
    //leftIndex and rightIndex keeps tract of nextElement of left and right to be filled
    //index keeps track of position to be filled in main array
    auto leftIndex=0,rightIndex=0,index=0;
    //till either of the arrays become empty run the loop
    //compare elements of the array and replace the element with lower value in the main array
    //increment index and the respective index i.e. array from which the lower element belongs
    //we do not check the further elements as the sub-arrays are always sorted 
    while(leftIndex < leftSize && rightIndex < rightSize){
        if (*(left+leftIndex) <= *(right+rightIndex)) {
        *(start+index) = *(left+leftIndex);
        leftIndex++;
    }
    else {
        *(start+index) = *(right+rightIndex);
        rightIndex++;
    }
    index++;
    //we stop the above loop when one of the sub-array becomes empty
    //we need to fill the other non-empty sub-array
    //run loop till there are elements in array and append them to main array
    //for the empty array the loop will not run from onset
    }
    while (leftIndex < leftSize) {
        *(start+index) = *(left+leftIndex);
        leftIndex++;
        index++;
    }

    while (rightIndex < rightSize) {
        *(start+index) = *(right+rightIndex);
        rightIndex++;
        index++;
    }
}

//recursive merge sort
void mergeSort(int *start, int const size){
    //exit condition: when array size becomes one or less i.e. further division not possible
    if (size<=1)
        return;
    //calculating mid
    auto mid = size / 2;
    //applying mergeSort on first half the the second half
    //note:here the division will take place in DFS manner
    mergeSort(start, mid);
    mergeSort(start+mid, size-mid);
    //after the division is completed we merge the array from the size=1 arrays to mainArray
    merge(start,mid,size);
}