#include "MediapipeHolisticTrackingDll.h"

MediapipeHolisticTrackingDll::MediapipeHolisticTrackingDll()
{
	m_Mediapipe_Holistic_Tracking_Init = nullptr;
	m_Mediapipe_Holistic_Tracking_Detect_Frame_Direct = nullptr;
	m_Mediapipe_Holistic_Tracking_Release = nullptr;
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
		void* pMediapipe_Holistic_Tracking_Init = m_DynamicModuleLoader.GetFunction("MediapipeHolisticTrackingInit");
		if (pMediapipe_Holistic_Tracking_Init != nullptr)
		{
			m_Mediapipe_Holistic_Tracking_Init = (FuncMediapipeHolisticTrackingInit)(pMediapipe_Holistic_Tracking_Init);
			if (m_Mediapipe_Holistic_Tracking_Init != nullptr)
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

		void* pMediapipe_Holistic_Tracking_Detect_Frame_Direct = m_DynamicModuleLoader.GetFunction("MediapipeHolisticTrackingDetectFrameDirect");
		if (pMediapipe_Holistic_Tracking_Detect_Frame_Direct != nullptr)
		{
			m_Mediapipe_Holistic_Tracking_Detect_Frame_Direct = (FuncMediapipeHolisticTrackingDetectFrameDirect)(pMediapipe_Holistic_Tracking_Detect_Frame_Direct);
			if (m_Mediapipe_Holistic_Tracking_Detect_Frame_Direct != nullptr)
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

		void* pMediapipe_Holistic_Tracking_Detect_Camera = m_DynamicModuleLoader.GetFunction("MediapipeHolisticTrackingDetectCamera");
		if (pMediapipe_Holistic_Tracking_Detect_Camera != nullptr)
		{
			m_Mediapipe_Holistic_Tracking_Detect_Camera = (FuncMediapipeHolisticTrackingDetectCamera)(pMediapipe_Holistic_Tracking_Detect_Camera);
			if (m_Mediapipe_Holistic_Tracking_Detect_Camera != nullptr)
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

		void* pMediapipe_Holistic_Tracking_Release = m_DynamicModuleLoader.GetFunction("MediapipeHolisticTrackingRelease");
		if (pMediapipe_Holistic_Tracking_Release != nullptr)
		{
			m_Mediapipe_Holistic_Tracking_Release = (FuncMediapipeHolisticTrackingRelease)(pMediapipe_Holistic_Tracking_Release);
			if (m_Mediapipe_Holistic_Tracking_Release != nullptr)
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
