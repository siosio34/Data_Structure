/**
*	@mainpage	Project_03 ���¼ҽ�(boost::thread,opencv,FMOD)�� �̿��� ���� ������ ���α׷� 
*				
*				Project_03 - MarketSystem ���α׷�
*				 1: DoublySortedLinkedList ����Ʈ�� ���뼺�� ���̱� ���� template �� ����Ͽ���(� Ŭ���� Ÿ�Կ� ����� �� �ִ�)..<br>
*				 2: itemType(Product,ManageProduct)�� ��ü�� ��.�������� �ϱ� ���ؼ� ItemType(Product) Ŭ������ ������ �����ε��� ����Ͽ���.<br>
*				 3: �ǸŸ�� ������ �� ȿ�������� �ϱ����� ManageProduct ����� �ϳ� ���� ����� �־���.<br>
*				 4: ������ Ŭ�������� Product,ManageProduct Ŭ���� �� ���� Market Ŭ���� �� ���� Market Ŭ�������� �Լ��� �ҷ��� ����ϴ� Application Ŭ������ �̷���� �ִ�.<br>
*                5. SortedLinked�� �ֿ� ����� Add,Delete,Search,update,Print ���� �ִ�.<br>
*				 6: ��ǰ��� ������ 1.��ǰ��� 2.��ǰ�԰� 3.��ǰ�ֹ� 4.��ǰ���� 5.��ǰ�˻� 6.��� ��ǰ��� ����� �ִ�.<br>
*				 7: ��ǰ�Ǹ� ������ 1.��ǰ�Ǹ� 2.��ǰ�ǸŸ����� 3.ȯ���ϱ� 4.�Ǹ� ��ǰ �˻��� �ִ�.<br>
*                8. Product Ŭ�������� ��ǰ������ set,get�ϰ� ��ǰ ������ �����ϴ� �Լ� ������ �����ε��� ���ǵǾ��մ�.<br>
*				 9: ManageProduct Ŭ�������� ��ǰ������ set,get�ϰ� �ǸŻ�ǰ������ �����ϴ� �Լ� ������ �����ε��� ���ǵǾ��մ�.<br>
*                10. Market Ŭ���������� �⺻ ���� �ý��ۿ��� �ʿ��� �ֿ� ��ɵ��� �����Ǿ� �ִ�.<br>
*                11. Application Ŭ���������� ���Ͻý��ۿ��� �ҷ��� �Լ����� �̿��� ����ó���� ���ְ� �������̽��� ȣ���Ѵ�.<br>
*				 12. Bgm Ŭ�������� FMOD�� ����� ������� ���,���� ���ٿ�,������� ����� �� �ִ�.<br>
*				 13. Media Ŭ�������� opencv�� ����� ��ǰ�� ������ �������� ���� ��ɰ� CCTV ����� �� �ִ�.<br>
*				 14. boost ���̺귯���� �߰��Ͽ� �� �ȿ� �ִ� �����带 �̿��Ͽ� �������� �Լ��� ���� �� �ֵ��� �Ͽ���. <br>
*				 15. ������Ʈ03 �� �߰� �⺻ ����� ����ǰ�� �Ǹ� ��� ���,�Ǹ� ��ǰ�� �˻��� �����Ͽ���. <br>
*	
*	@date	2014.12.04 
*	@author	������ 
*/

#include "Application.h"
#include "Market.h"
#include "Product.h"
#include "DoublySortedLinkedList.h"
#include "Bgm.h"
#include "Media.h"
#include <boost/thread.hpp>
#include <boost/bind.hpp>

int main()
{
	
	system("mode con:cols=150 lines=40"); // �ܼ�ũ��Ű���

	AppliCation app; /// ���ø����̼� ��ü���� 
	Bgm bgm; // Bgm ��ü ���� (FMOD ���� �ҽ� ��� , ������� ���� ���)
	Media op; // �̵�� ��ü ���� (opencv ���� �ҽ� ��� , CCTV ���� ���)

	boost::thread th1(boost::bind(&AppliCation::print_Start,app)); // ������ ù��° ��ü ����
	boost::thread th2(boost::bind(&Bgm::music_case,bgm)); // ������ �ι�° ��ü ����
	boost::thread th3(boost::bind(&Media::On_Capture,op)); // ������ ����° ��ü ����

	th1.join(); // ������ 1 ����
	th2.join(); // ������ 2 ����
	th3.join(); // ������ 3 ����
	
	return 0;
}