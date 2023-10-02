static bool_t
strings_equal(char* String1, char* String2)
{
	for(;;)
	{
		if((!String1) || (!String2))
		{
			return (String1 == String2);
		}
		if((*String1) != (*String2))
		{
			return false;
		}
		if((*String1) == '\0')
		{
			return true;
		}
		String1 += 1;
		String2 += 1;
	}
}
