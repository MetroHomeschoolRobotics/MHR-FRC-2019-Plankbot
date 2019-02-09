#include "RobotMap.h"

std::shared_ptr<rev::CANSparkMax> RobotMap::tankDriveFrontLeft;
std::shared_ptr<rev::CANSparkMax> RobotMap::tankDriveFrontRight;
std::shared_ptr<rev::CANSparkMax> RobotMap::tankDriveRearRight;
std::shared_ptr<rev::CANSparkMax> RobotMap::tankDriveRearLeft;

std::shared_ptr<WPI_TalonSRX> RobotMap::liftMotor;
std::shared_ptr<frc::Spark> RobotMap::cargoMotor;
std::shared_ptr<frc::Spark> RobotMap::armMotor;
std::shared_ptr<frc::AnalogPotentiometer> RobotMap::armPot;

std::shared_ptr<frc::DoubleSolenoid> RobotMap::octoDriveSwitchSol1;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::liftGrabSol1;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::pusherSol1;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::pusherSol2;

std::shared_ptr<frc::Encoder> RobotMap::liftMotorEncoder;
std::shared_ptr<frc::DigitalInput> RobotMap::manipulatorTopSwitch;
std::shared_ptr<frc::DigitalInput> RobotMap::manipulatorBottomSwitch;

//std::shared_ptr<LidarV3> RobotMap::lidarDistanceSensor;
std::shared_ptr<frc::ADXRS450_Gyro> RobotMap::gyro;
std::shared_ptr<FRCPixy2> RobotMap::pixySPI;
std::shared_ptr<FRCPixy2> RobotMap::pixyI2C;

std::shared_ptr<frc::Compressor> RobotMap::pneumoCharger;
// For Ultrasonic: Devantech SRF04, VEX Ultrasonic Rangefinder
std::shared_ptr<frc::Ultrasonic> RobotMap::ultrasonicDistanceSensor;
// For Ultrasonic: Maxbotix LV-MaxSonar-EZ1
std::shared_ptr<frc::AnalogInput> RobotMap::ultrasonicAnalogDistanceSensor;
int RobotMap::UltrasonicAnalogPort = 0;

std::shared_ptr<AHRS> RobotMap::navGyro;

void RobotMap::init() {

/*
	cs::UsbCamera cam0 = frc::CameraServer::GetInstance()->StartAutomaticCapture();
	cam0.SetFPS(30);
	cam0.SetResolution(640,480);
*/
    tankDriveFrontLeft.reset(new rev::CANSparkMax(0, rev::CANSparkMaxLowLevel::MotorType::kBrushless));
   
    tankDriveFrontRight.reset(new rev::CANSparkMax(2, rev::CANSparkMaxLowLevel::MotorType::kBrushless));

    tankDriveRearRight.reset(new rev::CANSparkMax(3, rev::CANSparkMaxLowLevel::MotorType::kBrushless));

    tankDriveRearLeft.reset(new rev::CANSparkMax(1, rev::CANSparkMaxLowLevel::MotorType::kBrushless));

    frc::SpeedController *fLeft = tankDriveFrontLeft.get();
    frc::SpeedController *rLeft = tankDriveRearLeft.get();
    frc::SpeedController *fRight = tankDriveFrontRight.get();
    frc::SpeedController *rRight = tankDriveRearRight.get();
    
    liftMotor.reset(new WPI_TalonSRX(4));
    cargoMotor.reset(new frc::Spark(9));
    armMotor.reset(new frc::Spark(9));
    armPot.reset(new frc::AnalogPotentiometer(0));

    manipulatorBottomSwitch.reset(new DigitalInput(1));
    manipulatorTopSwitch.reset(new DigitalInput(2));
    
    //lidarDistanceSensor.reset(new LidarV3(new frc::DigitalInput(0)));
    // For Ultrasonic: Devantech SRF04, VEX Ultrasonic Rangefinder
    //ultrasonicDistanceSensor.reset(new Ultrasonic(1, 1));
    // For Ultrasonic: Maxbotix LV-MaxSonar-EZ1
    //ultrasonicAnalogDistanceSensor.reset(new frc::AnalogInput(UltrasonicAnalogPort));

    //gyro.reset(new frc::ADXRS450_Gyro());
    navGyro.reset(new AHRS(SerialPort::kMXP));

/*
    octoDriveSwitchSol1.reset(new frc::DoubleSolenoid(0, 0, 1));
    octoDriveSwitchSol1->Set(frc::DoubleSolenoid::kReverse);
    octoDriveSwitchSol1->SetName("OctoDrive", "SwitchSol1");
    octoDriveSwitchSol1.get()->Set(frc::DoubleSolenoid::Value::kReverse);
    

    pusherSol1.reset(new frc::DoubleSolenoid(0, 2, 3));
    pusherSol1->SetName("Lift", "SwitchSol2");
    pusherSol1.get()->Set(frc::DoubleSolenoid::Value::kReverse);

    pusherSol2.reset(new frc::DoubleSolenoid(0, 4, 5));
    pusherSol2->SetName("Lift", "SwitchSol2");
    pusherSol2.get()->Set(frc::DoubleSolenoid::Value::kReverse);

    liftMotorEncoder.reset(new frc::Encoder(0, 1, false, frc::Encoder::EncodingType::k4X));

    pneumoCharger.reset(new frc::Compressor());
*/
    pixySPI.reset(new FRCPixy2(frc::SPI::kOnboardCS0));
    pixyI2C.reset(new FRCPixy2(frc::I2C::kOnboard , 0));

}

