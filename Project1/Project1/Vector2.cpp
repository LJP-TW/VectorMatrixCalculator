#include "Vector.h"

constexpr auto THRESHOLD = 10E-12;

Vector::Vector(double d)
{
	this->Data.push_back(d);
}

bool isln(std::vector<Vector> vectors)
{
	if (vectors.size() == 0)
	{
		return false;
	}

	unsigned int d = vectors[0].Data.size();
	for (unsigned int i = 1; i < vectors.size(); ++i)
	{
		if (vectors[i].Data.size() != d)
		{
			throw VECTOR_ERROR::DIMENSION_NON_EQUIVALENT;
		}
	}

	bool result = false;

	// Gaussian elimination to get r.e.f.
	for (unsigned int current_y = 0, current_x = 0; \
		current_y < vectors.size() && current_x < vectors[0].Data.size(); \
		++current_y, ++current_x)
	{
		// Search for maximum in this column
		double maxNum = abs(vectors[current_y].Data[current_x]);
		unsigned int maxRow = current_y;
		for (unsigned int r = current_y + 1; r < vectors.size(); ++r)
		{
			if (abs(vectors[r].Data[current_x]) > maxNum)
			{
				maxNum = abs(vectors[r].Data[current_x]);
				maxRow = r;
			}
		}

		if (!maxNum)
		{
			--current_y;
			continue;
		}

		// Swap maxRow to current row
		Vector temp = vectors[current_y];
		vectors[current_y] = vectors[maxRow];
		vectors[maxRow] = temp;

		// Doing elimination
		for (unsigned int r = current_y + 1; r < vectors.size(); ++r)
		{
			if (!vectors[r].Data[current_x])
			{
				continue;
			}

			vectors[r] = vectors[r] - vectors[current_y] * Vector(vectors[r].Data[current_x] / vectors[current_y].Data[current_x]);
		}
	}

	for (unsigned int y = 0; y < vectors.size(); ++y)
	{
		for (unsigned int x = 0; x < vectors[0].Data.size(); ++x)
		{
			// threshold
			if (abs(vectors[y].Data[x]) < THRESHOLD)
			{
				vectors[y].Data[x] = 0;
			}
		}
	}

	// Check if 0 row exist
	for (int x = vectors[0].Data.size() - 1; x >= 0; --x)
	{
		if (vectors[vectors.size() - 1].Data[x] != 0)
		{
			result = true;
			break;
		}
	}

	return result;
}