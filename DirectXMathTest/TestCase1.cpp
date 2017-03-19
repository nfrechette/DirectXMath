#include "stdafx.h"
#include "Inc\DirectXMath.h"

#include <iostream>
#include <conio.h>

#include "MatrixMultiply_Ref.h"
#include "MatrixMultiply_V0.h"
#include "MatrixMultiply_V1.h"
#include "MatrixMultiply_V2.h"
#include "MatrixMultiply_V3.h"
#include "MatrixMultiply_V4.h"
#include "Utils.h"

#define SANITY_CHECK_RESULTS	0

using namespace DirectX;

// Test case 1
// A single matrix is applied to multiple matrices
// The applied matrix should fit in a register, the second matrix is always loaded from memory
// In practice, the registers used for the input are also used for output, meaning that
// the const transform applied is always reloaded from memory anyway. In practice, it could be stored in some extra
// registers and moved but the compiler generally opts not to do so, at least with VS2015

void TestCase1_Setup(const __int32 random_seed, XMMATRIX matrices[64], XMMATRIX& transform)
{
	std::random_device rd;
	std::default_random_engine re(rd());
	re.seed(random_seed);

	for (__int32 i = 0; i < 64; ++i)
	{
		matrices[i] = GenerateRandomMatrix(re);
	}

	transform = GenerateRandomMatrix(re);
}

