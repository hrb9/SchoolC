#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int pack4Chars2Int(char c1, char c2, char c3, char c4);
int checkEvenParity(short input);

int main()
{
	char c1 = 'a';
	char c2 = 'b';
	char c3 = 'c';
	char c4 = 'd';
	printf("%d", pack4Chars2Int(c1, c2, c3,c4));

	printf("\n checkEvenParity 14580 ? (if 1 = yes)  %d", checkEvenParity(14580));
	return 0;
}
int pack4Chars2Int(char c1, char c2, char c3, char c4) {
	//1 char =8 bits, 8*4=32 => our number = 32 bits, interger -> 32.  
		unsigned int result = 0;
		result = result | ((unsigned int)c1);
		result = result << 24; //3 number left
		result = result | ((unsigned int)c2);
		result = result << 16; //2 number left
		result = result | ((unsigned int)c3);
		result = result << 8; //1 number left 
		result = result | ((unsigned int)c4);
		return result;
}
int checkEvenParity(short input) {
	unsigned short uInput = (unsigned short)input;
	int count = 0;
	while (uInput!=0) {
		if ((uInput & 1)==1) count ++;
		uInput >>= 1;
	}
	if (count % 2 == 0)
		return 1;
	else return 0; 

}
