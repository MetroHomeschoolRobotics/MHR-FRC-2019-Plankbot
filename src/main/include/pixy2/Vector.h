#include <string>
#include <iostream>

	class Vector
	{

	private:
		int x0 = 0, y0 = 0, x1 = 0, y1 = 0, index = 0, flags = 0;

		/**
		 * Constructs Vector instance
		 * 
		 * @param x0    X0 value
		 * @param y0    Y0 value
		 * @param x1    X1 value
		 * @param y1    Y1 value
		 * @param index Vector index
		 * @param flags Vector flags
		 */
	public:
		Vector(int x0, int y0, int x1, int y1, int index, int flags);

		/**
		 * Prints vector data to console
		 */
		virtual void print();

		/**
		 * Returns a string of vector data
		 * 
		 * @return String of vector data
		 */
		virtual std::wstring toString();

		/**
		 * @return X0 value
		 */
		virtual int getX0();

		/**
		 * @return Y0 value
		 */
		virtual int getY0();

		/**
		 * @return X1 value
		 */
		virtual int getX1();

		/**
		 * @return Y1 value
		 */
		virtual int getY1();

		/**
		 * @return Vector index
		 */
		virtual int getIndex();

		/**
		 * @return Vector flags
		 */
		virtual int getFlags();

	};
