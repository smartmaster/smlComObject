# CMakeList.txt : CMake project for smlComObject, include source and define
# project specific logic here.
#


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source to this project's executable.
add_executable (smlComObject 
"zzz-smlComObject.cpp"  
"smMetaType.h" 
"smMetaType.cpp"
"smIObjectBase.h" 
"smObjectBase.h" 
"smCommDefs.h" 
"smMetaTypeHelpers.h" 
"smPtrHelpers.h"
 "smIObjectBaseHelpers.h" 
 "xxx-test.cpp"
 "smQIHelper.h" 
 "smModuleHelper.cpp" 
 "smModuleHelper.h"
 "smModuleHelper.test.cpp"
 "smComRegistry.h" "smComRegistry.cpp" "smGUIDHelper.h" "yyy-test-misc.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET smlComObject PROPERTY CXX_STANDARD 20)
endif()


# TODO: Add tests and install targets if needed.
