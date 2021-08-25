#ifndef HAND_TRACKING_API_H
#define HAND_TRACKING_API_H

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


struct PoseInfo;
struct GestureRecognitionResult;


/*
@brief �ص����������ص�����
@param[out] image_index ��Ƶ֡����
@param[out] infos �洢��������ݵ�һά����
@param[out] count ���鳤�ȣ����������
*/
typedef void(*LandmarksCallBack)(int image_index, PoseInfo* infos, int count);

/*
@brief �ص�����ʶ�����ص�����
@param[out] image_index ��Ƶ֡����
@param[out] recogn_result �洢����ʶ������һά����
@param[out] count ���鳤�ȣ�ʶ��������
*/
typedef void(*GestureResultCallBack)(int image_index, int* recogn_result, int count);



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
	EXPORT_API int Mediapipe_Hand_Tracking_Init(const char* model_path);


	/*
	@brief ע��ص����������Ļص�����
	@param func �ص�����ָ��
	@return ���ز����ɹ�����ʧ��
		0 ʧ��
		1 �ɹ�
	*/
	EXPORT_API int Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback(LandmarksCallBack func);


	/*
	@brief ע������ʶ�����Ļص�����
	@param func �ص�����ָ��
	@return ���ز����ɹ�����ʧ��
		0 ʧ��
		1 �ɹ�
	*/
	EXPORT_API int Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback(GestureResultCallBack func);


	/*
	@brief �����Ƶ֡
	@param[in] image_index ��Ƶ֡������
	@param[in] image_width ��Ƶ֡���
	@param[in] image_height ��Ƶ֡�߶�
	@param[in] image_data ��Ƶ֡����
	@return ���ز����ɹ�����ʧ��
		0 ʧ��
		1 �ɹ�
	*/
	EXPORT_API int Mediapipe_Hand_Tracking_Detect_Frame(int image_index, int image_width, int image_height, void* image_data);

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
	EXPORT_API int Mediapipe_Hand_Tracking_Detect_Frame_Direct(int image_width, int image_height, void* image_data ,GestureRecognitionResult& gesture_result);


	/*
	@brief �����Ƶ
	@param[in] video_path ��Ƶ·��
	@param[in] show_image �Ƿ���ʾ�����Ƶ
	@return ���ز����ɹ�����ʧ��
		0 ʧ��
		1 �ɹ�
	*/
	EXPORT_API int Mediapipe_Hand_Tracking_Detect_Video(const char* video_path, int show_image);


	/*
	@brief Google Mediapipe�ͷ�
	@return ���ز����ɹ�����ʧ��
		0 ʧ��
		1 �ɹ�
	*/
	EXPORT_API int Mediapipe_Hand_Tracking_Release();


#ifdef __cplusplus
}
#endif 



#endif // !HAND_TRACKING_API_H
