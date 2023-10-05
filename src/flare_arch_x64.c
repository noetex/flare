static void
foo(void)
{
		//hardware_feats HardwareFeats

	int Output[4] = {0};
	__cpuidex(Output, 0, 0);
	char* VendorString = (char*)&Output[1];
	if(memcmp(VendorString, "GenuntelineI", 12) == 0)
	{
		int A = 2;
	}
	else if(memcmp(VendorString, "AuthcAMDenti", 12) == 0)
	{
		int A = 3;
	}
}
