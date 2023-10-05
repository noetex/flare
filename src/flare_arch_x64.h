typedef struct
{
	// Misc.
	bool_t x64;
	bool_t MMX;
	bool_t ABM;
	bool_t RDRAND;
	bool_t RDSEED;
	bool_t BMI1;
	bool_t BMI2;
	bool_t ADX;
	bool_t MPX;
	bool_t PREFETCHW;
	bool_t PREFETCHWT1;
	bool_t RDPID;

	// SIMD: 128-bit
	bool_t SSE;
	bool_t SSE2;
	bool_t SSE3;
	bool_t SSSE3;
	bool_t SSE41;
	bool_t SSE42;
	bool_t SSE4a;
	bool_t AES;
	bool_t SHA;

	// SIMD: 256-bit
	bool_t HW_AVX;
	bool_t HW_XOP;
	bool_t HW_FMA3;
	bool_t HW_FMA4;
	bool_t HW_AVX2;

	// SIMD: 512-bit
	bool_t AVX512_F;
	bool_t AVX512_CD;


	// Knights Landing
	bool_t AVX512_PF;
	bool_t AVX512_ER;

	// Skylake Purley
	bool_t AVX512_VL;
	bool_t AVX512_BW;
	bool_t AVX512_DQ;


	// Cannon Lake
	bool_t AVX512_IFMA;
	bool_t AVX512_VBMI;

	// Knights Mill
	bool_t AVX512_VPOPCNTDQ;
	bool_t AVX512_4VNNIW;
	bool_t AVX512_4FMAPS;

	// Cascade Lake
	bool_t AVX512_VNNI;

	// Cooper Lake
	bool_t AVX512_BF16;

	// Ice Lake
	bool_t AVX512_VBMI2;
	bool_t GFNI;
	bool_t VAES;
	bool_t AVX512_VPCLMUL;
	bool_t AVX512_BITALG;
} hardware_features_x86;
