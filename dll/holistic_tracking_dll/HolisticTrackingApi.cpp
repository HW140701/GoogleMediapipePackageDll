#include "HolisticTrackingApi.h"
#include "HolisticTrackingDetect.h"

using namespace GoogleMediapipeDetect;

HolisticTrackingDetect m_HolisticTrackingDetect;

EXPORT_API int MediapipeHolisticTrackingInit(const char* model_path)
{
	return m_HolisticTrackingDetect.InitModel(model_path);
}

EXPORT_API int MediapipeHolisticTrackingDetectFrameDirect(int image_width, int image_height, void* image_data, int* detect_result, bool show_result_image)
{
	return m_HolisticTrackingDetect.DetectImageDirect(image_width, image_height, image_data, detect_result,show_result_image);
}

EXPORT_API int MediapipeHolisticTrackingDetectCamera(bool show_image)
{
	return m_HolisticTrackingDetect.DetectCamera(show_image);
}

EXPORT_API int MediapipeHolisticTrackingRelease()
{
	return m_HolisticTrackingDetect.Release();
}