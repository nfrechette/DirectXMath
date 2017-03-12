// DirectXMathTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Inc\DirectXMath.h"
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <random>

using namespace DirectX;

extern void ProfileMatrixMultiply();

int main()
{
	ProfileMatrixMultiply();

	printf("Press any key to continue...\n");
	while (_kbhit() == 0);

	return 0;
}

