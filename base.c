#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_3,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_4,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           chassisLeftRear, tmotorVex393_HBridge, openLoop, encoderPort, I2C_1)
#pragma config(Motor,  port2,           chassisLeftFront, tmotorVex393_MC29, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port3,           armRight1,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           armRight2,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           clawRight,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           clawLeft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           armLeft2,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           armLeft1,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           chassisRightFront, tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_3)
#pragma config(Motor,  port10,          chassisRightRear, tmotorVex393_HBridge, openLoop, reversed, encoderPort, I2C_4)

#include "competition-config.lib.h"
#include "joystick-calibration.lib.h"

#include "function-definitions.c"

#include "autonomous.c"
#include "user-control.c"
