//
// HEAVY IRON INTERN PROGRAMMING CHALLENGE
// 
// Thanks for your interest in interning as a programmer at Heavy Iron.
//
// Welcome to the challenge. We expect it will take under two hours to complete.
// Please attempt all questions below.
//
// - Read all the instructions and questions carefully.
// - You may use a compiler, or just use a text editor. Your choice.
// - All work should be done in this one file.
//
// - DO NOT use the internet or other reference material, unless specified.
// - DO NOT use STL or similar templated data structures.
// - DO NOT modify the function definitions.
//
// - DO NOT CHEAT. We're not trying to see if you can cheat.
// 
//
// When finished:
//
// 1) Fill in these details in this cpp file:
//
//		Name										: Your name here
//		Address										: etc
//		Email										:
//		Phone										:
//		Current College								:
//		Current Course								:
//		Expected graduation date					:
//		Previous bachelors (if appropriate)			:
//		Date you could start						:
//		Date you would end (if appropriate)			:
//		Are you available full time all summer		:
//		Are you interested in interning term time*	:
//			* Some of our local interns work full time during the summer, and part time 2..5 
//			  days during term time. This isn't required, but it's interesting to know.
//
// 2) Save your changes, and email just this file to HI-interns@heavy-iron.com
//	  If you have an up to date resume, include that too.
//
// As we receive applications, we’ll pick several for in-house interview, and will then 
// select who will be offered positions.
//
// Good luck, and have fun! :)
//
// Heavy Iron Studios, Inc.
// (c) Copyright 2013


#include "System.h"
using namespace std;


////////////////////////////////////////////////
// QUESTION 0
//
// Change the string for your name and the date you todays date
char* YourNameAndTheDate()
{
	return "Your Name Here   4/1/2000";
}


////////////////////////////////////////////////
// QUESTION 1
//
// Write a function which sorts a list of numbers in ascending order, with odd numbers first.
// - E.g. if the input was 123456, the output would be 135246.
// - You are given a pointer to the beginning of an array, and the length of the array.
// - Your function should handle its input parameters robustly (i.e. not crash or misbehave with 'bad' parameters).
// - Correctness, performance and readability are important.
void SortOddEven( int* numbers, int count )
{
	// TODO
}


////////////////////////////////////////////////
// QUESTION 2
//
// 'FizzBuzz' is a game in which people take turns saying increasing numbers, but sometimes
// they have to say a word instead of a number.
// Write a function which:
// - Takes an integer. E.g. 2
// - Normally writes the integer as a string to the buffer pointed to by 'output'. E.g. "2"
// - If a multiple of 3 is passed, writes "Fizz" to the buffer pointed to by 'output', instead of printing the number.
// - If a multiple of 5 is passed, writes "Buzz" to the buffer pointed to by 'output', instead of printing the number.
// - If a multiple of both 3 and 5 is passed, writes "FizzBuzz" to the buffer pointed to by 'output', instead of printing the number.
// You may use strcpy and sprintf if you wish. You may look at the following two links for their definition if needed:
//    http://msdn.microsoft.com/en-us/library/kk6xf663(VS.90).aspx
//    http://msdn.microsoft.com/en-us/library/ybk95axf(VS.90).aspx
void FizzBuzz( int value, char* output )
{
	//*output = NULL;
	char f[5];
	char b[5];

	
	if ((value % 3) == 0)
	{
		strcpy(f, "Fizz");
	}
	else
	{
		strcpy(f, "");
	}

	if ((value % 5) == 0)
	{
		strcpy(b, "Buzz");
	}
	else
	{
		strcpy(b, "");
	}

	sprintf(output, "%s%s", f, b);
}


