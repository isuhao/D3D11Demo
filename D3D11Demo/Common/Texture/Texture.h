#ifndef _TEXTURE_H_
#define _TEXTURE_H_
#include <string>
#include "../HpD3D9Type.h"

class TextureMgr;
// Class that wraps information about a texture. This class 
// won't be used directly by the users. Instead, they will
// manipulate the CImage class.
class   CTexture
{
	friend class TextureMgr;
public:
	ID3D11ShaderResourceView* GetShaderResourceView(){ return m_pTexture; }
	void Show(int x, int y);
	void ShowEx(int x1, int y1, int x2, int y2);

	//x,y: ͼ��Ҫ��ʾ�����Ͻ�λ�� 
	//pSrc: Ҫ��ʾ��ͼ�����Դ��������,����ΪNULL��ʾ��ʾ����ͼ��. �Ե�C3_RECT��left/right�����������ҵߵ���ʾͼ�� 
	//	�Ե�RECT��top / bottom�����������µߵ���ʾͼ��
	//nWidth, nHeight: ͼ��Ҫ��ʾ����Ļ��Ŀ����δ�С.
	//��Ϊ0,��ʾ��ͼ���ԭʼ��Դ�ߴ���ʾ 
	//��dwWidth, dwHeight������ָ��ͼ���ԭʼ�ߴ��С, ͼ����Զ�����������ʾ.
	//////////////////////////////////////////////////////////////////////////
	void ShowEx(int x, int y, RECT* pSrc = NULL, int nWidth = 0, int nHeight = 0,bool bRotate = false);

	int  GetWidth(){ return m_nWidth; }
	int  GetHegith(){ return m_nHeight; }
	void Save();
protected:
	// Constructor which takes the filename as argument.
	// It loads the file and throw an exception if the load
	// failed.
	CTexture(ID3D11ShaderResourceView* pShaderResource,int nWidth,int nHeight);
	~CTexture();
private:
	ID3D11ShaderResourceView* m_pTexture;                                //����ָ��
	ID3D11Device			*m_d3dDevice;				//D3D11�豸
	ID3D11DeviceContext		*m_deviceContext;			//�豸������
	int m_nWidth;
	int m_nHeight;
};

#endif  // _TEXTURE_H_