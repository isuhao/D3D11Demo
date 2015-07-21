#include "CameraComponent.h"


CameraComponent::CameraComponent()
{
	Vector3 vEyePt(0.0f, 0.0f, 0.0f);
	Vector3 vLookatPt(0.0f, 0.0f, 1.0f);
	// Setup the view matrix
	SetViewParams(vEyePt, vLookatPt);
	// Setup the projection matrix
	SetProjParams(XM_PIDIV4, 1.0f, 1.0f, 1000.0f);
}


CameraComponent::~CameraComponent()
{

}

void CameraComponent::SetViewParams(Vector3 vEyePt, Vector3 vLookatPt, Vector3 vEyePtUp)
{
	m_vDefaultEye = m_vEye = vEyePt;
	m_vDefaultLookAt = m_vLookAt = vLookatPt;
	// Calc the view matrix


	Vector3 look = (vLookatPt - vEyePt);
	look.Normalize();
	Vector3 right = (vEyePtUp.Cross(look));

	right.Normalize();
	Vector3 up = look.Cross(right);


	//	������� ƽ�ƻ�ԭ�㣬����ת���������غ�
	// Rx  Ry  Rz									1 0 0
	// Ux  Uy Uz    * M == >				0 1 0
	// Lx  Ly   Lz									1 0 1
	//
	// M Ϊ��ת������� ������ת�������������� �������������� ���� ����ת�þ���
	//

	Vector3 NegEyePosition = -vEyePt;

	float x = NegEyePosition.Dot(right);
	float y = NegEyePosition.Dot(up);
	float z = NegEyePosition.Dot(look);
	Matrix ViewMatrix(right, up, look);
	m_mView = ViewMatrix.Transpose();
	m_mView(3, 0) = x;
	m_mView(3, 1) = y;
	m_mView(3, 2) = z;
	m_mView(3, 3) = 1;

	//�ȼ�CreateLookAtLh
	Matrix mView = Matrix::CreateLookAtLh(vEyePt, vLookatPt, vEyePtUp);

	Matrix mInvView;
	m_mView.Invert(mInvView);
}


void CameraComponent::SetProjParams(FLOAT fFOV, FLOAT fAspect, FLOAT fNearPlane, FLOAT fFarPlane)
{
	// Set attributes for the projection matrix
	m_fFOV = fFOV;
	m_fAspect = fAspect;
	m_fNearPlane = fNearPlane;
	m_fFarPlane = fFarPlane;
	//	͸��ͶӰ����ķ���
	// 1/ (tan(&/2))     0    0     0
	// 0		1/(tan(&/2))    0    0	
	// 0   0      f/f-n                1
	// 0   0     -nf/f-n              0
	//
	//
	m_mProj = XMMatrixPerspectiveFovLH(fFOV, fAspect, fNearPlane, fFarPlane);

}

void CameraComponent::Reset()
{

}
