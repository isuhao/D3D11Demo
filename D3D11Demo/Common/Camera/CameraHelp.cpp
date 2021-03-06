#include "CameraHelp.h"


CameraHelp::CameraHelp()
{
}


CameraHelp::~CameraHelp()
{
}

void CameraHelp::ConstructFrustum(Matrix viewMatrix, Matrix projectionMatrix)
{
	//http://blog.csdn.net/i_dovelemon/article/details/39693373
	Matrix matrix = viewMatrix * projectionMatrix;
	// Calculate near plane of frustum.
	m_planes[0].x = matrix(0, 3) + matrix(0, 2);
	m_planes[0].y = matrix(1, 3) + matrix(1, 2);
	m_planes[0].z = matrix(2, 3) + matrix(2, 2);
	m_planes[0].w = matrix(3, 3) + matrix(3, 2);
	m_planes[0].Normalize();

	m_planes[0].x = matrix(0, 2);
	m_planes[0].y = matrix(1, 2);
	m_planes[0].z = matrix(2, 2);
	m_planes[0].w = matrix(3, 2);
	m_planes[0].Normalize();

	// Calculate far plane of frustum.
	m_planes[1].x = matrix(0, 3) - matrix(0, 2);
	m_planes[1].y = matrix(1, 3) - matrix(1, 2);
	m_planes[1].z = matrix(2, 3) - matrix(2, 2);
	m_planes[1].w = matrix(3, 3) - matrix(3, 2);
	m_planes[1].Normalize();


	// Calculate left plane of frustum.
	m_planes[2].x = matrix(0, 3) + matrix(0, 0);
	m_planes[2].y = matrix(1, 3) + matrix(1, 0);
	m_planes[2].z = matrix(2, 3) + matrix(2, 0);
	m_planes[2].w = matrix(3, 3) + matrix(3, 0);
	m_planes[2].Normalize();


	// Calculate right plane of frustum.
	m_planes[3].x = matrix(0, 3) - matrix(0, 0);
	m_planes[3].y = matrix(1, 3) - matrix(1, 0);
	m_planes[3].z = matrix(2, 3) - matrix(2, 0);
	m_planes[3].w = matrix(3, 3) - matrix(3, 0);
	m_planes[3].Normalize();


	// Calculate top plane of frustum.
	m_planes[4].x = matrix(0, 3) - matrix(0, 1);
	m_planes[4].y = matrix(1, 3) - matrix(1, 1);
	m_planes[4].z = matrix(2, 3) - matrix(2, 1);
	m_planes[4].w = matrix(3, 3) - matrix(3, 1);
	m_planes[4].Normalize();


	// Calculate bottom plane of frustum.
	m_planes[5].x = matrix(0, 3) + matrix(0, 1);
	m_planes[5].y = matrix(1, 3) + matrix(1, 1);
	m_planes[5].z = matrix(2, 3) + matrix(2, 1);
	m_planes[5].w = matrix(3, 3) + matrix(3, 1);
	m_planes[5].Normalize();
}

bool CameraHelp::CheckSphere(float xCenter, float yCenter, float zCenter, float radius)
{
	int i;
	// Check if the radius of the sphere is inside the view frustum.
	for (i = 0; i < 6; i++)
	{
		float fDinate = m_planes[i].DotCoordinate(Vector3(xCenter, yCenter, zCenter));
		if (fDinate < -radius)
		{
			return false;
		}
	}
	return true;
}

bool CameraHelp::CheckPoint(float x, float y, float z)
{
	int i;
	// Check if the point is inside all six planes of the view frustum.
	for (i = 0; i < 6; i++)
	{
		float fDinate = m_planes[i].DotCoordinate(Vector3(x, y, z));
		if (fDinate < 0.0f)
		{
			return false;
		}
	}
	return true;
}

