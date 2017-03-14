#include "stdafx.h"
#include "Inc\DirectXMath.h"

#include <random>

#include "MatrixMultiply_Ref.h"
#include "MatrixMultiply_V0.h"
#include "MatrixMultiply_V1.h"
#include "MatrixMultiply_V2.h"
#include "Utils.h"

using namespace DirectX;

// We always test the following cases:
//		ref_reg: reference with FXMMATRIX as first argument
//		ref_mem: reference with CXMMATRIX as first argument if applicable
//		ref_inl: reference force inline
//		opt_reg: opt impl with FXMMATRIX as first argument
//		opt_mem: opt impl with CXMMATRIX as first argument
//		opt_inl: opt impl force inline

static std::uniform_real_distribution<float> random_distribution(-1.0, 1.0);
static __int32 random_seed = 304;

XMMATRIX GenerateRandomMatrix(std::default_random_engine& re)
{
	const float pitch = random_distribution(re) * 90.0f;
	const float yaw = random_distribution(re) * 90.0f;
	const float roll = random_distribution(re) * 90.0f;

	const float pos_x = random_distribution(re) * 200.0f;
	const float pos_y = random_distribution(re) * 200.0f;
	const float pos_z = random_distribution(re) * 200.0f;

	XMVECTOR quat = XMQuaternionRotationRollPitchYaw(DegToRad(pitch), DegToRad(yaw), DegToRad(roll));
	XMVECTOR pos = XMVectorSet(pos_x, pos_y, pos_z, 1.0f);

	XMMATRIX result;
	result = XMMatrixRotationQuaternion(quat);
	result.r[3] = pos;
	return result;
}