__declspec(noinline) void TestCase1_Ref_Reg(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_Ref_Reg(transform, matrices[mtx_index]);
		}
	});

	printf("TestCase1,ref_reg,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_Ref_Reg2(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_Ref_Reg2(transform, matrices[mtx_index], matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_Ref_Reg2(transform, matrices[mtx_index], matrices[mtx_index]);
		}
	});

	printf("TestCase1,ref_reg2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_Ref_RegFlip(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_Ref_RegFlip(transform, matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_Ref_RegFlip(transform, matrices[mtx_index]);
		}
	});

	printf("TestCase1,ref_regflip,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_Ref_RegFlip2(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_Ref_RegFlip2(transform, matrices[mtx_index], matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_Ref_RegFlip2(transform, matrices[mtx_index], matrices[mtx_index]);
		}
	});

	printf("TestCase1,ref_regflip2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_Ref_RegExp(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_Ref_RegExp(transform, matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_Ref_RegExp(transform, matrices[mtx_index]);
		}
	});

	printf("TestCase1,ref_regexp,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_Ref_RegExp2(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_Ref_RegExp2(transform, matrices[mtx_index], matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_Ref_RegExp2(transform, matrices[mtx_index], matrices[mtx_index]);
		}
	});

	printf("TestCase1,ref_regexp2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_Ref_Mem(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_Ref_Mem(transform, matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_Ref_Mem(transform, matrices[mtx_index]);
		}
	});

	printf("TestCase1,ref_mem,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_Ref_Mem2(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_Ref_Mem2(transform, matrices[mtx_index], matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_Ref_Mem2(transform, matrices[mtx_index], matrices[mtx_index]);
		}
	});

	printf("TestCase1,ref_mem2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_Ref_Inl(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_Ref_Inl(transform, matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_Ref_Inl(transform, matrices[mtx_index]);
		}
	});

	printf("TestCase1,ref_inl,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_Ref_Inl2(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_Ref_Inl2(transform, matrices[mtx_index], matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_Ref_Inl2(transform, matrices[mtx_index], matrices[mtx_index]);
		}
	});

	printf("TestCase1,ref_inl2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_Ref_InlExp(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_Ref_InlExp(transform, matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_Ref_InlExp(transform, matrices[mtx_index]);
		}
	});

	printf("TestCase1,ref_inlexp,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_Ref_InlExp2(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_Ref_InlExp2(transform, matrices[mtx_index], matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_Ref_InlExp2(transform, matrices[mtx_index], matrices[mtx_index]);
		}
	});

	printf("TestCase1,ref_inlexp2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V0_Reg(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V0_Reg(transform, matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V0_Reg(transform, matrices[mtx_index]);
		}
	});

	printf("TestCase1,v0_reg,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V0_Reg2(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V0_Reg2(transform, matrices[mtx_index], matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V0_Reg2(transform, matrices[mtx_index], matrices[mtx_index]);
		}
	});

	printf("TestCase1,v0_reg2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V0_RegFlip(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V0_RegFlip(transform, matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V0_RegFlip(transform, matrices[mtx_index]);
		}
	});

	printf("TestCase1,v0_regflip,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V0_RegFlip2(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V0_RegFlip2(transform, matrices[mtx_index], matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V0_RegFlip2(transform, matrices[mtx_index], matrices[mtx_index]);
		}
	});

	printf("TestCase1,v0_regflip2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V0_RegExp(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V0_RegExp(transform, matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V0_RegExp(transform, matrices[mtx_index]);
		}
	});

	printf("TestCase1,v0_regexp,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V0_RegExp2(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V0_RegExp2(transform, matrices[mtx_index], matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V0_RegExp2(transform, matrices[mtx_index], matrices[mtx_index]);
		}
	});

	printf("TestCase1,v0_regexp2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V0_Mem(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V0_Mem(transform, matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V0_Mem(transform, matrices[mtx_index]);
		}
	});

	printf("TestCase1,v0_mem,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V0_Mem2(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V0_Mem2(transform, matrices[mtx_index], matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V0_Mem2(transform, matrices[mtx_index], matrices[mtx_index]);
		}
	});

	printf("TestCase1,v0_mem2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V0_Inl(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V0_Inl(transform, matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V0_Inl(transform, matrices[mtx_index]);
		}
	});

	printf("TestCase1,v0_inl,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V0_Inl2(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V0_Inl2(transform, matrices[mtx_index], matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V0_Inl2(transform, matrices[mtx_index], matrices[mtx_index]);
		}
	});

	printf("TestCase1,v0_inl2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V0_InlExp(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V0_InlExp(transform, matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V0_InlExp(transform, matrices[mtx_index]);
		}
	});

	printf("TestCase1,v0_inlexp,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V0_InlExp2(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V0_InlExp2(transform, matrices[mtx_index], matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V0_InlExp2(transform, matrices[mtx_index], matrices[mtx_index]);
		}
	});

	printf("TestCase1,v0_inlexp2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V1_Reg(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V1_Reg(transform, matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V1_Reg(transform, matrices[mtx_index]);
		}
	});

	printf("TestCase1,v1_reg,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V1_Reg2(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V1_Reg2(transform, matrices[mtx_index], matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V1_Reg2(transform, matrices[mtx_index], matrices[mtx_index]);
		}
	});

	printf("TestCase1,v1_reg2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V1_RegFlip(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V1_RegFlip(transform, matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V1_RegFlip(transform, matrices[mtx_index]);
		}
	});

	printf("TestCase1,v1_regflip,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V1_RegFlip2(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V1_RegFlip2(transform, matrices[mtx_index], matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V1_RegFlip2(transform, matrices[mtx_index], matrices[mtx_index]);
		}
	});

	printf("TestCase1,v1_regflip2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V1_RegExp(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V1_RegExp(transform, matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V1_RegExp(transform, matrices[mtx_index]);
		}
	});

	printf("TestCase1,v1_regexp,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V1_RegExp2(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V1_RegExp2(transform, matrices[mtx_index], matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V1_RegExp2(transform, matrices[mtx_index], matrices[mtx_index]);
		}
	});

	printf("TestCase1,v1_regexp2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V1_Mem(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V1_Mem(transform, matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V1_Mem(transform, matrices[mtx_index]);
		}
	});

	printf("TestCase1,v1_mem,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V1_Mem2(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V1_Mem2(transform, matrices[mtx_index], matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V1_Mem2(transform, matrices[mtx_index], matrices[mtx_index]);
		}
	});

	printf("TestCase1,v1_mem2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V1_Inl(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V1_Inl(transform, matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V1_Inl(transform, matrices[mtx_index]);
		}
	});

	printf("TestCase1,v1_inl,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V1_Inl2(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V1_Inl2(transform, matrices[mtx_index], matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V1_Inl2(transform, matrices[mtx_index], matrices[mtx_index]);
		}
	});

	printf("TestCase1,v1_inl2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V1_InlExp(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V1_InlExp(transform, matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V1_InlExp(transform, matrices[mtx_index]);
		}
	});

	printf("TestCase1,v1_inlexp,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V1_InlExp2(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V1_InlExp2(transform, matrices[mtx_index], matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V1_InlExp2(transform, matrices[mtx_index], matrices[mtx_index]);
		}
	});

	printf("TestCase1,v1_inlexp2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V2_Reg(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V2_Reg(transform, matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V2_Reg(transform, matrices[mtx_index]);
		}
	});

	printf("TestCase1,v2_reg,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V2_Reg2(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V2_Reg2(transform, matrices[mtx_index], matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V2_Reg2(transform, matrices[mtx_index], matrices[mtx_index]);
		}
	});

	printf("TestCase1,v2_reg2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V2_RegFlip(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V2_RegFlip(transform, matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V2_RegFlip(transform, matrices[mtx_index]);
		}
	});

	printf("TestCase1,v2_regflip,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V2_RegFlip2(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V2_RegFlip2(transform, matrices[mtx_index], matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V2_RegFlip2(transform, matrices[mtx_index], matrices[mtx_index]);
		}
	});

	printf("TestCase1,v2_regflip2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V2_RegExp(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V2_RegExp(transform, matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V2_RegExp(transform, matrices[mtx_index]);
		}
	});

	printf("TestCase1,v2_regexp,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V2_RegExp2(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V2_RegExp2(transform, matrices[mtx_index], matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V2_RegExp2(transform, matrices[mtx_index], matrices[mtx_index]);
		}
	});

	printf("TestCase1,v2_regexp2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V2_Mem(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V2_Mem(transform, matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V2_Mem(transform, matrices[mtx_index]);
		}
	});

	printf("TestCase1,v2_mem,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V2_Mem2(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V2_Mem2(transform, matrices[mtx_index], matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V2_Mem2(transform, matrices[mtx_index], matrices[mtx_index]);
		}
	});

	printf("TestCase1,v2_mem2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V2_Inl(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V2_Inl(transform, matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V2_Inl(transform, matrices[mtx_index]);
		}
	});

	printf("TestCase1,v2_inl,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V2_Inl2(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V2_Inl2(transform, matrices[mtx_index], matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V2_Inl2(transform, matrices[mtx_index], matrices[mtx_index]);
		}
	});

	printf("TestCase1,v2_inl2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V2_InlExp(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V2_InlExp(transform, matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices[mtx_index] = XMMatrixMultiply_V2_InlExp(transform, matrices[mtx_index]);
		}
	});

	printf("TestCase1,v2_inlexp,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V2_InlExp2(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V2_InlExp2(transform, matrices[mtx_index], matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V2_InlExp2(transform, matrices[mtx_index], matrices[mtx_index]);
		}
	});

	printf("TestCase1,v2_inlexp2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V3_RegExp2(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V3_RegExp2(transform, matrices[mtx_index], matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V3_RegExp2(transform, matrices[mtx_index], matrices[mtx_index]);
		}
	});

	printf("TestCase1,v3_regexp2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V3_Mem2(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V3_Mem2(transform, matrices[mtx_index], matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V3_Mem2(transform, matrices[mtx_index], matrices[mtx_index]);
		}
	});

	printf("TestCase1,v3_mem2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V4_RegExp2(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V4_RegExp2(transform, matrices[mtx_index], matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V4_RegExp2(transform, matrices[mtx_index], matrices[mtx_index]);
		}
	});

	printf("TestCase1,v4_regexp2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase1_V4_Mem2(const __int32 random_seed, const __int32 num_iterations)
{
#if SANITY_CHECK_RESULTS
	{
		XMMATRIX matrices[64];
		XMMATRIX transform;
		TestCase1_Setup(random_seed, matrices, transform);

		XMMATRIX matrices_ref[64];
		XMMATRIX transform_ref;
		TestCase1_Setup(random_seed, matrices_ref, transform_ref);

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			matrices_ref[mtx_index] = XMMatrixMultiply_Ref_Reg(transform_ref, matrices_ref[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V4_Mem2(transform, matrices[mtx_index], matrices[mtx_index]);
		}

		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			EnsureMatrixEqual(matrices_ref[mtx_index], matrices[mtx_index]);
		}
	}
#endif

	XMMATRIX matrices[64];
	XMMATRIX transform;
	TestCase1_Setup(random_seed, matrices, transform);

	LONGLONG ticks = Measure(num_iterations, [&transform, &matrices]()
	{
		for (__int32 mtx_index = 0; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V4_Mem2(transform, matrices[mtx_index], matrices[mtx_index]);
		}
	});

	printf("TestCase1,v4_mem2,%f\n", TicksToMS(ticks));
}

void TestCase1(const __int32 random_seed, const __int32 num_samples, const __int32 num_iterations)
{
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_Ref_Reg(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_Ref_Reg2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_Ref_RegFlip(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_Ref_RegFlip2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_Ref_RegExp(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_Ref_RegExp2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_Ref_Mem(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_Ref_Mem2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_Ref_Inl(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_Ref_Inl2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_Ref_InlExp(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_Ref_InlExp2(random_seed, num_iterations);

	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V0_Reg(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V0_Reg2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V0_RegFlip(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V0_RegFlip2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V0_RegExp(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V0_RegExp2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V0_Mem(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V0_Mem2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V0_Inl(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V0_Inl2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V0_InlExp(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V0_InlExp2(random_seed, num_iterations);

	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V1_Reg(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V1_Reg2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V1_RegFlip(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V1_RegFlip2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V1_RegExp(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V1_RegExp2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V1_Mem(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V1_Mem2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V1_Inl(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V1_Inl2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V1_InlExp(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V1_InlExp2(random_seed, num_iterations);

	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V2_Reg(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V2_Reg2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V2_RegFlip(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V2_RegFlip2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V2_RegExp(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V2_RegExp2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V2_Mem(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V2_Mem2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V2_Inl(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V2_Inl2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V2_InlExp(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V2_InlExp2(random_seed, num_iterations);

	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V3_RegExp2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V3_Mem2(random_seed, num_iterations);

	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V4_RegExp2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase1_V4_Mem2(random_seed, num_iterations);
}
