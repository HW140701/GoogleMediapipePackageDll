#ifndef MEDIAPIPE_HAND_TRACKING_DLL_H
#define MEDIAPIPE_HAND_TRACKING_DLL_H

#include "DynamicModuleLoader.h"
using namespace DynamicModuleLoaderSpace;

struct PoseInfo {
	float x;
	float y;
};

struct GestureRecognitionResult
{
	int m_Gesture_Recognition_Result[2] = { -1,-1 };
	int m_HandUp_HandDown_Detect_Result[2] = { -1,-1 };
};

typedef void(*LandmarksCallBack)(int image_index, PoseInfo* infos, int count);
typedef void(*GestureResultCallBack)(int image_index, int* recogn_result, int count);

typedef int (*Func_Mediapipe_Hand_Tracking_Init)(const char* model_path);
typedef int (*Func_Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback)(LandmarksCallBack func);
typedef int (*Func_Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback)(GestureResultCallBack func);
typedef int (*Func_Mediapipe_Hand_Tracking_Detect_Frame)(int image_index, int image_width, int image_height, void* image_data);
typedef int (*Func_Mediapipe_Hand_Tracking_Detect_Frame_Direct)(int image_width, int image_height, void* image_data, GestureRecognitionResult& gesture_result);
typedef int (*Func_Mediapipe_Hand_Tracking_Detect_Video)(const char* video_path, int show_image);
typedef int (*Func_Mediapipe_Hand_Tracking_Release)();

class MediapipeHandTrackingDll
{
public:
	MediapipeHandTrackingDll();
	virtual~MediapipeHandTrackingDll();

public:
	bool LoadMediapipeHandTrackingDll(const std::string& dll_path);
	bool UnLoadMediapipeHandTrackingDll();
	bool GetAllFunctions();


public:
	Func_Mediapipe_Hand_Tracking_Init m_Mediapipe_Hand_Tracking_Init;
	Func_Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback m_Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback;
	Func_Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback m_Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback;
	Func_Mediapipe_Hand_Tracking_Detect_Frame m_Mediapipe_Hand_Tracking_Detect_Frame;
	Func_Mediapipe_Hand_Tracking_Detect_Video m_Mediapipe_Hand_Tracking_Detect_Video;
	Func_Mediapipe_Hand_Tracking_Detect_Frame_Direct m_Mediapipe_Hand_Tracking_Detect_Frame_Direct;
	Func_Mediapipe_Hand_Tracking_Release m_Mediapipe_Hand_Tracking_Release;

private:
	DynamicModuleLoader m_DynamicModuleLoader;
};


#endif // !MEDIAPIPE_HAND_TRACKING_DLL_H
