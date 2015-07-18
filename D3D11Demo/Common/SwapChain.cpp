#include "SwapChain.h"
#include "DeviceManager.h"
SwapChain::SwapChain()
{
	m_depthStencilBuffer = NULL;
	m_renderTargetView = NULL;
	m_depthStencilView = NULL;
	m_pd3dDevice = DeviceManager::GetInstance().GetDevice();
	m_pDXGIFactory = DeviceManager::GetInstance().GetDXGIFactory();

	m_bkgColor[0] = 0.58f;
	m_bkgColor[1] = 0.58f;
	m_bkgColor[2] = 0.58f;
	m_bkgColor[3] = 1.f;

	m_bkgColor[0] = 0.1921568627450980392156862745098f;
	m_bkgColor[1] = 0.30196078431372549019607843137255f;
	m_bkgColor[2] = 0.47450980392156862745098039215686f;
	m_bkgColor[3] = 1.0f;
/*

	m_bkgColor[0] = 0.0f;
	m_bkgColor[1] = 0.0f;
	m_bkgColor[2] = 0.0f;
	m_bkgColor[3] = 0.0f;*/

	m_bInit = false;
	texEx = NULL;
	mSRV = NULL;
	m_nWidth = 0;
	m_nHeight = 0;
}

SwapChain::~SwapChain()
{
	SAFE_RELEASE(m_pSwapChain);
	SAFE_RELEASE(mSRV);
	SAFE_RELEASE(texEx);
	SAFE_RELEASE(m_depthStencilBuffer);
	SAFE_RELEASE(m_renderTargetView);
	SAFE_RELEASE(m_depthStencilView);

}

HRESULT SwapChain::Initialize(HWND hwnd, int nWidth, int nHeigth)
{
	m_hWnd = hwnd;
	m_nWidth = nWidth;
	m_nHeight = nHeigth;
	HRESULT hr;
	std::cout << "��: " << m_nWidth << "   " << "��: " << m_nHeight << std::endl;

	DXGI_SWAP_CHAIN_DESC scDesc = { 0 };////���ṹ�����ý������൱����  
	scDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;//���������ݸ�ʽ  
	scDesc.BufferDesc.Width = m_nWidth;  //��������С 
	scDesc.BufferDesc.Height = m_nHeight;
	scDesc.BufferDesc.RefreshRate.Numerator = 60; //ˢ���ʣ�һ�������趨���� 
	scDesc.BufferDesc.RefreshRate.Denominator = 1;
	scDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED; //�̶����� 
	scDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED; //�̶�����
	scDesc.BufferCount = 1; //����������  
	scDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT ; //UsageΪRender Target Output  
	scDesc.Flags = 0;
	scDesc.OutputWindow = m_hWnd; //�����ھ��  
	scDesc.SampleDesc.Count = 1; //������  
	scDesc.SampleDesc.Quality = 0; //����֧�ֵȼ�
	scDesc.SwapEffect = DXGI_SWAP_EFFECT_SEQUENTIAL; //���ò��� 
	scDesc.Windowed = true;//����ģʽ 

	hr = m_pDXGIFactory->CreateSwapChain(m_pd3dDevice, &scDesc, &m_pSwapChain);
	if (!CreateWindowSizeDependentResources())
	{
		hr = S_FALSE;
	}
	m_bInit = true;

	return hr;
}

bool SwapChain::CreateWindowSizeDependentResources()
{
	SAFE_RELEASE(m_depthStencilBuffer);
	SAFE_RELEASE(m_renderTargetView);
	SAFE_RELEASE(m_depthStencilView);
	SAFE_RELEASE(texEx);
	SAFE_RELEASE(mSRV);
	HRESULT hr;
	m_pSwapChain->ResizeBuffers(1, m_nWidth, m_nHeight, DXGI_FORMAT_R8G8B8A8_UNORM, 0);

	//	3. ����RenderTargetView,D3D11�д�����ͼ��Ҫ��Ӧ����Դ
	ID3D11Texture2D *backBuffer(NULL);
	//��ȡ�󻺳�����ַ
	m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&backBuffer));
	D3D11_TEXTURE2D_DESC pDesc;
	backBuffer->GetDesc(&pDesc);
	//������ͼ
	hr = m_pd3dDevice->CreateRenderTargetView(backBuffer, 0, &m_renderTargetView);
	if (FAILED(hr))return false;



	/************************************************************************/
	/*        4. ������ȡ�ģ�建��������Ӧ��ͼ,����������Ҫ������һ��2ά����                                                             */
	/************************************************************************/
	D3D11_TEXTURE2D_DESC dsDesc;
	dsDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	dsDesc.Width = m_nWidth;
	dsDesc.Height = m_nHeight;
	dsDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	dsDesc.MipLevels = 1;
	dsDesc.ArraySize = 1;
	dsDesc.CPUAccessFlags = 0;
	dsDesc.SampleDesc.Count = 1;
	dsDesc.SampleDesc.Quality = 0;
	dsDesc.MiscFlags = 0;
	dsDesc.Usage = D3D11_USAGE_DEFAULT;

	int w = m_nWidth;
	int h = m_nHeight;

	hr = m_pd3dDevice->CreateTexture2D(&dsDesc, nullptr, &m_depthStencilBuffer);

	//������ͼ����DepthStencilView
	// Not needed since this is a 2d texture
	hr = m_pd3dDevice->CreateDepthStencilView(m_depthStencilBuffer, 0, &m_depthStencilView);

	//������������ͼ��Ȼ��Ҫ�󶨵���Ⱦ����
//	m_deviceContext->OMSetRenderTargets(1, &m_renderTargetView, m_depthStencilView);
	m_viewport.TopLeftX = 0.0f;
	m_viewport.TopLeftY = 0.0f;
	m_viewport.Width = (float)(m_nWidth);
	m_viewport.Height = (float)(m_nHeight);
	m_viewport.MinDepth = 0.0f;
	m_viewport.MaxDepth = 1.0f;
//
	//
	D3D11_TEXTURE2D_DESC desc;
	desc.Width = static_cast<UINT>(m_nWidth);
	desc.Height = static_cast<UINT>(m_nHeight);
	desc.MipLevels = static_cast<UINT>(1);
	desc.ArraySize = static_cast<UINT>(1);
	desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	desc.SampleDesc.Count = 1;
	desc.SampleDesc.Quality = 0;
	desc.Usage = D3D11_USAGE_DEFAULT;
	desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;;
	desc.CPUAccessFlags = 0;
	desc.MiscFlags = 0;

	hr = m_pd3dDevice->CreateTexture2D(&desc, NULL, &texEx);
	D3D11_SHADER_RESOURCE_VIEW_DESC SRVDesc;
	memset(&SRVDesc, 0, sizeof(SRVDesc));
	SRVDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	SRVDesc.ViewDimension = D3D_SRV_DIMENSION_TEXTURE2D;
	SRVDesc.Texture2D.MostDetailedMip = 0;
	SRVDesc.Texture2D.MipLevels = 1;
	hr = m_pd3dDevice->CreateShaderResourceView(texEx, &SRVDesc, &mSRV);

	//�ͷź󻺳�������  
	backBuffer->Release();
	return true;
}

ID3D11ShaderResourceView* SwapChain::GetResourceView()
{
	ID3D11Texture2D *backBuffer(NULL);
	//��ȡ�󻺳�����ַ
	m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&backBuffer));
	g_objDeviecManager.GetImmediateContext()->CopyResource(texEx, backBuffer);
	return mSRV;
}

void SwapChain::BeginClipRect(RECT& clipRC)
{
	ID3D11DeviceContext*  d3dcontext = g_objDeviecManager.GetImmediateContext();
	D3D11_RECT rects[1];
	rects[0].left = clipRC.left;
	rects[0].right = clipRC.right;
	rects[0].top = clipRC.top;
	rects[0].bottom = clipRC.bottom;
	d3dcontext->RSSetScissorRects(1, rects);
}


void SwapChain::Begin()
{
	ID3D11DeviceContext*  d3dcontext = g_objDeviecManager.GetImmediateContext();
	d3dcontext->OMSetRenderTargets(1, &m_renderTargetView, m_depthStencilView);
	d3dcontext->RSSetViewports(1, &m_viewport);
	d3dcontext->RSSetState(NULL);
	d3dcontext->OMSetDepthStencilState(NULL, 0);
	d3dcontext->OMSetBlendState(NULL, NULL, 0xFFFFFFFF);
	d3dcontext->ClearDepthStencilView(m_depthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);
	d3dcontext->ClearRenderTargetView(m_renderTargetView, this->GetBkgColor());
}

void SwapChain::SetBackBufferRenderTarget()
{
	ID3D11DeviceContext*  d3dcontext = g_objDeviecManager.GetImmediateContext();
	d3dcontext->OMSetRenderTargets(1, &m_renderTargetView, m_depthStencilView);
	d3dcontext->RSSetViewports(1, &m_viewport);
}

void SwapChain::Clear()
{
	ID3D11DeviceContext*  d3dcontext = g_objDeviecManager.GetImmediateContext();

	d3dcontext->ClearDepthStencilView(m_depthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);
	d3dcontext->ClearRenderTargetView(m_renderTargetView, this->GetBkgColor());
}

void SwapChain::Flip()
{
	if (this->GetDXGISwapChain()->Present(0, 0) == S_OK)
	{

	}
}

void SwapChain::OnResize(int nWidth, int nHeight)
{
	m_nWidth = nWidth;
	m_nHeight = nHeight;
	CreateWindowSizeDependentResources();
}