////////////////////////////////////////////////
// QUESTION 3
//
// Write a function which tests if two circles overlap.
// The circles are described by a position and radius.
// Return true if the circles exactly touch or are intersecting.
// Return false otherwise.
// Performance and accuracy are important.
bool CirclesIntersect( float x1, float y1, float r1, float x2, float y2, float r2 )
{
	//we can determine wether the two circles intersect or not by comparing the radiuses and the distance between their centers
	//so let get distance first
	float dist = 0;
	dist = sqrt(	powf(x1 - x2, 2) + powf(y1 - y2, 2)	);

	//case 1: they are way too far apart
	//in this case dist will be larger than even the two radiuses combined
	//which is the furthest the 2 circles can intersect (tangential? only 1 point of intersection)

	//case2: one is inside another
	//in which case the two centers must be far apart enough for the circles to touch each other
	//so we return false if the distance is too small for that to happen, or distance < |r1 - r2|
	if (dist > (r1 + r2) || dist < fabsf(r1 - r2))
	{
		return false;	// Todo
	}
	else
		return true;
}


////////////////////////////////////////////////
// QUESTION 4
//
// In our game, we have a monster which is looking for apples. Implement a function which returns if a
// given apple position is in front of a monster with a given position and facing direction (unit vector).
// You may look at the VecMath.cpp/h files (and use the functions within), but may USE NO OTHER REFERENCE.
bool IsAppleInFrontOfMonster( vector3& monsterPos, vector3& monsterFacingDirection, vector3& applePos )
{
	//So we have
	//A coordinate for the monster
	//A coordinate for the apple
	//A directional vector, let call it D

	//How about
	//We make a vector from the monster to the apple, call it V
	//if the monster is facing the apple, it would mean vector V has to be parallel to the facing vector D, and they are both facing the same general direction
	//This means there is a k so that V = kD, and that k has to be positive (if its negative the 2 vectors are parallel, but have opposite direction

	vector3 D = monsterFacingDirection;
	vector3 V(applePos.x - monsterPos.x, applePos.y - monsterPos.y, applePos.z - monsterPos.z);
	//vector3 V(applePos - monsterPos);
	float k1,k2,k3;

	//let see if the monster IS the apple!
	if (monsterPos == applePos)
	{
		return true;	// Todo
	}
	//Is the monster blind i.e. facing vector is zero
	else if (monsterFacingDirection.x == 0 && monsterFacingDirection.y == 0 && monsterFacingDirection.z == 0)
	{
		return false;
	}
	else
	{
		k1 = V.x / D.x;
		k2 = V.y / D.y;
		k3 = V.z / D.z;

		if ( k1 ==k2 && k1 == k3 && k1 > 0)
		{
			return true;
		}
		return false;
	}
}


////////////////////////////////////////////////
// QUESTION 5
//
// Write a function which shuffles the order of the bytes in an unsigned int, to reverse order.
// E.g. If the input was 0x12345678, the output should be 0x78563412
// Correctness is important, as well as performing the operation in as few steps as possible.
unsigned int SwapBytes( unsigned int in )
{
	return 0;	// Todo
}


////////////////////////////////////////////////
// QUESTION 6
//
// Strip spaces
// Write a function which allocates a new string using HIMalloc, and copies
// the input string to the new string, while stripping out the spaces.
// To allocate the memory for the new string, use 'HIMalloc' (which works like malloc).
// E.g. the input "My word, a talking goat!" should return a new string "Myword,atalkinggoat!"
// You are not allowed to call string functions, such as strlen. Just use pointers.
char* StripSpaces(char* input)
{
/*	int i = 0;
	while (&input[i] != NULL)
	{

	}
*/
	return NULL;	// Todo
}


