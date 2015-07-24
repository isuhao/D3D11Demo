#pragma once

#include "HpD3D9Type.h"


template< class D3D11ShaderType >
struct D3D11Shader
{
	D3D11ShaderType*  m_pShader;
	ID3D11ShaderReflection*  pReflector;
	int GetConstantIndex(const char* pszName);
	std::vector<ID3D11Buffer*> vecConstantBuffer;
};

template< class D3D11ShaderType >
int D3D11Shader<D3D11ShaderType>::GetConstantIndex(const char* pszName)
{
	D3D11_SHADER_DESC shaderDesc;
	if (pReflector)
	{
		pReflector->GetDesc(&shaderDesc);
		for (uint i = 0; i < shaderDesc.ConstantBuffers; ++i)
		{
			ID3D11ShaderReflectionConstantBuffer* pConstantBuffer = pReflector->GetConstantBufferByIndex(i);
			D3D11_SHADER_BUFFER_DESC shaderBufferDesc;
			pConstantBuffer->GetDesc(&shaderBufferDesc);
			for (uint j = 0; j < shaderBufferDesc.Variables; ++j)
			{
				ID3D11ShaderReflectionVariable* pVariable = pConstantBuffer->GetVariableByIndex(j);
				if (pVariable)
				{
					D3D11_SHADER_VARIABLE_DESC variableDesc;
					memset(&variableDesc, 0, sizeof(D3D11_SHADER_VARIABLE_DESC));
					pVariable->GetDesc(&variableDesc);
					if (strcmp(variableDesc.Name,pszName) == 0)
					{
						return i;
					}
					
				}
			}
		}
	}
	return 0;
}