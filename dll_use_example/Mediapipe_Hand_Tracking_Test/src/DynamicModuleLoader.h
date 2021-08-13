//!
//! @brief - Load dynamic libraries on Windows and Linux platforms
//!
//!	@author - HuangWang
//!
//! @data - 2019-09-26
//!


#ifndef _DYNAMIC_MODULE_LOADER_H_
#define _DYNAMIC_MODULE_LOADER_H_

#include <string>
#include <fstream>

#define _DYNAMIC_LOAD
#define WINDOWS

#if defined(_DYNAMIC_LOAD)

#if defined(WINDOWS)
#include <Windows.h>
#define MODULE_HANDLER HINSTANCE
#elif defined(LINUX)
#include <dlfcn.h>
#define MODULE_HANDLER void*
#endif 

#endif


#ifdef WINDOWS
#define PLATFORM_PATH_SPLIT_CHAR "\\"
#define PLATFORM_DYNAMIC_LIBRARY_PRE ""
#define PLATFORM_DYNAMIC_LIBRARY_EXT ".dll"
#elif defined (LINUX)
#define PLATFORM_PATH_SPLIT_CHAR "/"
#define PLATFORM_DYNAMIC_LIBRARY_PRE "lib"
#define PLATFORM_DYNAMIC_LIBRARY_EXT ".so"
#endif // WINDOWS


namespace DynamicModuleLoaderSpace
{
	enum DynamicModuleState
	{
		DMS_UnLoaded = 0,
		DMS_Loaded = 1
	};

	class DynamicModuleLoader
	{
	public:
		DynamicModuleLoader();
		virtual ~DynamicModuleLoader();

		static bool IsFileExist(const std::string filePath);

		bool LoadDynamicModule(const std::string dynamicModulePath);

		void* GetFunction(const std::string functionName);

		bool UnloadDynamicModule();

		std::string GetErrorMessage();

		bool GetDynamicModuleState();
	private:
		void GetInternalErrorMessge(int errorCode);
	private:
		MODULE_HANDLER m_DynamicModulePtr;

		std::string m_ErrorMessage;

		DynamicModuleState m_DynamicModuleState;
	};
}


#endif /// _DYNAMIC_MODULE_LOADER_H_
