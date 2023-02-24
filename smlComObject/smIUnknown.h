#pragma once

#include <Unknwn.h>

namespace SmartLib
{
	class smMetaType;

	class smIUnknown : public IUnknown
	{
	public:
		static const smMetaType* StaticMetaType();
	};
}