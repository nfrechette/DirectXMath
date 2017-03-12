#include "stdafx.h"
#include "Inc\DirectXMath.h"

#include <iostream>
#include <conio.h>

#include "MatrixMultiply_Ref.h"
#include "MatrixMultiply_V0.h"
#include "MatrixMultiply_V1.h"
#include "MatrixMultiply_V2.h"
#include "Utils.h"

using namespace DirectX;

// Test case 2
// Local space -> object space
// Both matrices are always loaded from memory

void TestCase2_Setup(const __int32 random_seed, XMMATRIX matrices_local[64])
{
	std::random_device rd;
	std::default_random_engine re(rd());
	re.seed(random_seed);

	for (__int32 i = 0; i < 64; ++i)
	{
		matrices_local[i] = GenerateRandomMatrix(re);
	}
}

__declspec(noinline) void TestCase2_Ref_Reg(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			matrices_object[mtx_index] = XMMatrixMultiply_Ref_Reg(matrices_local[mtx_index], matrices_object[mtx_index - 1]);
		}
	});

	printf("TestCase2,ref_reg,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_Ref_Reg2(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_Ref_Reg2(matrices_local[mtx_index], matrices_object[mtx_index - 1], matrices_object[mtx_index]);
		}
	});

	printf("TestCase2,ref_reg2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_Ref_RegFlip(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			matrices_object[mtx_index] = XMMatrixMultiply_Ref_RegFlip(matrices_local[mtx_index], matrices_object[mtx_index - 1]);
		}
	});

	printf("TestCase2,ref_regflip,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_Ref_RegFlip2(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_Ref_RegFlip2(matrices_local[mtx_index], matrices_object[mtx_index - 1], matrices_object[mtx_index]);
		}
	});

	printf("TestCase2,ref_regflip2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_Ref_RegExp(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			matrices_object[mtx_index] = XMMatrixMultiply_Ref_RegExp(matrices_local[mtx_index], matrices_object[mtx_index - 1]);
		}
	});

	printf("TestCase2,ref_regexp,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_Ref_RegExp2(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_Ref_RegExp2(matrices_local[mtx_index], matrices_object[mtx_index - 1], matrices_object[mtx_index]);
		}
	});

	printf("TestCase2,ref_regexp2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_Ref_Mem(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			matrices_object[mtx_index] = XMMatrixMultiply_Ref_Mem(matrices_local[mtx_index], matrices_object[mtx_index - 1]);
		}
	});

	printf("TestCase2,ref_mem,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_Ref_Mem2(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_Ref_Mem2(matrices_local[mtx_index], matrices_object[mtx_index - 1], matrices_object[mtx_index]);
		}
	});

	printf("TestCase2,ref_mem2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_Ref_Inl(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			matrices_object[mtx_index] = XMMatrixMultiply_Ref_Inl(matrices_local[mtx_index], matrices_object[mtx_index - 1]);
		}
	});

	printf("TestCase2,ref_inl,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_Ref_Inl2(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_Ref_Inl2(matrices_local[mtx_index], matrices_object[mtx_index - 1], matrices_object[mtx_index]);
		}
	});

	printf("TestCase2,ref_inl2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_Ref_InlExp(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			matrices_object[mtx_index] = XMMatrixMultiply_Ref_InlExp(matrices_local[mtx_index], matrices_object[mtx_index - 1]);
		}
	});

	printf("TestCase2,ref_inlexp,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_Ref_InlExp2(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_Ref_InlExp2(matrices_local[mtx_index], matrices_object[mtx_index - 1], matrices_object[mtx_index]);
		}
	});

	printf("TestCase2,ref_inlexp2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V0_Reg(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			matrices_object[mtx_index] = XMMatrixMultiply_V0_Reg(matrices_local[mtx_index], matrices_object[mtx_index - 1]);
		}
	});

	printf("TestCase2,v0_reg,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V0_Reg2(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V0_Reg2(matrices_local[mtx_index], matrices_object[mtx_index - 1], matrices_object[mtx_index]);
		}
	});

	printf("TestCase2,v0_reg2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V0_RegFlip(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			matrices_object[mtx_index] = XMMatrixMultiply_V0_RegFlip(matrices_local[mtx_index], matrices_object[mtx_index - 1]);
		}
	});

	printf("TestCase2,v0_regflip,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V0_RegFlip2(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V0_RegFlip2(matrices_local[mtx_index], matrices_object[mtx_index - 1], matrices_object[mtx_index]);
		}
	});

	printf("TestCase2,v0_regflip2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V0_RegExp(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			matrices_object[mtx_index] = XMMatrixMultiply_V0_RegExp(matrices_local[mtx_index], matrices_object[mtx_index - 1]);
		}
	});

	printf("TestCase2,v0_regexp,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V0_RegExp2(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V0_RegExp2(matrices_local[mtx_index], matrices_object[mtx_index - 1], matrices_object[mtx_index]);
		}
	});

	printf("TestCase2,v0_regexp2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V0_Mem(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			matrices_object[mtx_index] = XMMatrixMultiply_V0_Mem(matrices_local[mtx_index], matrices_object[mtx_index - 1]);
		}
	});

	printf("TestCase2,v0_mem,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V0_Mem2(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V0_Mem2(matrices_local[mtx_index], matrices_object[mtx_index - 1], matrices_object[mtx_index]);
		}
	});

	printf("TestCase2,v0_mem2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V0_Inl(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			matrices_object[mtx_index] = XMMatrixMultiply_V0_Inl(matrices_local[mtx_index], matrices_object[mtx_index - 1]);
		}
	});

	printf("TestCase2,v0_inl,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V0_Inl2(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V0_Inl2(matrices_local[mtx_index], matrices_object[mtx_index - 1], matrices_object[mtx_index]);
		}
	});

	printf("TestCase2,v0_inl2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V0_InlExp(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			matrices_object[mtx_index] = XMMatrixMultiply_V0_InlExp(matrices_local[mtx_index], matrices_object[mtx_index - 1]);
		}
	});

	printf("TestCase2,v0_inlexp,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V0_InlExp2(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V0_InlExp2(matrices_local[mtx_index], matrices_object[mtx_index - 1], matrices_object[mtx_index]);
		}
	});

	printf("TestCase2,v0_inlexp2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V1_Reg(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			matrices_object[mtx_index] = XMMatrixMultiply_V1_Reg(matrices_local[mtx_index], matrices_object[mtx_index - 1]);
		}
	});

	printf("TestCase2,v1_reg,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V1_Reg2(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V1_Reg2(matrices_local[mtx_index], matrices_object[mtx_index - 1], matrices_object[mtx_index]);
		}
	});

	printf("TestCase2,v1_reg2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V1_RegFlip(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			matrices_object[mtx_index] = XMMatrixMultiply_V1_RegFlip(matrices_local[mtx_index], matrices_object[mtx_index - 1]);
		}
	});

	printf("TestCase2,v1_regflip,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V1_RegFlip2(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V1_RegFlip2(matrices_local[mtx_index], matrices_object[mtx_index - 1], matrices_object[mtx_index]);
		}
	});

	printf("TestCase2,v1_regflip2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V1_RegExp(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			matrices_object[mtx_index] = XMMatrixMultiply_V1_RegExp(matrices_local[mtx_index], matrices_object[mtx_index - 1]);
		}
	});

	printf("TestCase2,v1_regexp,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V1_RegExp2(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V1_RegExp2(matrices_local[mtx_index], matrices_object[mtx_index - 1], matrices_object[mtx_index]);
		}
	});

	printf("TestCase2,v1_regexp2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V1_Mem(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			matrices_object[mtx_index] = XMMatrixMultiply_V1_Mem(matrices_local[mtx_index], matrices_object[mtx_index - 1]);
		}
	});

	printf("TestCase2,v1_mem,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V1_Mem2(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V1_Mem2(matrices_local[mtx_index], matrices_object[mtx_index - 1], matrices_object[mtx_index]);
		}
	});

	printf("TestCase2,v1_mem2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V1_Inl(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			matrices_object[mtx_index] = XMMatrixMultiply_V1_Inl(matrices_local[mtx_index], matrices_object[mtx_index - 1]);
		}
	});

	printf("TestCase2,v1_inl,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V1_Inl2(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V1_Inl2(matrices_local[mtx_index], matrices_object[mtx_index - 1], matrices_object[mtx_index]);
		}
	});

	printf("TestCase2,v1_inl2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V1_InlExp(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			matrices_object[mtx_index] = XMMatrixMultiply_V1_InlExp(matrices_local[mtx_index], matrices_object[mtx_index - 1]);
		}
	});

	printf("TestCase2,v1_inlexp,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V1_InlExp2(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V1_InlExp2(matrices_local[mtx_index], matrices_object[mtx_index - 1], matrices_object[mtx_index]);
		}
	});

	printf("TestCase2,v1_inlexp2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V2_Reg(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			matrices_object[mtx_index] = XMMatrixMultiply_V2_Reg(matrices_local[mtx_index], matrices_object[mtx_index - 1]);
		}
	});

	printf("TestCase2,v2_reg,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V2_Reg2(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V2_Reg2(matrices_local[mtx_index], matrices_object[mtx_index - 1], matrices_object[mtx_index]);
		}
	});

	printf("TestCase2,v2_reg2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V2_RegFlip(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			matrices_object[mtx_index] = XMMatrixMultiply_V2_RegFlip(matrices_local[mtx_index], matrices_object[mtx_index - 1]);
		}
	});

	printf("TestCase2,v2_regflip,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V2_RegFlip2(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V2_RegFlip2(matrices_local[mtx_index], matrices_object[mtx_index - 1], matrices_object[mtx_index]);
		}
	});

	printf("TestCase2,v2_regflip2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V2_RegExp(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			matrices_object[mtx_index] = XMMatrixMultiply_V2_RegExp(matrices_local[mtx_index], matrices_object[mtx_index - 1]);
		}
	});

	printf("TestCase2,v2_regexp,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V2_RegExp2(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V2_RegExp2(matrices_local[mtx_index], matrices_object[mtx_index - 1], matrices_object[mtx_index]);
		}
	});

	printf("TestCase2,v2_regexp2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V2_Mem(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			matrices_object[mtx_index] = XMMatrixMultiply_V2_Mem(matrices_local[mtx_index], matrices_object[mtx_index - 1]);
		}
	});

	printf("TestCase2,v2_mem,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V2_Mem2(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V2_Mem2(matrices_local[mtx_index], matrices_object[mtx_index - 1], matrices_object[mtx_index]);
		}
	});

	printf("TestCase2,v2_mem2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V2_Inl(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			matrices_object[mtx_index] = XMMatrixMultiply_V2_Inl(matrices_local[mtx_index], matrices_object[mtx_index - 1]);
		}
	});

	printf("TestCase2,v2_inl,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V2_Inl2(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V2_Inl2(matrices_local[mtx_index], matrices_object[mtx_index - 1], matrices_object[mtx_index]);
		}
	});

	printf("TestCase2,v2_inl2,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V2_InlExp(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			matrices_object[mtx_index] = XMMatrixMultiply_V2_InlExp(matrices_local[mtx_index], matrices_object[mtx_index - 1]);
		}
	});

	printf("TestCase2,v2_inlexp,%f\n", TicksToMS(ticks));
}

