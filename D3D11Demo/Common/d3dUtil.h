#pragma once
#include "HpD3D9Type.h"


HRESULT   D3DCompileShader(LPCSTR pFileName, LPCSTR pEntrypoint,
	LPCSTR pTarget, ID3DBlob** ppCode);
//��ȡ����2D�ľ���
XMMATRIX GetShow2DMatrix(int nWidth, int nHegith);