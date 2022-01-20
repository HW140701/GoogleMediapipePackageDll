#include "DynamicModuleLoader.h"

namespace DynamicModuleLoaderSpace
{
	DynamicModuleLoader::DynamicModuleLoader() :m_DynamicModulePtr(NULL), m_ErrorMessage(""), m_DynamicModuleState(DynamicModuleState::DMS_UnLoaded)
	{
	}

	DynamicModuleLoader::~DynamicModuleLoader()
	{
	}

	bool DynamicModuleLoader::IsFileExist(const std::string filePath)
	{
		std::fstream file;
		file.open(filePath, std::ios::in);
		if (file)
		{
			file.close();
			return true;
		}
		else
		{
			return false;
		}
	}

	bool DynamicModuleLoader::LoadDynamicModule(const std::string dynamicModulePath)
	{
		if (IsFileExist(dynamicModulePath))
		{
#ifdef WINDOWS
			m_DynamicModulePtr = LoadLibrary(dynamicModulePath.c_str());
#elif LINUX
			m_DynamicModulePtr = dlopen(dynamicModulePath.c_str(), RTLD_NOW | RTLD_GLOBAL);
#endif // WINDOWS

			if (m_DynamicModulePtr != NULL)
			{
				m_DynamicModuleState = DynamicModuleState::DMS_Loaded;
				return true;
			}
			else
			{
#ifdef WINDOWS
				int errorCode = GetLastError();
#endif
				GetInternalErrorMessge(errorCode);
				return false;
			}

		}

		return false;
	}

	void* DynamicModuleLoader::GetFunction(const std::string functionName)
	{
		if (m_DynamicModulePtr)
		{
			void* tempFunctionPtr = NULL;
#ifdef WINDOWS
			tempFunctionPtr = GetProcAddress(m_DynamicModulePtr, functionName.c_str());
#elif LINUX
			tempFunctionPtr = dlsym(m_DynamicModulePtr, functionName.c_str());
#endif // WINDOWS

			if (tempFunctionPtr != NULL)
			{
				return tempFunctionPtr;
			}
			else
			{
#ifdef WINDOWS
				int errorCode = GetLastError();
#endif
				GetInternalErrorMessge(errorCode);
			}
		}

		return NULL;
	}

	bool DynamicModuleLoader::UnloadDynamicModule()
	{
		if (m_DynamicModulePtr)
		{
#ifdef WINDOWS
			if (FreeLibrary(m_DynamicModulePtr) == 0)
			{
				int errorCode = GetLastError(); // 得到错误代码
				GetInternalErrorMessge(errorCode);
				return false;
			}
#elif LINUX
			dlclose(m_DynamicModulePtr);
#endif
			m_DynamicModuleState = DynamicModuleState::DMS_UnLoaded;
			return true;
		}
		return false;
	}

#ifdef WINDOWS

#endif


	void DynamicModuleLoader::GetInternalErrorMessge(int errorCode)
	{
		std::string errorMessge = "";
#ifdef WINDOWS
		LPVOID lpMsgBuf;
		if (FormatMessage(
			FORMAT_MESSAGE_ALLOCATE_BUFFER |
			FORMAT_MESSAGE_FROM_SYSTEM |
			FORMAT_MESSAGE_IGNORE_INSERTS |
			FORMAT_MESSAGE_MAX_WIDTH_MASK,
			NULL,
			errorCode,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPTSTR)&lpMsgBuf,
			0,
			NULL
		))
		{
			errorMessge = (LPCTSTR)(lpMsgBuf);
			LocalFree(lpMsgBuf);
		}
#elif LINUX
		errorMessge = dlerror();
#endif // WINDOWS

		m_ErrorMessage = errorMessge;
	}

	std::string DynamicModuleLoader::GetErrorMessage()
	{
		return m_ErrorMessage;
	}

	bool DynamicModuleLoader::GetDynamicModuleState()
	{
		return (bool)m_DynamicModuleState;
	}
}
