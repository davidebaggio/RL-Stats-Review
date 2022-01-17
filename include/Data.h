#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <vector>
#include "Pos.h"
#include "HeatMapPrompt.h"

/**
 * @brief Class Data, stores number of: Goals, Saves, Assists, Shots, Points and Pos
 */
class Data
{
private:
	int goals;
	int saves;
	int assists;
	int shots;
	int points;
	std::vector<Pos> positions;
	HeatMap map;

public:
	Data();

	inline HeatMap &getHeatMap() { return map; }

	inline int getGoals() { return goals; }
	inline void setGoals(int nGoals) { goals += nGoals; }

	inline int getSaves() { return saves; }
	inline void setSaves(int nSaves) { saves += nSaves; }

	inline int getAssists() { return assists; }
	inline void setAssists(int nAssists) { assists += nAssists; }

	inline int getShots() { return shots; }
	inline void setShots(int nShots) { shots += nShots; }

	inline int getPoints() { return points; }
	inline void setPoints(int nPoints) { points += nPoints; }

	inline std::vector<Pos> &getPositions() { return positions; }
	void addPos(Pos);
};

// helper functions

/**
 * @brief Overload of operator <<
 * Prints the current statistics of the match.
 *
 * @return std::ostream&
 */
std::ostream &operator<<(std::ostream &, Data &);

#endif // DATA_H