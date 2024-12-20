void DriveStraight(int FastSpeed, int SlowSpeed, int cts);

task mian()
{
  
}

void DriveStraight(int FastSpeed, int SlowSpeed, int cts)
{
	resetMotorEncoder(M_Motor_Left);
	resetMotorEncoder(M_Motor_Right);
	while(getMotorEncoder(M_Motor_Left) < cts)
	{
		if(getMotorEncoder(M_Motor_Right) > getMotorEncoder(M_Motor_Left))
		{
			motor(M_Motor_Left) = FastSpeed;
			motor(M_Motor_Right) = SlowSpeed;
		}
		if(getMotorEncoder(M_Motor_Right) < getMotorEncoder(M_Motor_Left))
		{
			motor(M_Motor_Left) = SlowSpeed;
			motor(M_Motor_Right) = FastSpeed;
		}
		if(getMotorEncoder(M_Motor_Right) == getMotorEncoder(M_Motor_Left))
		{
			motor(M_Motor_Left) = SlowSpeed;
			motor(M_Motor_Right) = SlowSpeed;
		}
	}
	motor(M_Motor_Left) = 0;
	motor(M_Motor_Right) = 0;
}
