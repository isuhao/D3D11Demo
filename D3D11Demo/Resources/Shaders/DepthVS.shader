DXBC®№¶п""?Uъртexѓ   аB     8   X  ћ     \  Ў  RDEF     L          ю€	  д   <                              MatrixBuffer ЂЂЂ<      d   ј           ђ       @      Є       »   @   @      Є       ”   А   @      Є       worldMatrix             viewMatrix projectionMatrix Microsoft (R) HLSL Shader Compiler 6.3.9600.16384 ЂЂISGNl         P                    \                    c                    SV_Position NORMAL TEXCOORD OSGNL         8                    D                    SV_POSITION TEXTURE SHDR4  @  Н   Y  FО         _  r     g  т         e  т     h     8  т      V     FО         2  
т           FО          F     2  
т      ¶     FО         F        т      F     FО         8  т     V     FО         2  
т           FО         F    2  
т     ¶
     FО         F    2  
т      ц     FО         F    8  т     V     FО      	   2  
т           FО         F    2  
т     ¶
     FО      
   F    2  
т      ц     FО         F    6  т      F     6  т     F     >  STATt                                                                                                                 SPDB >  Microsoft C/C++ MSF 7.00
DS            Ь                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  ј€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€8  а€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€       <       €€€€                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         Ф.1юАU   р£Ґчo≤BЬД3аЪЉ                          AС2                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
//////////////
struct VertexInputType
{

	float4 position : SV_Position;
	float3 normal : NORMAL;
	float2 tex : TEXCOORD;
};

struct PixelInputType
{
	float4 position : SV_POSITION;
	float4 depthPosition : TEXTURE0;
};


////////////////////////////////////////////////////////////////////////////////
// Vertex Shader
////////////////////////////////////////////////////////////////////////////////
PixelInputType ColorVertexShader(VertexInputType input)
{
	PixelInputType output;


	//ws  3M  /,  6$  Ї  L    ВF  р1  ‘(  є*  ≠Z  б/                                                                                                                                                                                                                                                                                                                                                                                                                                                                             ////////////////////////////////////////////////////////////////////////////////
// Filename: color.vs
////////////////////////////////////////////////////////////////////////////////


/////////////
// GLOBALS //
/////////////
cbuffer MatrixBuffer
{
	matrix worldMatrix;
	matrix viewMatrix;
	matrix projectionMatrix;
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
	float4 position : SV_POSITION;
	float4 depthPosition : TEXTURE0;
};


////////////////////////////////////////////////////////////////////////////////
// Vertex Shader
////////////////////////////////////////////////////////////////////////////////
PixelInputType ColorVertexShader(VertexInputType input)
{
	PixelInputType output;


	// Change the position vector to be 4 units for proper matrix calculations.
	input.position.w = 1.0f;

	// Calculate the position of the vertex against the world, view, and projection matrices.

	output.position = mul(input.position, worldMatrix);
	output.position = mul(output.position, viewMatrix);
	output.position = mul(output.position, projectionMatrix);

	// Store the position value in a second input value for depth value calculations.
	output.depthPosition = output.position;

	return output;
}                                                                                                                                            юпюп   ч   E:\LWM\WMDemo\WMDemo\VS2013_Proj\Bin\Debug\Shaders\DepthVS.hlsl  e:\lwm\wmdemo\wmdemo\vs2013_proj\bin\debug\shaders\depthvs.hlsl ////////////////////////////////////////////////////////////////////////////////
// Filename: color.vs
////////////////////////////////////////////////////////////////////////////////


/////////////
// GLOBALS //
/////////////
cbuffer MatrixBuffer
{
	matrix worldMatrix;
	matrix viewMatrix;
	matrix projectionMatrix;
};


//////////////
// TYPEDEFS //в0А   }ЇНс'®–                                                               B   (   в0≠÷st     A   B                                                                                                                                                                                                                                                                                                                                                                                                                  J <      @А%   @А%Microsoft (R) HLSL Shader Compiler 6.3.9600.16384 B =hlslFlags 0x9 hlslTarget vs_4_0 hlslEntry ColorVertexShader    :     p      м      м  	  H    †ColorVertexShader    . >  	 input                                  P     H    м     P    H    м    P    H    м    P    H    м    P    H    м    P    H    м    P    H    м    P    H    м     P     H    м$   F >  И <ColorVertexShader return value>                               P    H    м    P    H    м    P    H    м    P    H    м    P     H    м     P    H    м    P    H    м    P    H    м   . >   output                                 P      Ў    \     P     Ў    \    P     Ў    \    P     Ў    \     ф         if«.FRПЊа~Й(«`M  т   А        4         t  H   0  АH   0   h   0  Аh   0   Р   0  АР   0   Є   0  АЄ   0   Ў   1  АЎ   1   ш   1  Аш   1      1  А   1   H  1  АH  1   p  2  Аp  2   Р  2  АР  2   Є  2  АЄ  2   а  2  Аа  2     7  А  7     7  А  7   0  7  А0  7    4  3  4  3  4  3  4  3  4  3  4  3  4  3  4  3  :  9  :  9  :  9  :  9             ц                     @   `                                                                                                                                                                                                        18        d  
 €€   А      4   4      <        @       float4 утс @       float3 утс @       float2 утс:       position с    normal утс    tex тс&              $ VertexInputType тс
      .       position с     depthPosition &                PixelInputType утс
             @            @ float4x4 
 
    
                                                                                                          18              €€   А                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   Change the position vector to be 4 units for proper matrix calculations.
	input.position.w = 1.0f;

	// Calculate the position of the vertex against the world, view, and projection matrices.

	output.position = mul(input.position, worldMatrix);
	output.position = mul(output.position, viewMatrix);
	output.position = mul(output.position, projectionMatrix);

	// Store the position value in a second input value for depth value calculations.
	output.depthPosition = output.position;

	return output;
}    В   A                  B                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               D3DSHDR 4                             `                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        €€€€	/с            a      A      !                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                $                                                                                                                                                                                                                                                                                                                                                                                                                                                                %    Ф    ColorVertexShader  Q       €€€€€€worldMatrix  Q     @ €€€€€€viewMatrix  & Q     А €€€€€€projectionMatrix                                                                                                                                                                                                                                                                                                                                                                                                                       €€€€	/с                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            €€€€w	1     Л Ј√   X       ,   L                                    4     `             	 t      і      ИП         ColorVertexShader none  -Ї.с //    4     `  //                €€€€    4        €€€€    €€€€         E:\LWM\WMDemo\WMDemo\VS2013_Proj\Bin\Debug\Shaders\DepthVS.hlsl юпюп                  €€€€€€€€€€ €€€€€€€€€€                                                                                                                                                                 Ф.1юАU   р£Ґчo≤BЬД3аЪЉm   /LinkInfo /names /src/headerblock /src/files/e:\lwm\wmdemo\wmdemo\vs2013_proj\bin\debug\shaders\depthvs.hlsl          :             
             "          AС2                                                                                                                                                                                                                                                                                                                              …   Ь  _  8       '  А   t  <  <       (   D  ,   И                                    	   
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 