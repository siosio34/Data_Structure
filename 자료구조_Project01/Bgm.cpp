

#include "Bgm.h"


System* g_pSystem; //System ���� ����
Sound* g_pSound[MAX_SOUND_TRACK];//MAX_SOUND_TRACK�� ����� ���� �ִ밹����
Channel* g_pChannel; // Channel ������ ���� ����.

void Bgm::music_case()
{
	load_music(); // ���� DB�� �ҷ��´�.
	float volume = 0.5; // ó�� ���� ������ 0.5�� �����Ѵ�.
	srand(time(NULL)); // ���� ������ ����.
	string str;
	int num;

	while(1)
	{
		if(_kbhit())
		{
			int key=_getch(); // Ű����κ��� �Է��� �޴´�

			switch(key)
			{
			case 72: // ȭ��ǥ ����Ű
				volume += 0.1f; // ������ �ϳ� ��
				if( volume > 1.0) //�ִ� ������ ������
					volume = 1.0;
				g_pChannel->setVolume(volume); //ä�� ���� ����
				break;
			case 80: //ȭ��ǥ �Ʒ���Ű
				volume -= 0.1f; // ������ �ϳ� �Ʒ�
				if( volume < 0) //���� ������ ������
					volume = 0;
				g_pChannel->setVolume(volume); //ä�� ���� ����
				break;

			case 75: // ���� ȭ��ǥ
				stop_music(); //��������
				break;

			case 77: //  ������ ȭ��ǥ
				num=rand()%music_count;
				play_music(num); //�������
				break;

			}

		}

	}
}

void Bgm::load_music() //���� ��� �ε�
{
	int num=0;
	music_count=0; //���Ǹ���� ����
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

	while(getline(fin,record)) //�ٸ��� �д´�.
	{

		st_num =""; //���ǹ�ȣ
		name=""; //��������
		Artist=""; //��Ƽ��Ʈ

		for(int i=0 ; i<record.size() ; i++)
		{
			if(record[i] == '&' && count ==0) //���ǹ�ȣ ����
			{
				for(k ; k<i ; k++)
				{
					st_num += record[k];
				}
				k=k+1;
				num = std::stoi(st_num);

				count++;
			}

			else if(record[i] == '&' &&count == 1) //�������� ����
			{
				for(k ; k<i ; k++)
				{
					name += record[k];
				}
				count++;
				k=k+1;
			}

			else if(record[i] == '&' && count == 2) //���� ��Ƽ��Ʈ ����
			{
				for(k ; k<i ; k++)
				{
					Artist += record[k];
				}
				count=0;
				k=0;
			}

		}

		Bgm *music = new Bgm; // Bgm �� ���ο� ��ü ����
		music->set_Music_Num(num);
		music->set_Music_Name(name);
		music->set_Music_Artist(Artist);
		Music[music_count]=music;
		music_count ++; // ���� ������ ���� �ϳ��ø�

	}
	fin.close();
}


void Bgm::play_music(int num) //�������
{
	
	stop_music(); //���� ����
	string str;
	str = (Music[num]->get_Music_Name() + ".mp3"); 
	System_Create(&g_pSystem); // ���� �ý��� ����
	g_pSystem->init(1,FMOD_INIT_NORMAL,0); // 1�� ¥�� ä���� ����
	g_pSystem->createSound(str.c_str(),FMOD_HARDWARE,0,&g_pSound[0]); //��� ������ �ִ� ����� ���� ������ g_pSound�� ����
	g_pSystem->playSound(FMOD_CHANNEL_FREE,g_pSound[0],0,&g_pChannel); //�ƹ� ä���̳� ��� g_pSound[0]�� ����ִ� �뷡�� ���


}

void Bgm::stop_music() // �뷡�� ����
{
	g_pSystem->release(); // �뷡 �޸���ü
	g_pSystem->close();   // �ý��� �ݱ�
}











