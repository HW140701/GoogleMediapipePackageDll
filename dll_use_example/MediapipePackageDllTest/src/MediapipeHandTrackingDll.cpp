#include "MediapipeHandTrackingDll.h"

MediapipeHandTrackingDll::MediapipeHandTrackingDll()
{
	m_Mediapipe_Hand_Tracking_Init = nullptr;
	m_Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback = nullptr;
	m_Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback = nullptr;
	m_Mediapipe_Hand_Tracking_Detect_Frame = nullptr;
	m_Mediapipe_Hand_Tracking_Detect_Video = nullptr;
	m_Mediapipe_Hand_Tracking_Release = nullptr;
}

MediapipeHandTrackingDll::~MediapipeHandTrackingDll()
{
	if (m_DynamicModuleLoader.GetDynamicModuleState())
	{
		m_DynamicModuleLoader.UnloadDynamicModule();
	}
}

bool MediapipeHandTrackingDll::LoadMediapipeHandTrackingDll(const std::string& dll_path)
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

bool MediapipeHandTrackingDll::UnLoadMediapipeHandTrackingDll()
{
	if (m_DynamicModuleLoader.UnloadDynamicModule())
	{
		return true;
	}

	return false;
}

bool MediapipeHandTrackingDll::GetAllFunctions()
{
	if (m_DynamicModuleLoader.GetDynamicModuleState())
	{
		// 获取Mediapipe_Hand_Tracking_Init
		void* p_Mediapipe_Hand_Tracking_Init = m_DynamicModuleLoader.GetFunction("Mediapipe_Hand_Tracking_Init");
		if (p_Mediapipe_Hand_Tracking_Init != nullptr)
		{
			m_Mediapipe_Hand_Tracking_Init = (Func_Mediapipe_Hand_Tracking_Init(p_Mediapipe_Hand_Tracking_Init));
			if (m_Mediapipe_Hand_Tracking_Init != nullptr)
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

		// 获取Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback
		void* p_Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback = m_DynamicModuleLoader.GetFunction("Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback");
		if (p_Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback != nullptr)
		{
			m_Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback = (Func_Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback(p_Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback));
			if (m_Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback != nullptr)
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



		// 获取Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback
		void* p_Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback = m_DynamicModuleLoader.GetFunction("Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback");
		if (p_Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback != nullptr)
		{
			m_Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback = (Func_Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback(p_Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback));
			if (m_Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback != nullptr)
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


		// 获取Mediapipe_Hand_Tracking_Detect_Frame
		void* p_Mediapipe_Hand_Tracking_Detect_Frame = m_DynamicModuleLoader.GetFunction("Mediapipe_Hand_Tracking_Detect_Frame");
		if (p_Mediapipe_Hand_Tracking_Detect_Frame != nullptr)
		{
			m_Mediapipe_Hand_Tracking_Detect_Frame = (Func_Mediapipe_Hand_Tracking_Detect_Frame(p_Mediapipe_Hand_Tracking_Detect_Frame));
			if (m_Mediapipe_Hand_Tracking_Detect_Frame != nullptr)
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

		// 获取Mediapipe_Hand_Tracking_Detect_Frame_Direct
		void* p_Mediapipe_Hand_Tracking_Detect_Frame_Direct = m_DynamicModuleLoader.GetFunction("Mediapipe_Hand_Tracking_Detect_Frame_Direct");
		if (p_Mediapipe_Hand_Tracking_Detect_Frame_Direct != nullptr)
		{
			m_Mediapipe_Hand_Tracking_Detect_Frame_Direct = (Func_Mediapipe_Hand_Tracking_Detect_Frame_Direct)(p_Mediapipe_Hand_Tracking_Detect_Frame_Direct);
			if (m_Mediapipe_Hand_Tracking_Detect_Frame_Direct != nullptr)
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

		// 获取Mediapipe_Hand_Tracking_Detect_Video
		void* p_Mediapipe_Hand_Tracking_Detect_Video = m_DynamicModuleLoader.GetFunction("Mediapipe_Hand_Tracking_Detect_Video");
		if (p_Mediapipe_Hand_Tracking_Detect_Video != nullptr)
		{
			m_Mediapipe_Hand_Tracking_Detect_Video = (Func_Mediapipe_Hand_Tracking_Detect_Video(p_Mediapipe_Hand_Tracking_Detect_Video));
			if (m_Mediapipe_Hand_Tracking_Detect_Video != nullptr)
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


		// 获取Mediapipe_Hand_Tracking_Release
		void* p_Mediapipe_Hand_Tracking_Release = m_DynamicModuleLoader.GetFunction("Mediapipe_Hand_Tracking_Release");
		if (p_Mediapipe_Hand_Tracking_Release != nullptr)
		{
			m_Mediapipe_Hand_Tracking_Release = (Func_Mediapipe_Hand_Tracking_Release(p_Mediapipe_Hand_Tracking_Release));
			if (m_Mediapipe_Hand_Tracking_Release != nullptr)
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