__declspec(noinline) void TestCase2_V2_InlExp2(const __int32 random_seed, const __int32 num_iterations)
{
	XMMATRIX matrices_local[64];
	XMMATRIX matrices_object[64];
	TestCase2_Setup(random_seed, matrices_local);

	LONGLONG ticks = Measure(num_iterations, [&matrices_local, &matrices_object]()
	{
		matrices_object[0] = matrices_local[0];

		for (__int32 mtx_index = 1; mtx_index < 64; ++mtx_index)
		{
			XMMatrixMultiply_V2_InlExp2(matrices_local[mtx_index], matrices_object[mtx_index - 1], matrices_object[mtx_index]);
		}
	});

	printf("TestCase2,v2_inlexp2,%f\n", TicksToMS(ticks));
}

void ValidateTestCase2()
{

}

void TestCase2(const __int32 random_seed, const __int32 num_samples, const __int32 num_iterations)
{
	ValidateTestCase2();

	for (__int32 i = 0; i < num_samples; ++i) TestCase2_Ref_Reg(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_Ref_Reg2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_Ref_RegFlip(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_Ref_RegFlip2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_Ref_RegExp(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_Ref_RegExp2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_Ref_Mem(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_Ref_Mem2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_Ref_Inl(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_Ref_Inl2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_Ref_InlExp(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_Ref_InlExp2(random_seed, num_iterations);

	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V0_Reg(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V0_Reg2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V0_RegFlip(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V0_RegFlip2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V0_RegExp(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V0_RegExp2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V0_Mem(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V0_Mem2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V0_Inl(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V0_Inl2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V0_InlExp(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V0_InlExp2(random_seed, num_iterations);

	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V1_Reg(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V1_Reg2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V1_RegFlip(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V1_RegFlip2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V1_RegExp(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V1_RegExp2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V1_Mem(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V1_Mem2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V1_Inl(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V1_Inl2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V1_InlExp(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V1_InlExp2(random_seed, num_iterations);

	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V2_Reg(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V2_Reg2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V2_RegFlip(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V2_RegFlip2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V2_RegExp(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V2_RegExp2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V2_Mem(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V2_Mem2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V2_Inl(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V2_Inl2(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V2_InlExp(random_seed, num_iterations);
	for (__int32 i = 0; i < num_samples; ++i) TestCase2_V2_InlExp2(random_seed, num_iterations);
}
