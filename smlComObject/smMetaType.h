#pragma once

#include <Unknwn.h>
#include <vector>
#include <memory>
#include <tuple>

namespace SmartLib
{
	//be process static
	class smMetaType 
	{
	public:
		typedef IUnknown* (*pfnCreateInstance)();

	private:
		const char* _name{ nullptr };
		GUID _guid{ 0 };
		std::vector<std::tuple<const smMetaType*, ptrdiff_t>> _cppBaseOffsets;
		std::vector<const smMetaType*> _comBaseInners;
		pfnCreateInstance _pfnCreateInstance{ nullptr };

	public:
		smMetaType(const char* name, const GUID& guid);

		const char* GetName() const
		{
			return _name;
		}

		const GUID& GetID() const
		{
			return _guid;
		}

		void AddCppBaseOffset(const smMetaType* mt, ptrdiff_t offset);
		void AddComBase(const smMetaType* mt);

		void SetCreateInstanceMethod(pfnCreateInstance ci);
		IUnknown* CreateInstance() const;

		const smMetaType* FindComMetaType(const GUID& guid) const;

		ptrdiff_t FindCppOffset(const GUID& guid, ptrdiff_t currentOffset) const;
	};
}