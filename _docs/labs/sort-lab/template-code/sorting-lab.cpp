#include <iostream>
#include "sorting-lab.h"

sorts::sorts() {
    //nothing to do here
}

sorts::~sorts() {
    //nothing to do here
}

//does sorting, using selection sort algo
void sorts::selectionSort(int * unsortedArr, int arrSize) {

	// Set the current sorted_pos to 0
	for (int sorted_pos = 0; sorted_pos <= arrSize - 1; sorted_pos++)
	{
		int smallest_elem_pos = sorted_pos; //keeping track of smallest position's index rather than value so it's easier to swap

		// Find the smallest element in the rest of list
		// YT link on how selection sort works: https://www.youtube.com/watch?v=g-PGLbMth_g

		// Swap the smallest element in the list with the element at sorted_pos
		std::swap(unsortedArr[smallest_elem_pos], unsortedArr[sorted_pos]);

		// Increment sorted_pos by 1 (done by loop)
		// Repeat 2-4 until list is sorted (until sorted_pos is n-1) (done by loop)
	}
}

//does sorting, using insertion sort algo
void sorts::insertionSort(int * unsortedArr, int arrSize) {
	// Start at the front of the list
	for (int i = 1; i < arrSize; i++) //starting at one so there's something to the left
	{
		int curr = unsortedArr[i];
		int j; //declaring outside so we can use it outside of for loop

		// Compare the current element to the element immediately to its left
		// If the current element is smaller than the element immediately to its left...
		// ...compare the current element to all the other elements to the left
		// Do this until the current element is not smaller than the element its being compared to
		//while the previous item is greater than the next item, continue swapping
        //hint: remember there are many shifts in insertion sort, what does it take to make a shift?
        //YT link on how insertion sort works: https://www.youtube.com/watch?v=JU767SDMDvA
	}
}

void sorts::print(int data[], int n, std::ostream& os) {
    for(int i=0;i<n;i++)
        os << data[i] << " ";
}

void sorts::merge(int data[], int temp[], int low, int mid, int high) {
	for(int i=low;i<=high;i++) {
        //how do you copy an array's items to the new array temp?
	}
    //variables to track the low, middle, and high indices, we will need 3 of these
	int i = low;
	//Think about why j here has mid + 1
	int j = mid + 1;
	int k = low;

	//while we have items in left and right subarray...
	while( (i<=mid) && (j<=high) ) {
        //if left is smaller, we put it to its right/sorted position in the array.
        //write something that compares the 2 split arrays in merge, and then iterates through the split list that just added a value to the new array

	}
	//sometimes we have items left in the left subarray, so we copy it to the final nums array. They're in sorted order at this point, so we just copy them
	//we copy them by adding the rest of the items in the subarray to the array
    while (i <= mid) {

    }
	//same reasoning for the last while loop applies to this loop, but for the right subarray
    while (j <= high) {

    }
}

void sorts::mergesort(int data[], int low, int high) {
    //base case for recursive method calls
    //what should the recursive call be? What if we don't have enough items to actually sort through?
	if(  ) {
		return;
	}
    //look for the middle index to partition the array into 2 equal subarrays. We set a variable to determine the middle of the list

    //divide portion

    //call the merge sort method recursively on the left subarray (use that middle variable you just wrote above as a parameter)

	//call the merge sort method recursively on the right subarray (use that middle variable you just wrote above as a parameter)

	//conquer (where we call the helper function
}

void sorts::mergesort(int data[], int n) {
    mergesort(data, 0, n-1);
}

void sorts::swap(int& x, int& y){
  int temp = x;
  x = y;
  y = temp;
}

int sorts::partition(int data[], int low, int high) {
  //we could generate a random item for the pivot, but we're using a middle item instead
  int pivdex = (low+high)/2;
  //make the pivot be the last item in the array
  swap(data[pivdex], data[high]);

  //write code that decides what are the items that will be on the left side of the pivot or the right side of the pivot
  int i = low;
  //we need to write something that goes through the whole list, checks if the data being checked is less than the data within the pivot, ans swap accordingly

  swap(data[i], data[high]);
  //return index of pivot
  return i;
}

void sorts::quicksort(int data[], int low, int high) {
  //base case, takes care of the same case we hinted on in mergesort
  if (  ){
    return;
  }
  //find a pivot item, run the partition on the array according to what the pivot is
  //like merge sort, we make a variable to keep track of this

   //call this sort method recursively on left array

   //call this sort method recursively on right array

  //we use pivdex - 1 and pivdex + 1 because we aren't measuring the pivot at all
}

void sorts::quicksort(int data[], int n){
  quicksort(data, 0, n - 1);
}
