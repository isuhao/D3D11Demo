#pragma once
#include "D3D11App.h"
#include "HpD3D9Type.h"
#include "VertexTypes.h"

class SpecularLight : public D3D11App
{
public:
	SpecularLight(HINSTANCE hInstance, int nWidth = 1024, int nHeight = 600);
	~SpecularLight();
	virtual void UpdateScene(float dt);
	virtual void DrawScene();
protected:
	virtual void InitResource();

	std::shared_ptr<class D3D11RendererMesh> m_MeshModel;
	std::shared_ptr<class D3D11RendererMaterial> m_Material;
	ID3D11ShaderResourceView* srv;
};

