DXBCЂПJиE^@ј‘&H7Ґрм   h8     8   м   D  x  д  `  RDEFђ                  €€	  x   \                            j            €€€€          colorSampler_ shaderTexture Microsoft (R) HLSL Shader Compiler 6.3.9600.16384 ЂЂISGNP         8                    D                   SV_POSITION TEXCOORD ЂЂЂOSGN,                               SV_TARGET ЂЂSHDRd   @      Z   `     X  p     UU  b 2    e  т      E  	т      F    F~      `     >  STATt                                                                                                                   SPDB 6  Microsoft C/C++ MSF 7.00
DS            Р                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  ј€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€8  ь€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€       <       €€€€                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         Ф.1ИwmU   /-  ®X}LА√R/ЫRЃ                          AС2                                                                                                                                                                                                                                                                                                                                                                                                                                                                    = Wrap;
	AddressV = Wrap;
};

//////////////
// TYPEDEFS //
//////////////
struct PixelInputType
{
    float4 position : SV_POSITION;
  float2 tex : TEXCOORD;
};


////////////////////////////////////////////////////////////////////////////////
// Pixel Shader
////////////////////////////////////////////////////////////////////////////////
float4 ColorPixelShader(PixelInputType input) : SV_TARGET
{
	float4 textureColor = float4(0,0,0,0);
		// Sample the pixel color from the texture usingws  /,  ў]  ВF  “A  Кn  ≠"  тF  р1  ,  Mu  ≠Z  б/                                                                                                                                                                                                                                                                                                                                                                                                                                                                             ////////////////////////////////////////////////////////////////////////////////
// Filename: color.ps
////////////////////////////////////////////////////////////////////////////////

Texture2D shaderTexture : register(t0);
SamplerState colorSampler_ : register(s0);
SamplerState samLinear
{
	Filter = MIN_MAG_MIP_LINEAR;
	AddressU = Wrap;
	AddressV = Wrap;
};

//////////////
// TYPEDEFS //
//////////////
struct PixelInputType
{
    float4 position : SV_POSITION;
  float2 tex : TEXCOORD;
};


////////////////////////////////////////////////////////////////////////////////
// Pixel Shader
////////////////////////////////////////////////////////////////////////////////
float4 ColorPixelShader(PixelInputType input) : SV_TARGET
{
	float4 textureColor = float4(0,0,0,0);
		// Sample the pixel color from the texture using the sampler at this texture coordinate location.
	textureColor = shaderTexture.Sample(colorSampler_, input.tex);
    return textureColor;
}
                         юпюп   Ж   D:\VS2013Proj\DXEngine(UE)\DXEngine\VS2013_Proj\Bin\Debug\Shaders\SkinPS.hlsl  d:\vs2013proj\dxengine(ue)\dxengine\vs2013_proj\bin\debug\shaders\skinps.hlsl ////////////////////////////////////////////////////////////////////////////////
// Filename: color.ps
////////////////////////////////////////////////////////////////////////////////

Texture2D shaderTexture : register(t0);
SamplerState colorSampler_ : register(s0);
SamplerState samLinear
{
	Filter = MIN_MAG_MIP_LINEAR;
	AddressU в0А   ж…©Э–                                                               P   (   в0нСсKз     O   P                                                                                                                                                                                                                                                                                                                                                                                                                  J <      @А%   @А%Microsoft (R) HLSL Shader Compiler 6.3.9600.16384 B =hlslFlags 0x9 hlslTarget ps_4_0 hlslEntry ColorPixelShader     6     4      (       (     <    †ColorPixelShader . >  	 input                                  P     <    (      P    <    (     P    <    (     P    <    (     P    <    (     P    <    (    F >  И <ColorPixelShader return value>                                P     <    (      P    <    (     P    <    (     P    <    (      ф         WЯIV_?я_Eњ ъ?<  т   H         d          <   <     А<      `      А`        ?  >     ц                     D                                                                                                                                                                                                                                                                                                                                18        ш   
 €€   А      4   4      <        @       float4 утс @       float2 утс&       position с    tex тс&               PixelInputType утс
      
                 †   тс
     
          
    тс
 
    
                                                                                                                                                                                                                      18              €€   А                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   the sampler at this texture coordinate location.
	textureColor = shaderTexture.Sample(colorSampler_, input.tex);
    return textureColor;
}
    Ю   O           P                                                                                                                                                                                                                                                                                                                                                       D3DSHDR d                              `                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        €€€€	/с     !            E                                                                                                                                                                                                                                                                                                                                                                                                                                               @                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            %    Ф    ColorPixelShader  " Q	   €€€€  €€€€shaderTexture   " Q   €€€€€€  €€colorSampler_                                                                                                                                                                                                                                                                                                                                                                                                                                                      €€€€	/с                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            €€€€w	1     Л Ј√   X       ,   \                                    d      `             	 8      |      0ИU         ColorPixelShader none   -Ї.с       d      `                    €€€€    d         €€€€    €€€€         D:\VS2013Proj\DXEngine(UE)\DXEngine\VS2013_Proj\Bin\Debug\Shaders\SkinPS.hlsl   юпюп                  €€€€€€€€€€ €€€€€€€€€€                                                                                                                                                 Ф.1ИwmU   /-  ®X}LА√R/ЫRЃ{   /LinkInfo /names /src/headerblock /src/files/d:\vs2013proj\dxengine(ue)\dxengine\vs2013_proj\bin\debug\shaders\skinps.hlsl                 "            
                 AС2                                                                                                                                                                                                                                                                                                                „   0  o  8       ґ  А   з  ƒ  <       (   8  ,   h                  
               	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          