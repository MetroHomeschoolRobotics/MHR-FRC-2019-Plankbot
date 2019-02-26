#include <string>
#include <iostream>

	class Barcode
	{

	private:
		int x = 0, y = 0, flags = 0, code = 0;

		/**
		 * Constructs barcode object
		 * 
		 * @param x     X value
		 * @param y     Y value
		 * @param flags Barcode flags
		 * @param code  Code
		 */
	public:
		Barcode(int x, int y, int flags, int code);

		/**
		 * Prints barcode data to console
		 */
		virtual void print();

		/**
		 * Returns a string of barcode data
		 * 
		 * @return String of barcode data
		 */
		virtual std::wstring toString();

		/**
		 * @return X value
		 */
		virtual int getX();

		/**
		 * @return Y value
		 */
		virtual int getY();

		/**
		 * @return Barcode flags
		 */
		virtual int getFlags();

		/**
		 * @return Code
		 */
		virtual int getCode();

	};