////////////////////////////////////////////////
// QUESTION 7
//
// Many displays display numbers using a set of 7 bars (e.g. calculator, microwave, digital watch)
// The following ASCII art shows the numbers 0 to 9
//
//	 -			 -		-				 -				 -		 -		 -
//	| |		|	  |		 |		| |		|		|		  |		| |		| |
//	 			 -		-		 -		 -		 -				 -		 -
//	| |		|	|		 |		  |		  |		| |		  |		| |		  |
//	 -			 -		-				 -		 -				 -
//
// Write a function which returns how many LCD 'bars' are needed to display an unsigned int.
// Given an unsigned int as input, return how many 'bars' will make up that number when displayed
// on a calculator which uses this type of display. 
// E.g. 1 would return 2 bars, 12 would return 7 (2 bars for the 1, plus 5 for the 2), 90 would return 11 etc.
int BarsInDisplayedNumber( unsigned int num )
{
	//we can try to parse the int into a string then evaluate each digit
	//or we can do it in numerical form
	//let say we have 123
	//if we divide the number by 10, we get 12, and remainder 3
	//so if we continuosly divide the number by 10 and take the remainder, we can "sort of" parsing the individual digits at the end
	//we can then compare the digit taken from remainder against integers in a switch case, and return the bars needed
	//C++ division for int throw away the decimals, so we don't have to worry about it for now
	int a = num;
	int bars_total = 0;
	int remainder;
	
	//this trick wouldn't work if the number is already 0 so let cover it first
	if (num == 0)
	{
		bars_total =6;
	}
	else
	{
		while (a != 0)
		{
			remainder = a % 10;
			a = a / 10;

			switch (remainder)
			{
			case 0:
				bars_total = bars_total + 6;
				break;
			case 1:
				bars_total = bars_total + 2;
				break;
			case 2:
				bars_total = bars_total + 5;
				break;
			case 3:
				bars_total = bars_total + 5;
				break;
			case 4:
				bars_total = bars_total + 4;
				break;
			case 5:
				bars_total = bars_total + 5;
				break;
			case 6:
				bars_total = bars_total + 6;
				break;
			case 7:
				bars_total = bars_total + 3;
				break;
			case 8:
				bars_total = bars_total + 7;
				break;
			case 9:
				bars_total = bars_total + 5;
				break;
			default:
				break;
			}
		}
	}
	return bars_total;	// TODO
}




// This is the 'test' function which calls your answers above.
// If you are using a compiler, you are welcome to use and modify this function 
// to help while developing your answers. This function should not do anything 
// important though. Your answers should be contained in the functions above.
void RunTest()
{
	// Question 0 - NAME AND DATE
	printf( "0) Name and date: %s\n\n", YourNameAndTheDate() );


	// Question 1 - SORT ODD EVEN
	int list1[] = {1, 2, 3, 4, 5, 6};
	SortOddEven( list1, sizeof(list1)/sizeof(int) );
	printf( "1) SORT ODD EVEN\n\n" );


	// Question 2 - FIZZ BUZZ --Done
	printf( "2) FIZZ BUZZ\n" );
	char temp[16];
	FizzBuzz(15, temp);
	if( *temp )
		printf( "%s\n", temp );
	printf( "\n" );


	// Question 3 - CIRCLE INTERSECTION --Done
	bool intersects = CirclesIntersect(0,	0,	5,	10,	0,	3);
	printf( "3) CIRCLE INTERSECTION : %s\n\n", intersects ? "Yes":"No" );


	// Question 4 - APPLE MONSTER --Done
	vector3 monsterPos(100, 100, 0);
	vector3 monsterDir(1, 1, 1);
	vector3 applePos(99, 99, -1);
	bool infront = IsAppleInFrontOfMonster( monsterPos, monsterDir, applePos );
	printf( "4) APPLE IS %s MONSTER\n\n", infront?"IN FRONT OF":"NOT IN FRONT OF" );


	// Question 5 - SWAP BYTES
	unsigned int input = 0x12345678;
	unsigned int shuffled = SwapBytes( input );
	printf( "5) SWAP BYTES\n0x%x => 0x%x\n\n", input, shuffled );


	// Question 6 - STRIP SPACES
	char* withSpaces = "Oh My Word!";
	char* stripped = StripSpaces( withSpaces );
	printf( "6) STRIP SPACES\n%s => %s\n\n", withSpaces, stripped );


	// Question 7 - BARS IN DISPLAY --Done
	int bars = BarsInDisplayedNumber( 90 );
	printf( "7) BARS IN DISPLAY = %d\n", bars );
}

int main()
{
	RunTest();

	int in =1;
	printf("Enter 0 to exit.");
	scanf("%d", &in);
	if (in == 0)
	{
		return 0;
	}
}

