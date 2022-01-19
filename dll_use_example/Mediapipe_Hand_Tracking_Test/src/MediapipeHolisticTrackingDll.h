#ifndef MEDIAPIPE_HOLISTIC_TRACKING_DLL_H
#define MEDIAPIPE_HOLISTIC_TRACKING_DLL_H

#include "DynamicModuleLoader.h"
using namespace DynamicModuleLoaderSpace;

typedef int (*FuncMediapipeHolisticTrackingInit)(const char* model_path);
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
	FuncMediapipeHolisticTrackingInit m_Mediapipe_Holistic_Tracking_Init;
	FuncMediapipeHolisticTrackingDetectFrameDirect m_Mediapipe_Holistic_Tracking_Detect_Frame_Direct;
	FuncMediapipeHolisticTrackingDetectCamera m_Mediapipe_Holistic_Tracking_Detect_Camera;
	FuncMediapipeHolisticTrackingRelease m_Mediapipe_Holistic_Tracking_Release;

private:
	DynamicModuleLoader m_DynamicModuleLoader;
};

#endif // !MEDIAPIPE_HOLISTIC_TRACKING_DLL_H