bool CameraHelp::CheckCube(float xCenter, float yCenter, float zCenter, float radius)
{
	int i;


	// Check if any one point of the cube is in the view frustum.
	for (i = 0; i < 6; i++)
	{
		float fDinate = m_planes[i].DotCoordinate(Vector3((xCenter - radius), (yCenter - radius), (zCenter - radius)));
		if (fDinate >= 0.0f)
		{
			continue;
		}

		fDinate = m_planes[i].DotCoordinate(Vector3((xCenter + radius), (yCenter - radius), (zCenter - radius)));
		if (fDinate >= 0.0f)
		{
			continue;
		}
		fDinate = m_planes[i].DotCoordinate(Vector3((xCenter - radius), (yCenter + radius), (zCenter - radius)));
		if (fDinate >= 0.0f)
		{
			continue;
		}
		fDinate = m_planes[i].DotCoordinate(Vector3((xCenter + radius), (yCenter + radius), (zCenter - radius)));
		if (fDinate >= 0.0f)
		{
			continue;
		}
		fDinate = m_planes[i].DotCoordinate(Vector3((xCenter - radius), (yCenter - radius), (zCenter + radius)));
		if (fDinate >= 0.0f)
		{
			continue;
		}
		fDinate = m_planes[i].DotCoordinate(Vector3((xCenter + radius), (yCenter - radius), (zCenter + radius)));
		if (fDinate >= 0.0f)
		{
			continue;
		}
		fDinate = m_planes[i].DotCoordinate(Vector3((xCenter - radius), (yCenter + radius), (zCenter + radius)));
		if (fDinate >= 0.0f)
		{
			continue;
		}
		fDinate = m_planes[i].DotCoordinate(Vector3((xCenter + radius), (yCenter + radius), (zCenter + radius)));
		if (fDinate >= 0.0f)
		{
			continue;
		}
		return false;
	}

	return true;
}

bool CameraHelp::CheckRectangle(float xCenter, float yCenter, float zCenter, float xSize, float ySize, float zSize)
{
	int i;

	// Check if any of the 6 planes of the rectangle are inside the view frustum.
	for (i = 0; i < 6; i++)
	{
		float fDinate = m_planes[i].DotCoordinate(Vector3((xCenter - xSize), (yCenter - ySize), (zCenter - zSize)));
		if (fDinate >= 0.0f)
		{
			continue;
		}
		fDinate = m_planes[i].DotCoordinate(Vector3((xCenter + xSize), (yCenter - ySize), (zCenter - zSize)));
		if (fDinate >= 0.0f)
		{
			continue;
		}
		fDinate = m_planes[i].DotCoordinate(Vector3((xCenter - xSize), (yCenter + ySize), (zCenter - zSize)));
		if (fDinate >= 0.0f)
		{
			continue;
		}
		fDinate = m_planes[i].DotCoordinate(Vector3((xCenter - xSize), (yCenter - ySize), (zCenter + zSize)));
		if (fDinate >= 0.0f)
		{
			continue;
		}
		fDinate = m_planes[i].DotCoordinate(Vector3((xCenter + xSize), (yCenter + ySize), (zCenter - zSize)));
		if (fDinate >= 0.0f)
		{
			continue;
		}
		fDinate = m_planes[i].DotCoordinate(Vector3((xCenter + xSize), (yCenter - ySize), (zCenter + zSize)));
		if (fDinate >= 0.0f)
		{
			continue;
		}
		fDinate = m_planes[i].DotCoordinate(Vector3((xCenter - xSize), (yCenter + ySize), (zCenter + zSize)));
		if (fDinate >= 0.0f)
		{
			continue;
		}
		fDinate = m_planes[i].DotCoordinate(Vector3((xCenter + xSize), (yCenter + ySize), (zCenter + zSize)));
		if (fDinate >= 0.0f)
		{
			continue;
		}
		return false;
	}

	return true;
}



