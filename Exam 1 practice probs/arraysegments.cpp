#include <iostream>

using std::cout, std::endl, std::cin;
using namespace std;

/*  
    arraysegments:

    Given n > 0, and a sequence of n integer numbers, print how many
    segments omcposed by consecutive copies of the same number the 
    sequence has. Ex: 5 2 2 3 4 4 4 4 1 1 1 has 5 segments
*/

int main() {
    unsigned int i;
    const unsigned n = 10; //array size must be const, else error

    int sequence[n];
    int count = 1 ;

    for (i = 0; i < n; ++i) { //initialize array values to 0, dont have to do
		sequence[i] = 0;
	}

    cout << "Enter 10 integers for the sequence: " << endl;
    for (i = 0; i < n; ++i) {
        cin >> sequence[i];                //input sequence vals
    }    
    for (i = 0; i < 9; ++i) {               //one less than arry size to not access out of bounds
        if (sequence[i] != sequence[i+1]) { //check if next val is new segment
            count++;
        }
    }

    cout << "Your sequence has " << count << " segments." << endl;

    return 0;

}