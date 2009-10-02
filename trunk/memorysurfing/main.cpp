#include <stdio.h>
#include <windows.h>

void printchar(char);

int main(int argc, char ** argv)
{
	//using argc and argv
	/*
	printf("Goooooodmoooooorning GEEEE ESSSS PEEEE\n");
	// dump our arguments
	for(int i = 0; i < argc; ++i)
	{
		printf("%s\n", argv[i]);
	}
	*/

	/*
	int a = 2;
	int b = 10;
	int c = 99;

	printf("%d is at: 0x%08X\n%d is at: 0x%08X\n%d is at: 0x%08X\n", a, &a, b, &b, c, &c);


	int d = 0xF;
	int e = 1;
	int f = 5;

	printf("d: %d is at 0x%08X\n", d, &d);
	printf("e: %d is at 0x%08X\n", e, &e);
	printf("f: %d is at 0x%08X\n", f, &f);

	int * ptr = &c;
	for(int i = 0; i < 30; ++i)
	{
		printf("ptr: 0x%08X is at 0x%08X\n", ptr, &ptr);
		printf("the value AT ptr is: %d\n", *ptr);
		ptr += 3;
	}
*/
	char aLetter = 'a';
	char * charptr = &aLetter;

	for(int i = 0; i < 8192; i++)
	{
		printchar(*charptr);
		charptr++;
	}

	return 0;
}

void printchar(char cursor)
{
	// the color to display the letters at
	int color = FOREGROUND_INTENSITY;
	// \t, \r, \n, \b, \a, \0, -1
	switch(cursor)
	{
	case 0:	// \0
		color = BACKGROUND_BLUE;
		cursor = '0';
		break;
	case 7:	// \a
		color = FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN;
		cursor = 'a';
		break;
	case 8: // \b
		color = FOREGROUND_BLUE | FOREGROUND_GREEN;
		cursor = 'b';
		break;
	case 9: // \t
		color = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
		cursor = 't';
		break;
	case 10:// \n
		color = FOREGROUND_RED | FOREGROUND_INTENSITY;
		cursor = 'n';
		break;
	case 13:// \r
		color = FOREGROUND_RED | FOREGROUND_INTENSITY;
		cursor = 'r';
		break;
	case -1:// EOF
		color = FOREGROUND_RED | FOREGROUND_INTENSITY;
		cursor = 'e';
		break;
	}
	// set the color before printing
	SetConsoleTextAttribute(
		GetStdHandle(STD_OUTPUT_HANDLE),
		color);
	printf("%c", cursor);
}