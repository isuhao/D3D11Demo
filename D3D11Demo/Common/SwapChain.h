#pragma once
#include "HpD3D9Type.h"

class  SwapChain
{
public:
	SwapChain();
	virtual HRESULT Initialize(HWND hwnd, int nWidth, int nHeigth);
	~SwapChain();
	ID3D11RenderTargetView* GetRenderTargetView() { return m_renderTargetView; }
	ID3D11DepthStencilView* GetDepthStencilView() { return m_depthStencilView; }
	IDXGISwapChain* GetDXGISwapChain(){ return m_pSwapChain; }
	ID3D11ShaderResourceView* GetResourceView();

	D3D11_VIEWPORT GetViewPort(){ return m_viewport; }

	void OnResize(int nWidth, int nHeight);
	void BeginClipRect(RECT& clipRC);
	void EndClipRect();
	void TurnZBufferOn();
	void TurnZBufferOff();
	bool GetState(){ return m_bInit; }
	void  SetBkgColor(const FLOAT ColorRGBA[4])
	{ 
		m_bkgColor[0] = ColorRGBA[0];
		m_bkgColor[1] = ColorRGBA[1];
		m_bkgColor[2] = ColorRGBA[2];
	}
	const float* GetBkgColor()
	{ 
		return m_bkgColor; 
	}
	void Begin();
	void SetBackBufferRenderTarget();
	void Clear();
	void Flip();

private:
	virtual bool CreateWindowSizeDependentResources();
	HWND		m_hWnd;				//���ھ��
	IDXGIFactory*          m_pDXGIFactory;
	ID3D11Device*           m_pd3dDevice;

	// render target
	IDXGISwapChain*         m_pSwapChain;

	ID3D11ShaderResourceView* mSRV; //��̨���ݵ�������ͼ
	ID3D11Texture2D*  texEx; //�Ѻ�̨���������ݿ��������������ظ��ⲿʹ��
	

	ID3D11Texture2D			*m_depthStencilBuffer;		//���/ģ�建����
	ID3D11RenderTargetView	*m_renderTargetView;		//��Ⱦ������ͼ
	ID3D11DepthStencilView	*m_depthStencilView;		//���/ģ����ͼ
	D3D11_VIEWPORT m_viewport;
	float m_bkgColor[4];
	bool m_bInit;
	int					m_nWidth;
	int					m_nHeight;
};

