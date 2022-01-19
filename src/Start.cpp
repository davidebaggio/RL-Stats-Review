
#include "../include/Data.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
	srand(time(NULL));
	Data data = Data();

	Pos posXY;
	for (int i = 0; i < 300; i++)
	{
		posXY.x = rand() % 110;
		posXY.y = rand() % 70;
		data.addPos(posXY);
	}

	data.setGoals(10);
	std::cout << data;
	if (argc <= 1)
		std::cout << data.getHeatMap();
	else if (strcmp(argv[1], "-s2") == 0)
		std::cout << data.getHeatMap().scaleBy2();
	else if (strcmp(argv[1], "-s5") == 0)
		std::cout << data.getHeatMap().scaleByFactor(5);
	else if (strcmp(argv[1], "-s10") == 0)
		std::cout << data.getHeatMap().scaleByFactor(10);
	std::string str;
	std::cin >> str;
}