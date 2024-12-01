#include <windows.h>
enum 
{
	black,
	dark_blue,
	dark_green,
	dark_cyan,
	dark_red,
	dark_magenta,
	dark_yellow,
	light_gray,
	dark_gray,
	light_blue,
	light_green,
	light_cyan,
	light_red,
	light_magenta,
	light_yellow,
	white
};

int getcolors()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(
	GetStdHandle( STD_OUTPUT_HANDLE ), 
	&csbi
	);
	return csbi.wAttributes;
}

int getfgcolor()
{
	return getcolors() & 0x0F;
}

int getbgcolor()
{
	return getcolors() >> 4;
}

void setfgcolor( int color )
{
	SetConsoleTextAttribute(
	GetStdHandle( STD_OUTPUT_HANDLE ), 
	(getcolors() & 0xF0) | (color & 0x0F)
	);
}

void setbgcolor( int color )
{
	SetConsoleTextAttribute(
	GetStdHandle( STD_OUTPUT_HANDLE ), 
	((color & 0x0F) << 4) | (getcolors() & 0x0F)
	);
}

void setcolors( int fg, int bg )
{
	SetConsoleTextAttribute(
	GetStdHandle( STD_OUTPUT_HANDLE ), 
	((bg & 0x0F) << 4) | (fg & 0x0F)
	);
}
