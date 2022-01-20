#include "MediapipeHolisticTrackingDll.h"

MediapipeHolisticTrackingDll::MediapipeHolisticTrackingDll()
{
	m_MediapipeHolisticTrackingInit = nullptr;
	m_MediapipeHolisticTrackingDetectFrameDirect = nullptr;
	m_MediapipeHolisticTrackingRelease = nullptr;
}

MediapipeHolisticTrackingDll::~MediapipeHolisticTrackingDll()
{
	if (m_DynamicModuleLoader.GetDynamicModuleState())
	{
		m_DynamicModuleLoader.UnloadDynamicModule();
	}
}

bool MediapipeHolisticTrackingDll::LoadMediapipeHolisticTrackingDll(const std::string& dll_path)
{
	std::string dllPath = dll_path;
	if (m_DynamicModuleLoader.IsFileExist(dllPath))
	{
		if (m_DynamicModuleLoader.LoadDynamicModule(dllPath))
		{
			return true;
		}
	}

	return false;
}

bool MediapipeHolisticTrackingDll::UnLoadMediapipeHolisticTrackingDll()
{
	if (m_DynamicModuleLoader.UnloadDynamicModule())
	{
		return true;
	}

	return false;
}

bool MediapipeHolisticTrackingDll::GetAllFunctions()
{
	if (m_DynamicModuleLoader.GetDynamicModuleState())
	{
		void* pMediapipeHolisticTrackingInit = m_DynamicModuleLoader.GetFunction("MediapipeHolisticTrackingInit");
		if (pMediapipeHolisticTrackingInit != nullptr)
		{
			m_MediapipeHolisticTrackingInit = (FuncMediapipeHolisticTrackingInit)(pMediapipeHolisticTrackingInit);
			if (m_MediapipeHolisticTrackingInit != nullptr)
			{
				
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}

		void* pMediapipeHolisticTrackingDetectFrameDirect = m_DynamicModuleLoader.GetFunction("MediapipeHolisticTrackingDetectFrameDirect");
		if (pMediapipeHolisticTrackingDetectFrameDirect != nullptr)
		{
			m_MediapipeHolisticTrackingDetectFrameDirect = (FuncMediapipeHolisticTrackingDetectFrameDirect)(pMediapipeHolisticTrackingDetectFrameDirect);
			if (m_MediapipeHolisticTrackingDetectFrameDirect != nullptr)
			{

			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}

		void* pMediapipeHolisticTrackingDetectCamera = m_DynamicModuleLoader.GetFunction("MediapipeHolisticTrackingDetectCamera");
		if (pMediapipeHolisticTrackingDetectCamera != nullptr)
		{
			m_MediapipeHolisticTrackingDetectCamera = (FuncMediapipeHolisticTrackingDetectCamera)(pMediapipeHolisticTrackingDetectCamera);
			if (m_MediapipeHolisticTrackingDetectCamera != nullptr)
			{

			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}

		void* pMediapipeHolisticTrackingRelease = m_DynamicModuleLoader.GetFunction("MediapipeHolisticTrackingRelease");
		if (pMediapipeHolisticTrackingRelease != nullptr)
		{
			m_MediapipeHolisticTrackingRelease = (FuncMediapipeHolisticTrackingRelease)(pMediapipeHolisticTrackingRelease);
			if (m_MediapipeHolisticTrackingRelease != nullptr)
			{

			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	return true;
}
