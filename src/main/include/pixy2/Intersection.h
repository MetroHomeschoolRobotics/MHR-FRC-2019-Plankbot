#pragma once

#include <vector>
#include <iostream>
//#include "pixy2/FRCPixy2.h"

class IntersectionLine
{
	private:
		int index = 0, reserved = 0;
		short angle = 0;

		/**
		 * Constructs IntersectionLine object
		 * 
		 * @param index    IntersectionLine index
		 * @param reserved Reserved
		 * @param angle    Line angle
		 */
	public:
		IntersectionLine(int index, int reserved, short angle);
		/**
		 * @return IntersectionLine index
		 */
		virtual int getIndex();

		/**
		 * @return Reserved
		 */
		virtual int getReserved();

		/**
		 * @return Line angle
		 */
		virtual short getAngle();
    };
	class Intersection
	{
	private:
		int x = 0, y = 0, number = 0, reserved = 0;
		std::vector<IntersectionLine*> lines = std::vector<IntersectionLine*>(LINE_MAX_INTERSECTION_LINES);

		/**
		 * Constructs Intersection object
		 * 
		 * @param x        X value
		 * @param y        Y value
		 * @param number   Number of lines
		 * @param reserved Reserved
		 * @param lines    Array of lines
		 */
	public:
		Intersection(int x, int y, int number, int reserved, std::vector<IntersectionLine*> &lines);
    	static const std::uint8_t LINE_MAX_INTERSECTION_LINES = 6;

		/**
		 * Prints intersection data to console
		 */
		virtual void print();
		/**
		 * @return X value
		 */
		virtual int getX();
		/**
		 * @return Y value
		 */
		virtual int getY();
		/**
		 * @return Number of lines
		 */
		virtual int getNumber();
		/**
		 * @return Reserved
		 */
		virtual int getReserved();
		/**
		 * @return Array of lines
		 */
		virtual std::vector<IntersectionLine*> getLines();
	};