void CameraHelp::GetFrustumMeshElements(std::vector<VertexPositionColor>& vecPos, int nWidth, int nHeight)
{
	vecPos.clear();

	float fAspectRatio = (float)nWidth / (float)nHeight;
	float FrustumStartDist = 10.0f;
	float FrustumEndDist = 1000.0f;

	float HozLength = 0.0f;
	float VertLength = 0.0f;

	HozLength = FrustumStartDist* tanf(XM_PIDIV4 / 2);
	VertLength = HozLength / fAspectRatio;

	Vector3 Direction(0, 0, 1);
	Vector3 LeftVector(1, 0, 0);
	Vector3 UpVector(0, 1, 0);
	Vector3 Verts[8];

	// near plane verts
	Verts[0] = (Direction * FrustumStartDist) + (UpVector * VertLength) + (LeftVector * HozLength);
	Verts[1] = (Direction * FrustumStartDist) + (UpVector * VertLength) - (LeftVector * HozLength);
	Verts[2] = (Direction * FrustumStartDist) - (UpVector * VertLength) - (LeftVector * HozLength);
	Verts[3] = (Direction * FrustumStartDist) - (UpVector * VertLength) + (LeftVector * HozLength);

	if (XM_PIDIV4 > 0.0f)
	{
		HozLength = FrustumEndDist * tanf(XM_PIDIV4 / 2);
		VertLength = HozLength / fAspectRatio;
	}

	// far plane verts
	Verts[4] = (Direction * FrustumEndDist) + (UpVector * VertLength) + (LeftVector * HozLength);
	Verts[5] = (Direction * FrustumEndDist) + (UpVector * VertLength) - (LeftVector * HozLength);
	Verts[6] = (Direction * FrustumEndDist) - (UpVector * VertLength) - (LeftVector * HozLength);
	Verts[7] = (Direction * FrustumEndDist) - (UpVector * VertLength) + (LeftVector * HozLength);

		vecPos.push_back(VertexPositionColor(Verts[0], XMFLOAT4(1, 0, 0, 1)));
		vecPos.push_back(VertexPositionColor(Verts[1], XMFLOAT4(1, 0, 0, 1)));
		vecPos.push_back(VertexPositionColor(Verts[1], XMFLOAT4(1, 0, 0, 1)));
		vecPos.push_back(VertexPositionColor(Verts[2], XMFLOAT4(1, 0, 0, 1)));

		vecPos.push_back(VertexPositionColor(Verts[2], XMFLOAT4(1, 0, 0, 1)));
		vecPos.push_back(VertexPositionColor(Verts[3], XMFLOAT4(1, 0, 0, 1)));

		vecPos.push_back(VertexPositionColor(Verts[3], XMFLOAT4(1, 0, 0, 1)));
		vecPos.push_back(VertexPositionColor(Verts[0], XMFLOAT4(1, 0, 0, 1)));

		vecPos.push_back(VertexPositionColor(Verts[4], XMFLOAT4(1, 0, 0, 1)));
		vecPos.push_back(VertexPositionColor(Verts[5], XMFLOAT4(1, 0, 0, 1)));
		vecPos.push_back(VertexPositionColor(Verts[5], XMFLOAT4(1, 0, 0, 1)));
		vecPos.push_back(VertexPositionColor(Verts[6], XMFLOAT4(1, 0, 0, 1)));
		vecPos.push_back(VertexPositionColor(Verts[6], XMFLOAT4(1, 0, 0, 1)));
		vecPos.push_back(VertexPositionColor(Verts[7], XMFLOAT4(1, 0, 0, 1)));
		vecPos.push_back(VertexPositionColor(Verts[7], XMFLOAT4(1, 0, 0, 1)));
		vecPos.push_back(VertexPositionColor(Verts[4], XMFLOAT4(1, 0, 0, 1)));

		vecPos.push_back(VertexPositionColor(Verts[0], XMFLOAT4(1, 0, 0, 1)));
		vecPos.push_back(VertexPositionColor(Verts[4], XMFLOAT4(1, 0, 0, 1)));
		vecPos.push_back(VertexPositionColor(Verts[1], XMFLOAT4(1, 0, 0, 1)));
		vecPos.push_back(VertexPositionColor(Verts[5], XMFLOAT4(1, 0, 0, 1)));
		vecPos.push_back(VertexPositionColor(Verts[2], XMFLOAT4(1, 0, 0, 1)));
		vecPos.push_back(VertexPositionColor(Verts[6], XMFLOAT4(1, 0, 0, 1)));
		vecPos.push_back(VertexPositionColor(Verts[3], XMFLOAT4(1, 0, 0, 1)));
		vecPos.push_back(VertexPositionColor(Verts[7], XMFLOAT4(1, 0, 0, 1)));

}

