#include "pixy2/LineFeatures.h"

LineFeatures::LineFeatures()
{
}

LineFeatures::LineFeatures(std::vector<Vector*> &vectors, std::vector<Intersection*> &intersections, std::vector<Barcode*> &barcodes)
{
	_vectors = vectors;
	_intersections = intersections;
	_barcodes = barcodes;
}

std::vector<Barcode*> LineFeatures::Barcodes()
{
	return _barcodes;
}

std::vector<Intersection*> LineFeatures::Intersections()
{
	return _intersections;
}

std::vector<Vector*> LineFeatures::Vectors()
{
	return _vectors;
}
