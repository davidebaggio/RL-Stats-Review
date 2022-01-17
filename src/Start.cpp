
#include "../include/Data.h"

int main()
{
	Data data = Data();
	Pos posXY;
	posXY.x = 10;
	posXY.y = 20;

	data.setGoals(10);
	data.addPos(posXY);
	std::cout << data;
}