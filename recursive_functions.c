/* SYSC 2006 Winter 2019 Lab 11. */

#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "recursive_functions.h"

/* Return x raised to the power n for n >= 0. */
double power(double x, int n)
{
	//base case, if n is 0, return 1
 	if(n==0){
		return 1;
	}   
	//otherwise, you multiply by x until n = 0
	return x*power(x, n-1);
}

/* Return the count of the number of times target occurs in the first 
 * n elements of array a.
 */
int count(int a[], int n, int target)
{
	if(n-1 == -1){
		return 0;
	}
	if(a[n-1] == target){
		return 1 + count(a , n - 1 , target);
	}
	return count(a , n - 1 , target);


	/*
	//if the element is equivalent to the target, change found to 1
	//otherwise, just leave it as 0
 	int found = 0;
	if(a[n-1] == target){
		found = 1;
	}
	//if n is 0, meaning it is the first element of the array
	//return found, the first n elements have all been checked
	if(n-1 == 0){
		return found;
	}
	//otherwise, add found, and check the next element
	return found + count(a, n-1, target);

	*/

}

/* Return the count of the number of times target occurs in the 
 * linked list pointed to by head. 
 */
int occurrences(node_t *head, int target)
{
 	//base case, the head has reached the end of the list	
	if(head == NULL){
		return 0;
	}	
	//checking for if the data in the node is equivalent to target
	//if so, add 1
	if(head->data == target){
		return 1 + occurrences(head->next, target);
	}   
	return occurrences(head->next, target);
}

/* Return the last element in the linked list pointed to by head.
 * Terminate (via assert) if the list is empty.
 */
int last(node_t *head)
{
	assert(head!=NULL);
 	//base case, head->next is pointing to null
	//would return the current value of head->data
	if(head -> next == NULL){
		return head->data;
	}
	return last(head->next);
}

/* Extra-practice exercises. */

/* Return the number of digits in integer n, n >= 0. */
int num_digits(int n)
{
	//base case: has one digit
	if(n/10 == 0){
		return 1;
	}
	//recursive case: has more than one digit
	return 1 + num_digits(n/10);
}

/* Return x raised to the power n for n >= 0. */
double power2(double x, int n)
{
	//base case: n = 0 
	if(n==0){
		return 1;
	}
	//recursive case 1: n is even, and is not 0
	if(n%2 == 0){
		return power2(x, n/2)*power2(x, n/2);
		//or could even do
		//return power2(power2(x, n/2), 2);
	}
	//recursive case 2: n is odd (not even, not zero)
	return x * power2(x, n/2) * power2(x, n/2);
}
