#include "RobotMap.h"

std::shared_ptr<frc::MecanumDrive> RobotMap::mainDrive;
std::shared_ptr<WPI_TalonSRX> RobotMap::tankDriveFrontLeft;
std::shared_ptr<WPI_TalonSRX> RobotMap::tankDriveFrontRight;
std::shared_ptr<WPI_TalonSRX> RobotMap::tankDriveRearRight;
std::shared_ptr<WPI_TalonSRX> RobotMap::tankDriveRearLeft;

std::shared_ptr<WPI_TalonSRX> RobotMap::liftMotor;
std::shared_ptr<frc::Spark> RobotMap::corkscrewClampMotor;
std::shared_ptr<frc::Spark> RobotMap::leftBoxIntake;
std::shared_ptr<frc::Spark> RobotMap::rightBoxIntake;

std::shared_ptr<frc::DoubleSolenoid> RobotMap::octoDriveSwitchSol1;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::liftGrabSol1;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::pusherSol1;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::pusherSol2;

std::shared_ptr<frc::Encoder> RobotMap::liftMotorEncoder;

//std::shared_ptr<LidarV3> RobotMap::lidarDistanceSensor;
std::shared_ptr<frc::ADXRS450_Gyro> RobotMap::gyro;

std::shared_ptr<frc::Compressor> RobotMap::pneumoCharger;
// For Ultrasonic: Devantech SRF04, VEX Ultrasonic Rangefinder
std::shared_ptr<frc::Ultrasonic> RobotMap::ultrasonicDistanceSensor;
// For Ultrasonic: Maxbotix LV-MaxSonar-EZ1
std::shared_ptr<frc::AnalogInput> RobotMap::ultrasonicAnalogDistanceSensor;
int RobotMap::UltrasonicAnalogPort = 0;

//std::shared_ptr<AHRS> RobotMap::navGyro;

void RobotMap::init() {

    tankDriveFrontLeft.reset(new WPI_TalonSRX(0));
    
    tankDriveFrontRight.reset(new WPI_TalonSRX(2));

    tankDriveRearRight.reset(new WPI_TalonSRX(3));

    tankDriveRearLeft.reset(new WPI_TalonSRX(1));

    frc::SpeedController *fLeft = tankDriveFrontLeft.get();
    frc::SpeedController *rLeft = tankDriveRearLeft.get();
    frc::SpeedController *fRight = tankDriveFrontRight.get();
    frc::SpeedController *rRight = tankDriveRearRight.get();
    mainDrive.reset(new frc::MecanumDrive(*fLeft, *rLeft, *rRight, *fRight));
    
    liftMotor.reset(new WPI_TalonSRX(4));
    leftBoxIntake.reset(new frc::Spark(0));
    rightBoxIntake.reset(new frc::Spark(1));
    corkscrewClampMotor.reset(new frc::Spark(2));
    
    //lidarDistanceSensor.reset(new LidarV3(new frc::DigitalInput(0)));
    // For Ultrasonic: Devantech SRF04, VEX Ultrasonic Rangefinder
    //ultrasonicDistanceSensor.reset(new Ultrasonic(1, 1));
    // For Ultrasonic: Maxbotix LV-MaxSonar-EZ1
    ultrasonicAnalogDistanceSensor.reset(new frc::AnalogInput(UltrasonicAnalogPort));

    gyro.reset(new frc::ADXRS450_Gyro());
    //navGyro.reset(new AHRS(SerialPort::kMXP));

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
}
