#include "Media.h"



void Media::print_Picture(string name) // 사진정보출력함수
{
	load_pro_name();
	string str;
	bool check =false;
	for(int i=0 ; i< count ; i++)
	{
		if(P_DB[i]->get_P_name() == name)
		{
			 str = name +".png"; //사진의 확장자까지 가져온다
			 check=true;
			 break;
		}
	
	}
	if(check == true)// DB에 정보가있을때
	{

	IplImage *pEviMonitor; //변수선언
	pEviMonitor = cvLoadImage(str.c_str()); //이미지로드

	cvShowImage(name.c_str(),pEviMonitor); //이미지 출력

	waitKey(0); //입력받을때까지 기다림

	cvReleaseImage(&pEviMonitor);
	cvDestroyWindow(name.c_str());
	}
	else //사진정보가 없을때
	{
		cout<<"\n\t 해당 상품의 사진 정보는 존재 하지않습니다 \n ";
		system("pause");
	}

}

void Media::On_Capture() // CCTV기능을 구현하는 함수이다.
{
	IplImage * ori_ori = NULL; //원조 이미지 변수 생성
	IplImage * ori = NULL; //크기를 조절할 이미지 변수 생성
	CvCapture *capture = cvCaptureFromCAM(0); //캠의 정보를 받아온다.

	CvVideoWriter* videoOut = NULL; //동영상 저장을 위한 변수
	
	time_t _c_time; 
    _c_time = time(NULL);

	 struct tm *t;
	 t=localtime(&_c_time);

	 string currentTime;

	 int year, month, day, hour, min;
	 int buf;
	 char target[10];
	 
   //현재시간을 저장해준다.
	year = t->tm_year+1900;
	month = t->tm_mon+1;
	day = t->tm_mday;
	hour = t->tm_hour;
	min = t->tm_min;

	buf=year;
	itoa(buf,target,10);
	currentTime.append(target);

	currentTime.append("년 ");

	buf=month;
	itoa(buf,target,10);
	currentTime.append(target);

	currentTime.append("월 ");

	buf=day;
	
	itoa(buf,target,10);
	currentTime.append(target);

	currentTime.append("일 ");


	string str = currentTime+ "CCTV.avi"; //현재날짜 +CCTV 로 화면 이름선언
	
	cvNamedWindow(str.c_str(),1); //현재날짜 +CCTV 로 화면 이름선언
	
	while(1)
	{
		cvGrabFrame(capture); //캡쳐된 영상을 받아옴
		ori_ori = cvRetrieveFrame(capture); //원조 이미지
		ori = cvCreateImage(cvSize(400,200),IPL_DEPTH_8U,3); //이미지 생성
		cvResize(ori_ori,ori,CV_INTER_LINEAR); //크기 축소

		
			if( videoOut == NULL) // 기존 비디오에 아무정보가 없을때
			{
				videoOut = cvCreateVideoWriter(str.c_str(),-1,30,cvGetSize(ori),1);
				//동영상객체를 만든뒤 정보저장
			}
			
			cvWriteFrame(videoOut,ori);//계속해서 정보저장
			
		cvShowImage(str.c_str(),ori); //웹캠 영상 출력

		if(cvWaitKey(33)>=27) // ESC가 입력될때까지
			break;

		cvReleaseImage(&ori); // 메모리해제
	}

	cvReleaseVideoWriter(&videoOut); //비디오 객체 메모리해제
	cvDestroyWindow(str.c_str()); //윈도우 영상 닫기

	cvReleaseCapture(&capture); // 캠처영상 메모르해제

}

void Media::load_pro_name() // 상품내역 로드
{
	string p_name;
	
	ifstream fin;
	fin.open("proDB.txt");

	while(!fin.eof())
	{
		fin>>p_name;

		Media* Pro = new Media;
		Pro->set_P_name(p_name);

		P_DB[count] = Pro;
		count++;
	}
	fin.close();
}


	

