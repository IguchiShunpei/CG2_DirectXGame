#include "Basic.hlsli"

VSOutput main(float4 pos : POSITION,float3 normal :NORMAL, float2 uv : TEXCOORD)
{
	VSOutput output;//ピクセルシェーダーに渡す値
	output.svpos = mul(mat, pos); //座標に行列を乗算
	output.uv = uv;

	//受け取った法線の数値をそのまま出力する処理
	output.normal = normal;

	return output;
}
