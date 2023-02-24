#include "smIObjectBase.h"


namespace SmartLib
{
	const smMetaType* smIObjectBase::StaticMetaType()
	{
		return smMetaTypeMaker::Make<smIObjectBase, smIUnknown>(
			SM_NAME_OF(smIObjectBase),
			GUID{ 0xd647181d, 0xe29d, 0x4afc,{ 0x96, 0x6d, 0x50, 0xf5, 0xce, 0x49, 0x94, 0xbf } }
		);
	}
}


