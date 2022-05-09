#ifndef MEDIAPIPE_HOLISTIC_TRACKING_DLL_H
#define MEDIAPIPE_HOLISTIC_TRACKING_DLL_H

#include "DynamicModuleLoader.h"
using namespace DynamicModuleLoaderSpace;

typedef int (*FuncMediapipeHolisticTrackingInit)(const char* model_path, bool is_need_video_outputstream, bool is_need_pose_outputstream, bool is_need_hand_outputstream, bool is_need_face_outputstream);
typedef int (*FuncMediapipeHolisticTrackingDetectFrameDirect)(int image_width, int image_height, void* image_data, int* detect_result, bool show_result_image);
typedef int (*FuncMediapipeHolisticTrackingDetectCamera)(bool show_image);
typedef int (*FuncMediapipeHolisticTrackingRelease)();

class MediapipeHolisticTrackingDll
{
public:
	MediapipeHolisticTrackingDll();
	virtual~ MediapipeHolisticTrackingDll();

public:
	bool LoadMediapipeHolisticTrackingDll(const std::string& dll_path);
	bool UnLoadMediapipeHolisticTrackingDll();
	bool GetAllFunctions();

public:
	FuncMediapipeHolisticTrackingInit m_MediapipeHolisticTrackingInit;
	FuncMediapipeHolisticTrackingDetectFrameDirect m_MediapipeHolisticTrackingDetectFrameDirect;
	FuncMediapipeHolisticTrackingDetectCamera m_MediapipeHolisticTrackingDetectCamera;
	FuncMediapipeHolisticTrackingRelease m_MediapipeHolisticTrackingRelease;

private:
	DynamicModuleLoader m_DynamicModuleLoader;
};

#endif // !MEDIAPIPE_HOLISTIC_TRACKING_DLL_H
