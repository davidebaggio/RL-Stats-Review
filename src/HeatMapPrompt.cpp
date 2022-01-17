#include "../include/HeatMapPrompt.h"

int HeatMap::findMaxInMatrix(int row, int col, int offset)
{
	int max = 0;

	for (int i = row; i < offset; i++)
	{
		for (int j = col; j < offset; j++)
		{
			if (max < pitch[i][j])
				max = pitch[i][j];
		}
	}
	return max;
}

HeatMap::HeatMap()
{
	HEIGHT = 110;
	WIDTH = 70;
	pitch = new int *[HEIGHT];
	for (int i = 0; i < HEIGHT; i++)
	{
		pitch[i] = new int[WIDTH];
		for (int j = 0; j < WIDTH; j++)
		{
			pitch[i][j] = 0;
		}
	}
}

HeatMap::HeatMap(int **posPitch, int height, int width)
{
	HEIGHT = height;
	WIDTH = width;
	pitch = new int *[HEIGHT];
	for (int i = 0; i < HEIGHT; i++)
	{
		pitch[i] = new int[WIDTH];
		for (int j = 0; j < WIDTH; j++)
		{
			pitch[i][j] = posPitch[i][j];
		}
	}
}

void HeatMap::pitchUpdate(int height, int width)
{
	pitch[height][width]++;
}

HeatMap HeatMap::scaleBy2()
{
	int **scaledHeatMap;
	scaledHeatMap = new int *[HEIGHT / 2];
	for (int i = 0; i < HEIGHT / 2; i++)
	{
		scaledHeatMap[i] = new int[WIDTH / 2];
		for (int j = 0; j < WIDTH / 2; j++)
		{
			int max = pitch[i * 2][j * 2];
			if (max < pitch[i * 2][j * 2 + 1])
				max = pitch[i * 2][j * 2 + 1];
			if (max < pitch[i * 2 + 1][j * 2])
				max = pitch[i * 2 + 1][j * 2];
			if (max < pitch[i * 2 + 1][j * 2 + 1])
				max = pitch[i * 2 + 1][j * 2 + 1];
			scaledHeatMap[i][j] = max;
		}
	}
	return HeatMap(scaledHeatMap, HEIGHT / 2, WIDTH / 2);
}

HeatMap HeatMap::scaleByFactor(int factor)
{
	if (factor != 2 && factor != 5 && factor != 10)
		throw InvalidFactor();

	int height = HEIGHT / factor;
	int width = WIDTH / factor;
	int **scaledHeatMap;
	scaledHeatMap = new int *[height];
	for (int i = 0; i < height; i++)
	{
		scaledHeatMap[i] = new int[width];
		for (int j = 0; j < width; j++)
		{
			scaledHeatMap[i][j] = findMaxInMatrix(i * factor, j * factor, factor);
		}
	}
	return HeatMap(scaledHeatMap, height, width);
}

std::ostream &operator<<(std::ostream &os, const HeatMap &map)
{
	os << "\n\nHEATMAP: \n";
	int **temp = map.getPitch();
	for (int i = 0; i < map.getHeight(); i++)
	{
		for (int j = 0; j < map.getWidth(); j++)
		{
			os << temp[i][j] << " ";
		}
		os << "\n";
	}

	return os;
}