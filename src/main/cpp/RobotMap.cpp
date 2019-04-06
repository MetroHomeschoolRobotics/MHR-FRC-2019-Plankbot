#include "RobotMap.h"

std::shared_ptr<rev::CANSparkMax> RobotMap::tankDriveFrontLeft;
std::shared_ptr<rev::CANSparkMax> RobotMap::tankDriveFrontRight;
std::shared_ptr<rev::CANSparkMax> RobotMap::tankDriveRearRight;
std::shared_ptr<rev::CANSparkMax> RobotMap::tankDriveRearLeft;

std::shared_ptr<WPI_TalonSRX> RobotMap::liftMotor;
std::shared_ptr<WPI_TalonSRX> RobotMap::cargoMotor;
std::shared_ptr<WPI_TalonSRX> RobotMap::armMotor;

std::shared_ptr<frc::DoubleSolenoid> RobotMap::octoDriveSwitchSol1;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::liftGrabSol1;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::pusherSol1;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::pusherSol2;

std::shared_ptr<frc::Encoder> RobotMap::liftMotorEncoder;
std::shared_ptr<frc::Encoder> RobotMap::armMotorEncoder;
std::shared_ptr<frc::DigitalInput> RobotMap::manipulatorTopSwitch;
std::shared_ptr<frc::DigitalInput> RobotMap::manipulatorBottomSwitch;

std::shared_ptr<frc::ADXRS450_Gyro> RobotMap::gyro;
std::shared_ptr<FRCPixy2> RobotMap::pixySPI;
std::shared_ptr<FRCPixy2> RobotMap::pixyI2C;

std::shared_ptr<frc::Compressor> RobotMap::pneumoCharger;
std::shared_ptr<frc::Ultrasonic> RobotMap::ultrasonicDistanceSensor;
std::shared_ptr<frc::AnalogInput> RobotMap::ultrasonicAnalogDistanceSensor;
int RobotMap::UltrasonicAnalogPort = 0;

std::shared_ptr<AHRS> RobotMap::navGyro;

void RobotMap::init() {


	cs::UsbCamera cam0 = frc::CameraServer::GetInstance()->StartAutomaticCapture();
	cam0.SetFPS(30);
	//cam0.SetResolution(640,480);
    cam0.SetResolution(200, 150);

    tankDriveFrontLeft.reset(new rev::CANSparkMax(1, rev::CANSparkMaxLowLevel::MotorType::kBrushless));
   
    tankDriveFrontRight.reset(new rev::CANSparkMax(3, rev::CANSparkMaxLowLevel::MotorType::kBrushless));

    tankDriveRearRight.reset(new rev::CANSparkMax(4, rev::CANSparkMaxLowLevel::MotorType::kBrushless));

    tankDriveRearLeft.reset(new rev::CANSparkMax(2, rev::CANSparkMaxLowLevel::MotorType::kBrushless));

    frc::SpeedController *fLeft = tankDriveFrontLeft.get();
    frc::SpeedController *rLeft = tankDriveRearLeft.get();
    frc::SpeedController *fRight = tankDriveFrontRight.get();
    frc::SpeedController *rRight = tankDriveRearRight.get();
    
    liftMotor.reset(new WPI_TalonSRX(4));
    cargoMotor.reset(new WPI_TalonSRX(2));
    armMotor.reset(new WPI_TalonSRX(1));

    manipulatorBottomSwitch.reset(new DigitalInput(1));
     manipulatorTopSwitch.reset(new DigitalInput(2));
    
    navGyro.reset(new AHRS(SPI::kMXP));
    //navGyro.reset(new AHRS(SerialPort::kMXP));

    armMotorEncoder.reset(new frc::Encoder(3, 4, false, frc::Encoder::EncodingType::k4X));

    /*
    pixySPI.reset(new FRCPixy2(frc::SPI::kOnboardCS0));
    pixyI2C.reset(new FRCPixy2(frc::I2C::kOnboard , 0));
    */

}

