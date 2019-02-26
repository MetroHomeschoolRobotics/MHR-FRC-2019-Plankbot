#pragma once

#include <vector>
#include "Intersection.h"
#include "Barcode.h"
#include "Vector.h"

class LineFeatures
{
	private:
		std::vector<Vector*> _vectors;
		std::vector<Intersection*> _intersections;
		std::vector<Barcode*> _barcodes;

	public:
		LineFeatures();
		LineFeatures(std::vector<Vector*> &vectors, std::vector<Intersection*> &intersections, std::vector<Barcode*> &barcodes);

		virtual std::vector<Barcode*> Barcodes();

		virtual std::vector<Intersection*> Intersections();

		virtual std::vector<Vector*> Vectors();
};
