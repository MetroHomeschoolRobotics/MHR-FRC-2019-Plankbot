#include "commands/AutoLeft.h"

AutoLeft::AutoLeft() {
	//Requires(Robot::MainDrive());
	AddSequential(new AutoDrive(8500, -0.8,-0.5));
	AddSequential(new AutoDrive(23000, 0,-0.5));
	AddSequential(new AutoDrive(3000, 0.7,-0.5));
	AddSequential(new AutoDrive(2000, 0,-0.5));
}
