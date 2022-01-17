#ifndef HEATMAPPROMPT_H
#define HEATMAPPROMPT_H

#include <iostream>

class HeatMap
{
private:
	int HEIGHT, WIDTH;
	int **pitch;

	int findMaxInMatrix(int, int, int);

public:
	HeatMap();
	HeatMap(int **, int, int);

	inline int getHeight() const { return HEIGHT; }
	inline int getWidth() const { return WIDTH; }
	inline int **getPitch() const { return pitch; }

	void pitchUpdate(int, int);

	HeatMap scaleBy2();
	HeatMap scaleByFactor(int);

	class InvalidFactor
	{
	};
};

/**
 * @brief Overload of operator <<
 * Prints the current HeatMap of yuor match.
 *
 * @return std::ostream&
 */
std::ostream &operator<<(std::ostream &, const HeatMap &);

#endif // HEATMAPPROPMPT_H