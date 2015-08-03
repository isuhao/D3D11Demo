/////////////
// GLOBALS //
/////////////
cbuffer  MatrixBuffer: register(b0)
{
	matrix worldMatrix;
	matrix viewMatrix;
	matrix projectionMatrix;
};

//�������һ���µĳ��������������Ʒ������

cbuffer ReflectionBuffer
{
	matrix reflectionMatrix;
};

//////////////
// TYPEDEFS //
//////////////
struct VertexInputType
{
	float4 position : SV_Position;
	float3 normal : NORMAL;
	float2 tex : TEXCOORD;
};
struct PixelInputType
{
	float4 position : SV_Position;
	float2 tex : TEXCOORD;
	float4 reflectionPosition : TEXCOORD1;
};


////////////////////////////////////////////////////////////////////////////////
// Vertex Shader
////////////////////////////////////////////////////////////////////////////////
PixelInputType main(VertexInputType input)
{
	PixelInputType output;
	matrix reflectProjectWorld;

	input.position.w = 1.0f;
	// Calculate the position of the vertex against the world, view, and projection matrices.
	output.position = mul(input.position, worldMatrix);
	output.position = mul(output.position, viewMatrix);
	output.position = mul(output.position, projectionMatrix);
	// Store the texture coordinates for the pixel shader.
	output.tex = input.tex;
	//��һ���ı䶥����ɫ�������Ǵ���һ�����������λ��ֵת����ͶӰ�����λ�á� �������ӳ����Ͼ���ͶӰ����,��������硣
	reflectProjectWorld = mul(reflectionMatrix, projectionMatrix);
	reflectProjectWorld = mul(worldMatrix, reflectProjectWorld);

	//���ڽ������λ��ת��ΪͶӰ�����λ�á� ��ʹ����Щת��λ�������������ɫ����õ�ͼͶӰ����ṹ��

		// Calculate the input position against the reflectProjectWorld matrix.
	output.reflectionPosition = mul(input.position, reflectProjectWorld);
	return output;
}