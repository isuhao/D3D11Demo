/////////////
// GLOBALS //
/////////////
Texture2D shaderTexture;
SamplerState SampleType;

//�������һ���µ����������ӳ������Ⱦ�ĳ�����
Texture2D reflectionTexture;

//////////////
// TYPEDEFS //
//////////////
struct PixelInputType
{
	float4 position : SV_Position;
	float2 tex : TEXCOORD;
	float4 reflectionPosition : TEXCOORD1;
};

////////////////////////////////////////////////////////////////////////////////
// Pixel Shader
////////////////////////////////////////////////////////////////////////////////
float4 main(PixelInputType input) : SV_TARGET
{
	float4 textureColor;
	float2 reflectTexCoord;
	float4 reflectionColor;
	float4 color;


	// Sample the texture pixel at this location.
	textureColor = shaderTexture.Sample(SampleType, input.tex);
	//���뷴��ͬ������λ����Ҫת��Ϊ�ʵ����������ꡣ ���������ȳ���WЭ���� ����������tu�͵�������1 + 1��Χ, �޸���ӳ�䵽һ��0�� + 1����2, ���0.5��Χ��
	// Calculate the projected reflection texture coordinates.
	reflectTexCoord.x = input.reflectionPosition.x / input.reflectionPosition.w / 2.0f + 0.5f;
	reflectTexCoord.y = -input.reflectionPosition.y / input.reflectionPosition.w / 2.0f + 0.5f;


	// Sample the texture pixel from the reflection texture using the projected texture coordinates.
	reflectionColor = reflectionTexture.Sample(SampleType, reflectTexCoord);

	//������ǽ�Ϸ�ӳ���������ӵذ��ϴ�����Ӱ�췴ӳ��ά���ݼ��ڵذ��ϡ� ��������ʹ��һ�����Բ�ֵ��������֮���0.15���� ����Ըı���һ����ͬ�Ļ�Ϸ��̻�ı��������, ��ͬ�Ļ��ǿ��Ч����
	// Do a linear interpolation between the two textures for a blend effect.
	color = lerp(textureColor, reflectionColor, 0.15f);

	return color;
}