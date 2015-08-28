#include "FEulerAngle.h"
#include "FQuaternion.h"
#include "UnrealMathUtility.h"


const FEulerAngle FEulerAngle::ZeroRotator(0.f, 0.f, 0.f);

FEulerAngle::FEulerAngle(float InPitch, float InYaw, float InRoll)
	: Pitch(InPitch), Yaw(InYaw), Roll(InRoll)
{

}

FEulerAngle::FEulerAngle(const FEulerAngle& Euler)
	: Pitch(Euler.Pitch), Yaw(Euler.Yaw), Roll(Euler.Roll)

{

}

FQuaternion FEulerAngle::Quaternion() const
{
	//UE �е�Roll ��Ӧ����X����ת   --  DX ��Ϊ -Pitch�������ַ����෴��
	//UE �е�Pitch ��Ӧ����Y����ת --  DX ��Ϊ -Yaw�������ַ����෴��
	//UE �е�Yaw ��Ӧ����Z����ת  --  DX ��Ϊ -Roll��Z�᷽����һ���ģ�
	
	//Roll = -Pitch
	//Pitch = -Yaw
	//Yaw = Roll
	//��DX--UE
	VectorRegister Angles = MakeVectorRegister(-Pitch, -Yaw, Roll, 0.0f);
	VectorRegister HalfAngles = VectorMultiply(Angles, GlobalVectorConstants::DEG_TO_RAD_HALF);
	union { VectorRegister v; float f[4]; } SinAngles, CosAngles;
	VectorSinCos(&SinAngles.v, &CosAngles.v, &HalfAngles);

	const float	SR = SinAngles.f[0];
	const float	SP = SinAngles.f[1];
	const float	SY = SinAngles.f[2];
	const float	CR = CosAngles.f[0];
	const float	CP = CosAngles.f[1];
	const float	CY = CosAngles.f[2];

	FQuaternion RotationQuat;
	RotationQuat.W = CR*CP*CY + SR*SP*SY;
	RotationQuat.X = CR*SP*SY - SR*CP*CY;
	RotationQuat.Y = -CR*SP*CY - SR*CP*SY;
	RotationQuat.Z = CR*CP*SY - SR*SP*CY;

	return RotationQuat;;
}

FEulerAngle FEulerAngle::MakeFromEuler(const FVector& Euler)
{
	return FEulerAngle(Euler.x, Euler.y, Euler.z);
}

void FEulerAngle::Normalize()
{
	VectorRegister VRotator = VectorLoadFloat3_W0(this);
	VRotator = VectorNormalizeRotator(VRotator);
	VectorStoreFloat3(VRotator, this);
}

FEulerAngle FEulerAngle::UEToDX()
{
	FEulerAngle a(*this);
	//Roll = -Pitch
	//Pitch = -Yaw
	//Yaw = Roll
	//��DX--UE
	a.Pitch = -Roll;
	a.Yaw = -Pitch;
	a.Roll = Yaw;
	return a;
}

FEulerAngle FEulerAngle::DXToUE()
{
	FEulerAngle a(*this);
	//Roll = -Pitch
	//Pitch = -Yaw
	//Yaw = Roll
	//��DX--UE
	a.Roll = -Pitch;
	a.Pitch = -Yaw;
	a.Yaw = Roll;
	return a;
}


