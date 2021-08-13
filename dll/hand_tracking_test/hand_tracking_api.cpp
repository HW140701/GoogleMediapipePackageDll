#include "hand_tracking_api.h"
#include "hand_tracking_detect.h"

using namespace GoogleMediapipeHandTrackingDetect;

HandTrackingDetect m_HandTrackingDetect;

EXPORT_API int Mediapipe_Hand_Tracking_Init(const char* model_path)
{
	return m_HandTrackingDetect.InitGraph(model_path);
}


EXPORT_API int Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback(LandmarksCallBack func)
{
	return m_HandTrackingDetect.RegisterLandmarksCallback(func);
}

EXPORT_API int Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback(GestureResultCallBack func)
{
	return m_HandTrackingDetect.RegisterGestureResultCallBack(func);
}

EXPORT_API int Mediapipe_Hand_Tracking_Detect_Frame(int image_index, int image_width, int image_height, void* image_data)
{
	return m_HandTrackingDetect.DetectFrame(image_index, image_width, image_height, image_data);
}

EXPORT_API int Mediapipe_Hand_Tracking_Detect_Video(const char* video_path, int show_image)
{
	return m_HandTrackingDetect.DetectVideo(video_path, show_image);
}


EXPORT_API int Mediapipe_Hand_Tracking_Release()
{
	return m_HandTrackingDetect.Release();
}