#ifndef DATA_H
#define DATA_H

#include <vector>

struct Pos
{
	int x, y;
};

class Data
{
private:
	int goals;
	int saves;
	int assists;
	int shots;
	int points;
	std::vector<Pos> positions;

public:
	Data();

	// getters and setters
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
};

#endif // DATA_H