void CameraHelp::GetFrustumMeshElementsEx(std::vector<VertexPositionColor>& vecPos, int nWidth, int nHeight)
{
	vecPos.clear();

	float fAspectRatio = (float)nWidth / (float)nHeight;
	float FrustumStartDist = 10.0f;
	float FrustumEndDist = 1000.0f;

	float HozLength = 0.0f;
	float VertLength = 0.0f;

	HozLength = FrustumStartDist* tanf(XM_PIDIV4 / 2);
	VertLength = HozLength / fAspectRatio;

	Vector3 Direction(0, 0, 1);
	Vector3 LeftVector(1, 0, 0);
	Vector3 UpVector(0, 1, 0);
	Vector3 Verts[8];

	// near plane verts
	Verts[0] = (Direction * FrustumStartDist) + (UpVector * VertLength) + (LeftVector * HozLength);
	Verts[1] = (Direction * FrustumStartDist) + (UpVector * VertLength) - (LeftVector * HozLength);
	Verts[2] = (Direction * FrustumStartDist) - (UpVector * VertLength) - (LeftVector * HozLength);
	Verts[3] = (Direction * FrustumStartDist) - (UpVector * VertLength) + (LeftVector * HozLength);

	if (XM_PIDIV4 > 0.0f)
	{
		HozLength = FrustumEndDist * tanf(XM_PIDIV4 / 2);
		VertLength = HozLength / fAspectRatio;
	}

	// far plane verts
	Verts[4] = (Direction * FrustumEndDist) + (UpVector * VertLength) + (LeftVector * HozLength);
	Verts[5] = (Direction * FrustumEndDist) + (UpVector * VertLength) - (LeftVector * HozLength);
	Verts[6] = (Direction * FrustumEndDist) - (UpVector * VertLength) - (LeftVector * HozLength);
	Verts[7] = (Direction * FrustumEndDist) - (UpVector * VertLength) + (LeftVector * HozLength);

	vecPos.push_back(VertexPositionColor(Verts[0], XMFLOAT4(1, 0, 0, 1)));
	vecPos.push_back(VertexPositionColor(Verts[1], XMFLOAT4(1, 0, 0, 1)));
	vecPos.push_back(VertexPositionColor(Verts[2], XMFLOAT4(1, 0, 0, 1)));
	vecPos.push_back(VertexPositionColor(Verts[0], XMFLOAT4(1, 0, 0, 1)));
	vecPos.push_back(VertexPositionColor(Verts[2], XMFLOAT4(1, 0, 0, 1)));
	vecPos.push_back(VertexPositionColor(Verts[3], XMFLOAT4(1, 0, 0, 1)));

	

	vecPos.push_back(VertexPositionColor(Verts[4], XMFLOAT4(1, 0, 0, 1)));
	vecPos.push_back(VertexPositionColor(Verts[5], XMFLOAT4(1, 0, 0, 1)));
	vecPos.push_back(VertexPositionColor(Verts[6], XMFLOAT4(1, 0, 0, 1)));
	vecPos.push_back(VertexPositionColor(Verts[4], XMFLOAT4(1, 0, 0, 1)));
	vecPos.push_back(VertexPositionColor(Verts[6], XMFLOAT4(1, 0, 0, 1)));
	vecPos.push_back(VertexPositionColor(Verts[7], XMFLOAT4(1, 0, 0, 1)));


	vecPos.push_back(VertexPositionColor(Verts[0], XMFLOAT4(1, 0, 0, 1)));
	vecPos.push_back(VertexPositionColor(Verts[4], XMFLOAT4(1, 0, 0, 1)));
	vecPos.push_back(VertexPositionColor(Verts[5], XMFLOAT4(1, 0, 0, 1)));
	vecPos.push_back(VertexPositionColor(Verts[0], XMFLOAT4(1, 0, 0, 1)));
	vecPos.push_back(VertexPositionColor(Verts[5], XMFLOAT4(1, 0, 0, 1)));
	vecPos.push_back(VertexPositionColor(Verts[1], XMFLOAT4(1, 0, 0, 1)));

}