void ValidateImplementations()
{
	const XMVECTOR quat0 = XMQuaternionRotationRollPitchYaw(DegToRad(32.0f), DegToRad(78.0f), DegToRad(13.0f));
	const XMVECTOR quat1 = XMQuaternionRotationRollPitchYaw(DegToRad(87.0f), DegToRad(23.0f), DegToRad(43.0f));

	const XMVECTOR pos0 = XMVectorSet(293.0f, 581.0f, 0.004f, 1.0f);
	const XMVECTOR pos1 = XMVectorSet(526.0f, 1135, 0.1234f, 1.0f);

	XMMATRIX mtx0 = XMMatrixRotationQuaternion(quat0);
	mtx0.r[3] = pos0;

	XMMATRIX mtx1 = XMMatrixRotationQuaternion(quat1);
	mtx0.r[3] = pos1;

	const XMMATRIX ref_mtx = XMMatrixMultiply(mtx0, mtx1);
	XMMATRIX tmp_mtx;

	EnsureMatrixEqual(ref_mtx, XMMatrixMultiply_Ref_Reg(mtx0, mtx1));
	XMMatrixMultiply_Ref_Reg2(mtx0, mtx1, tmp_mtx); EnsureMatrixEqual(ref_mtx, tmp_mtx);
	EnsureMatrixEqual(ref_mtx, XMMatrixMultiply_Ref_RegFlip(mtx0, mtx1));
	XMMatrixMultiply_Ref_RegFlip2(mtx0, mtx1, tmp_mtx); EnsureMatrixEqual(ref_mtx, tmp_mtx);
	EnsureMatrixEqual(ref_mtx, XMMatrixMultiply_Ref_RegExp(mtx0, mtx1));
	XMMatrixMultiply_Ref_RegExp2(mtx0, mtx1, tmp_mtx); EnsureMatrixEqual(ref_mtx, tmp_mtx);
	EnsureMatrixEqual(ref_mtx, XMMatrixMultiply_Ref_Mem(mtx0, mtx1));
	XMMatrixMultiply_Ref_Mem2(mtx0, mtx1, tmp_mtx); EnsureMatrixEqual(ref_mtx, tmp_mtx);
	EnsureMatrixEqual(ref_mtx, XMMatrixMultiply_Ref_Inl(mtx0, mtx1));
	XMMatrixMultiply_Ref_Inl2(mtx0, mtx1, tmp_mtx); EnsureMatrixEqual(ref_mtx, tmp_mtx);
	EnsureMatrixEqual(ref_mtx, XMMatrixMultiply_Ref_InlExp(mtx0, mtx1));
	XMMatrixMultiply_Ref_InlExp2(mtx0, mtx1, tmp_mtx); EnsureMatrixEqual(ref_mtx, tmp_mtx);

	EnsureMatrixEqual(ref_mtx, XMMatrixMultiply_V0_Reg(mtx0, mtx1));
	XMMatrixMultiply_V0_Reg2(mtx0, mtx1, tmp_mtx); EnsureMatrixEqual(ref_mtx, tmp_mtx);
	EnsureMatrixEqual(ref_mtx, XMMatrixMultiply_V0_RegFlip(mtx0, mtx1));
	XMMatrixMultiply_V0_RegFlip2(mtx0, mtx1, tmp_mtx); EnsureMatrixEqual(ref_mtx, tmp_mtx);
	EnsureMatrixEqual(ref_mtx, XMMatrixMultiply_V0_RegExp(mtx0, mtx1));
	XMMatrixMultiply_V0_RegExp2(mtx0, mtx1, tmp_mtx); EnsureMatrixEqual(ref_mtx, tmp_mtx);
	EnsureMatrixEqual(ref_mtx, XMMatrixMultiply_V0_Mem(mtx0, mtx1));
	XMMatrixMultiply_V0_Mem2(mtx0, mtx1, tmp_mtx); EnsureMatrixEqual(ref_mtx, tmp_mtx);
	EnsureMatrixEqual(ref_mtx, XMMatrixMultiply_V0_Inl(mtx0, mtx1));
	XMMatrixMultiply_V0_Inl2(mtx0, mtx1, tmp_mtx); EnsureMatrixEqual(ref_mtx, tmp_mtx);
	EnsureMatrixEqual(ref_mtx, XMMatrixMultiply_V0_InlExp(mtx0, mtx1));
	XMMatrixMultiply_V0_InlExp2(mtx0, mtx1, tmp_mtx); EnsureMatrixEqual(ref_mtx, tmp_mtx);

	EnsureMatrixEqual(ref_mtx, XMMatrixMultiply_V1_Reg(mtx0, mtx1));
	XMMatrixMultiply_V1_Reg2(mtx0, mtx1, tmp_mtx); EnsureMatrixEqual(ref_mtx, tmp_mtx);
	EnsureMatrixEqual(ref_mtx, XMMatrixMultiply_V1_RegFlip(mtx0, mtx1));
	XMMatrixMultiply_V1_RegFlip2(mtx0, mtx1, tmp_mtx); EnsureMatrixEqual(ref_mtx, tmp_mtx);
	EnsureMatrixEqual(ref_mtx, XMMatrixMultiply_V1_RegExp(mtx0, mtx1));
	XMMatrixMultiply_V1_RegExp2(mtx0, mtx1, tmp_mtx); EnsureMatrixEqual(ref_mtx, tmp_mtx);
	EnsureMatrixEqual(ref_mtx, XMMatrixMultiply_V1_Mem(mtx0, mtx1));
	XMMatrixMultiply_V1_Mem2(mtx0, mtx1, tmp_mtx); EnsureMatrixEqual(ref_mtx, tmp_mtx);
	EnsureMatrixEqual(ref_mtx, XMMatrixMultiply_V1_Inl(mtx0, mtx1));
	XMMatrixMultiply_V1_Inl2(mtx0, mtx1, tmp_mtx); EnsureMatrixEqual(ref_mtx, tmp_mtx);
	EnsureMatrixEqual(ref_mtx, XMMatrixMultiply_V1_InlExp(mtx0, mtx1));
	XMMatrixMultiply_V1_InlExp2(mtx0, mtx1, tmp_mtx); EnsureMatrixEqual(ref_mtx, tmp_mtx);

	EnsureMatrixEqual(ref_mtx, XMMatrixMultiply_V2_Reg(mtx0, mtx1));
	XMMatrixMultiply_V2_Reg2(mtx0, mtx1, tmp_mtx); EnsureMatrixEqual(ref_mtx, tmp_mtx);
	EnsureMatrixEqual(ref_mtx, XMMatrixMultiply_V2_RegFlip(mtx0, mtx1));
	XMMatrixMultiply_V2_RegFlip2(mtx0, mtx1, tmp_mtx); EnsureMatrixEqual(ref_mtx, tmp_mtx);
	EnsureMatrixEqual(ref_mtx, XMMatrixMultiply_V2_RegExp(mtx0, mtx1));
	XMMatrixMultiply_V2_RegExp2(mtx0, mtx1, tmp_mtx); EnsureMatrixEqual(ref_mtx, tmp_mtx);
	EnsureMatrixEqual(ref_mtx, XMMatrixMultiply_V2_Mem(mtx0, mtx1));
	XMMatrixMultiply_V2_Mem2(mtx0, mtx1, tmp_mtx); EnsureMatrixEqual(ref_mtx, tmp_mtx);
	EnsureMatrixEqual(ref_mtx, XMMatrixMultiply_V2_Inl(mtx0, mtx1));
	XMMatrixMultiply_V2_Inl2(mtx0, mtx1, tmp_mtx); EnsureMatrixEqual(ref_mtx, tmp_mtx);
	EnsureMatrixEqual(ref_mtx, XMMatrixMultiply_V2_InlExp(mtx0, mtx1));
	XMMatrixMultiply_V2_InlExp2(mtx0, mtx1, tmp_mtx); EnsureMatrixEqual(ref_mtx, tmp_mtx);
}

extern void TestCase1(const __int32 random_seed, const __int32 num_samples, const __int32 num_iterations);
extern void TestCase2(const __int32 random_seed, const __int32 num_samples, const __int32 num_iterations);
extern void TestCase3(const __int32 random_seed, const __int32 num_samples, const __int32 num_iterations);

void ProfileMatrixMultiply()
{
	ValidateImplementations();

	const __int32 num_samples = 200;
	//const __int32 num_samples = 1;
	const __int32 num_iterations = 1000000;
	//const __int32 num_iterations = 1000;

	TestCase1(random_seed, num_samples, num_iterations);
	TestCase2(random_seed, num_samples, num_iterations);
	TestCase3(random_seed, num_samples, num_iterations);
}
