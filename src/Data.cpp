
#include "../include/Data.h"

Data::Data()
{
	goals = 0;
	assists = 0;
	saves = 0;
	shots = 0;
	points = 0;
}

void Data::addPos(Pos posXY)
{
	positions.push_back(posXY);
}

std::ostream &operator<<(std::ostream &os, Data &data)
{
	os << "\nData progression: "
	   << "\n\tGoals: " << data.getGoals()
	   << "\n\tAssists: " << data.getAssists()
	   << "\n\tSaves: " << data.getSaves()
	   << "\n\tShots " << data.getShots()
	   << "\n\tPoints: " << data.getPoints()
	   << "\n\nPositions: ";

	for (Pos temp : data.getPositions())
	{
		os << "\n\tx: " << temp.x << ",\ty: " << temp.y;
	}
	return os;
}