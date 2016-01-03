#include "Media.h"



void Media::print_Picture(string name) // ������������Լ�
{
	load_pro_name();
	string str;
	bool check =false;
	for(int i=0 ; i< count ; i++)
	{
		if(P_DB[i]->get_P_name() == name)
		{
			 str = name +".png"; //������ Ȯ���ڱ��� �����´�
			 check=true;
			 break;
		}
	
	}
	if(check == true)// DB�� ������������
	{

	IplImage *pEviMonitor; //��������
	pEviMonitor = cvLoadImage(str.c_str()); //�̹����ε�

	cvShowImage(name.c_str(),pEviMonitor); //�̹��� ���

	waitKey(0); //�Է¹��������� ��ٸ�

	cvReleaseImage(&pEviMonitor);
	cvDestroyWindow(name.c_str());
	}
	else //���������� ������
	{
		cout<<"\n\t �ش� ��ǰ�� ���� ������ ���� �����ʽ��ϴ� \n ";
		system("pause");
	}

}

void Media::On_Capture() // CCTV����� �����ϴ� �Լ��̴�.
{
	IplImage * ori_ori = NULL; //���� �̹��� ���� ����
	IplImage * ori = NULL; //ũ�⸦ ������ �̹��� ���� ����
	CvCapture *capture = cvCaptureFromCAM(0); //ķ�� ������ �޾ƿ´�.

	CvVideoWriter* videoOut = NULL; //������ ������ ���� ����
	
	time_t _c_time; 
    _c_time = time(NULL);

	 struct tm *t;
	 t=localtime(&_c_time);

	 string currentTime;

	 int year, month, day, hour, min;
	 int buf;
	 char target[10];
	 
   //����ð��� �������ش�.
	year = t->tm_year+1900;
	month = t->tm_mon+1;
	day = t->tm_mday;
	hour = t->tm_hour;
	min = t->tm_min;

	buf=year;
	itoa(buf,target,10);
	currentTime.append(target);

	currentTime.append("�� ");

	buf=month;
	itoa(buf,target,10);
	currentTime.append(target);

	currentTime.append("�� ");

	buf=day;
	
	itoa(buf,target,10);
	currentTime.append(target);

	currentTime.append("�� ");


	string str = currentTime+ "CCTV.avi"; //���糯¥ +CCTV �� ȭ�� �̸�����
	
	cvNamedWindow(str.c_str(),1); //���糯¥ +CCTV �� ȭ�� �̸�����
	
	while(1)
	{
		cvGrabFrame(capture); //ĸ�ĵ� ������ �޾ƿ�
		ori_ori = cvRetrieveFrame(capture); //���� �̹���
		ori = cvCreateImage(cvSize(400,200),IPL_DEPTH_8U,3); //�̹��� ����
		cvResize(ori_ori,ori,CV_INTER_LINEAR); //ũ�� ���

		
			if( videoOut == NULL) // ���� ������ �ƹ������� ������
			{
				videoOut = cvCreateVideoWriter(str.c_str(),-1,30,cvGetSize(ori),1);
				//������ü�� ����� ��������
			}
			
			cvWriteFrame(videoOut,ori);//����ؼ� ��������
			
		cvShowImage(str.c_str(),ori); //��ķ ���� ���

		if(cvWaitKey(33)>=27) // ESC�� �Էµɶ�����
			break;

		cvReleaseImage(&ori); // �޸�����
	}

	cvReleaseVideoWriter(&videoOut); //���� ��ü �޸�����
	cvDestroyWindow(str.c_str()); //������ ���� �ݱ�

	cvReleaseCapture(&capture); // ķó���� �޸�����

}

void Media::load_pro_name() // ��ǰ���� �ε�
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


	

