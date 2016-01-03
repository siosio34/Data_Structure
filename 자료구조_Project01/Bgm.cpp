

#include "Bgm.h"


System* g_pSystem; //System 변수 생성
Sound* g_pSound[MAX_SOUND_TRACK];//MAX_SOUND_TRACK는 사용할 음악 최대갯수다
Channel* g_pChannel; // Channel 포인터 변수 생성.

void Bgm::music_case()
{
	load_music(); // 음악 DB를 불러온다.
	float volume = 0.5; // 처음 볼륨 설정은 0.5로 설정한다.
	srand(time(NULL)); // 난수 설정을 위함.
	string str;
	int num;

	while(1)
	{
		if(_kbhit())
		{
			int key=_getch(); // 키보드로부터 입력을 받는다

			switch(key)
			{
			case 72: // 화살표 위쪽키
				volume += 0.1f; // 음량을 하나 위
				if( volume > 1.0) //최대 음량을 넘을시
					volume = 1.0;
				g_pChannel->setVolume(volume); //채널 음량 설정
				break;
			case 80: //화살표 아래쪽키
				volume -= 0.1f; // 음량을 하나 아래
				if( volume < 0) //최저 음량을 넘을시
					volume = 0;
				g_pChannel->setVolume(volume); //채널 음량 설정
				break;

			case 75: // 왼쪽 화살표
				stop_music(); //음악중지
				break;

			case 77: //  오른쪽 화살표
				num=rand()%music_count;
				play_music(num); //음악재생
				break;

			}

		}

	}
}

void Bgm::load_music() //음악 목록 로드
{
	int num=0;
	music_count=0; //음악목록의 개수
	string st_num;
	string name;
	string Artist;
	ifstream fin;
	fin.open("SoundDB.txt");

	string record;
	string a="";
	char ch=0;

	int count=0;
	int k=0;

	while(getline(fin,record)) //줄마다 읽는다.
	{

		st_num =""; //음악번호
		name=""; //음악제목
		Artist=""; //아티스트

		for(int i=0 ; i<record.size() ; i++)
		{
			if(record[i] == '&' && count ==0) //음악번호 설정
			{
				for(k ; k<i ; k++)
				{
					st_num += record[k];
				}
				k=k+1;
				num = std::stoi(st_num);

				count++;
			}

			else if(record[i] == '&' &&count == 1) //음악제목 설정
			{
				for(k ; k<i ; k++)
				{
					name += record[k];
				}
				count++;
				k=k+1;
			}

			else if(record[i] == '&' && count == 2) //음악 아티스트 설정
			{
				for(k ; k<i ; k++)
				{
					Artist += record[k];
				}
				count=0;
				k=0;
			}

		}

		Bgm *music = new Bgm; // Bgm 의 새로운 객체 생성
		music->set_Music_Num(num);
		music->set_Music_Name(name);
		music->set_Music_Artist(Artist);
		Music[music_count]=music;
		music_count ++; // 음악 저장목록 개수 하나늘림

	}
	fin.close();
}


void Bgm::play_music(int num) //음악재생
{
	
	stop_music(); //음악 멈춤
	string str;
	str = (Music[num]->get_Music_Name() + ".mp3"); 
	System_Create(&g_pSystem); // 음악 시스템 생성
	g_pSystem->init(1,FMOD_INIT_NORMAL,0); // 1개 짜리 채널을 생성
	g_pSystem->createSound(str.c_str(),FMOD_HARDWARE,0,&g_pSound[0]); //디비가 가지고 있는 제목과 같은 음악을 g_pSound에 복사
	g_pSystem->playSound(FMOD_CHANNEL_FREE,g_pSound[0],0,&g_pChannel); //아무 채널이나 골라 g_pSound[0]에 들어있는 노래를 재생


}

void Bgm::stop_music() // 노래를 정지
{
	g_pSystem->release(); // 노래 메모리해체
	g_pSystem->close();   // 시스템 닫기
}











