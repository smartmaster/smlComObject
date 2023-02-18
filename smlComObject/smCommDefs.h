#pragma once

#define SM_NAME_OF(x) #x
#define SM_EXPAND_MACRO(x) SM_NAME_OF(x)


#if false
void fooooo()
{
	do {
		int var_88A2B523B28343EDA53B1AA01D247327 ## x = x;

		if (xxx)
		{
			(void)(var_88A2B523B28343EDA53B1AA01D247327 ## x);
			break;
		}

		(void)(var_88A2B523B28343EDA53B1AA01D247327 ## x);
	} while (0);
}
#endif

#define SM_BEGIN_BLOCK(x) \
	do { \
		int var_88A2B523B28343EDA53B1AA01D247327 ## x = x;

#define SM_LEAVE_BLOCK(x) \
		{ \
			(var_88A2B523B28343EDA53B1AA01D247327 ## x); \
			break; \
		}

#define SM_END_BLOCK(x) \
		(var_88A2B523B28343EDA53B1AA01D247327 ## x); \
	} while (0);


