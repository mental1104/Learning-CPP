#include <iostream>

int main()
{
	// currVal is the number we're counting; we'll read new values into val
	int currVal = 0, val = 0;

	// read first number and ensure that we have data to process
	if (std::cin >> currVal) {        
		int cnt = 1;  // store the count for the current value we're processing
		while (std::cin >> val) { // read the remaining numbers 
			if (val == currVal)   // if the values are the same
				++cnt;            // add 1 to cnt 
			else { // otherwise, print the count for the previous value
				std::cout << currVal << " occurs " 
				          << cnt << " times" << std::endl;
				currVal = val;    // remember the new value
				cnt = 1;          // reset the counter
			}
		}  // while loop ends here
		// remember to print the count for the last value in the file
		std::cout << currVal << " occurs " 
		          << cnt << " times" << std::endl;
	} // outermost if statement ends here
	return 0;
}

/************************************
 * All equal:
 * 1
 * 1
 * 1
 * 1
 * 1
 * 1
 * 1
 * 1
 * 1
 * 1
 * 1
 * 1
 * 1
 * 1
 * 1 occurs 14 times
 *************************************
 * no repetion:
 * 1
 * 2
 * 1 occurs 1 times
 * 3
 * 2 occurs 1 times
 * 4
 * 3 occurs 1 times
 * 5
 * 4 occurs 1 times
 * 6
 * 5 occurs 1 times
 * 7
 * 6 occurs 1 times
 * 8
 * 7 occurs 1 times
 * 9
 * 8 occurs 1 times
 * 10
 * 9 occurs 1 times
 *************************************/