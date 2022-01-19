#ifndef HOLISTIC_TRACKING_API_H
#define HOLISTIC_TRACKING_API_H

#define EXPORT

/* ���嶯̬���ӿ�dll�ĵ��� */
#include <malloc.h>
#ifdef _WIN32
#ifdef EXPORT
#define EXPORT_API __declspec(dllexport)
#else
#define EXPORT_API __declspec(dllimport)
#endif
#else
#include <stdlib.h>

#ifdef EXPORT
#define EXPORT_API __attribute__((visibility ("default")))
#else
#endif

#endif


#ifdef __cplusplus
extern "C" {
#endif 

#ifndef EXPORT_API
#define EXPORT_API
#endif

	/*
	@brief ��ʼ��Google Mediapipe
	@param[in] model_path ��Ҫ���ص�ģ��·��
	@return ���ز����ɹ�����ʧ��
		0 ʧ��
		1 �ɹ�
	*/
	EXPORT_API int MediapipeHolisticTrackingInit(const char* model_path);

	/*
	@brief �����Ƶ֡
	@param[in] image_width ��Ƶ֡���
	@param[in] image_height ��Ƶ֡�߶�
	@param[in] image_data ��Ƶ֡����
	@param[out] gesture_result - ����ʶ����
	@return ���ز����ɹ�����ʧ��
		0 ʧ��
		1 �ɹ�
	*/
	EXPORT_API int MediapipeHolisticTrackingDetectFrameDirect(int image_width, int image_height, void* image_data, int* detect_result, bool show_result_image = false);

	/*
	@brief �������ͷ
	@param[in] show_image �Ƿ���ʾ���ͼƬ
	@return ���ز����ɹ�����ʧ��
	0 ʧ��
	1 �ɹ�
	*/
	EXPORT_API int MediapipeHolisticTrackingDetectCamera(bool show_image = false);
	/*
	@brief Google Mediapipe�ͷ�
	@return ���ز����ɹ�����ʧ��
		0 ʧ��
		1 �ɹ�
	*/
	EXPORT_API int MediapipeHolisticTrackingRelease();


#ifdef __cplusplus
}
#endif 

#endif // !HOLISTIC_TRACKING_API_H
