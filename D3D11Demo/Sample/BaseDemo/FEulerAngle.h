#pragma once
#include "HpD3D9Type.h"

class FQuaternion;
//DX ��������ϵ left x  up y look  z
//pitch()����������������X����ת��localRotationX��
//yaw()�����򣬽�������Y����ת��localRotationY��
//roll()���������������Z����ת��localRotationZ��

//DX����ϵ(x,y,z) �ڲ������õ���UE ����ϵ

class FEulerAngle
{
public:
	float Pitch;	 //����,��������X����ת��localRotationX��
	float Yaw;		//����,��������Y����ת��localRotationY��
	float Roll;		//���,��������Z����ת��localRotationZ��

	static  const FEulerAngle ZeroRotator;
public:
	FEulerAngle(){};
	FEulerAngle(const FEulerAngle& Euler);

	FEulerAngle(float InPitch, float InYaw, float InRoll);
	FQuaternion Quaternion() const;
	void Normalize();

	FEulerAngle UEToDX();
	FEulerAngle DXToUE();

public:
	static FEulerAngle MakeFromEuler(const FVector& Euler);
};

