/**
*	@mainpage	Project_03 오픈소스(boost::thread,opencv,FMOD)을 이용한 마켓 관리자 프로그램 
*				
*				Project_03 - MarketSystem 프로그램
*				 1: DoublySortedLinkedList 리스트의 재사용성을 높이기 위해 template 을 사용하였다(어떤 클래스 타입에 사용할 수 있다)..<br>
*				 2: itemType(Product,ManageProduct)의 객체를 비교.값전달을 하기 위해서 ItemType(Product) 클래스에 연산자 오버로딩을 사용하였다.<br>
*				 3: 판매목록 관리를 더 효율적으로 하기위해 ManageProduct 헤더를 하나 새로 만들어 주었다.<br>
*				 4: 최하위 클래스에는 Product,ManageProduct 클래스 그 위엔 Market 클래스 그 위엔 Market 클래스에서 함수를 불러와 사용하는 Application 클래스로 이루어져 있다.<br>
*                5. SortedLinked의 주요 기능은 Add,Delete,Search,update,Print 등이 있다.<br>
*				 6: 상품목록 관리는 1.상품등록 2.상품입고 3.상품주문 4.상품삭제 5.상품검색 6.등록 상품목록 출력이 있다.<br>
*				 7: 상품판매 관리는 1.상품판매 2.상품판매목록출력 3.환불하기 4.판매 상품 검색이 있다.<br>
*                8. Product 클래스에는 상품정보를 set,get하고 상품 정보를 관리하는 함수 연산자 오버로딩이 정의되어잇다.<br>
*				 9: ManageProduct 클래스에는 상품정보를 set,get하고 판매상품정보를 관리하는 함수 연산자 오버로딩이 정의되어잇다.<br>
*                10. Market 클래스에서는 기본 마켓 시스템에서 필요한 주요 기능들이 구현되어 있다.<br>
*                11. Application 클래스에서는 마켓시스템에서 불러온 함수들을 이용해 예외처리를 해주고 인터페이스를 호출한다.<br>
*				 12. Bgm 클래스에는 FMOD를 사용한 배경음악 재생,볼륨 업다운,재생정지 기능이 들어가 있다.<br>
*				 13. Media 클래스에는 opencv를 사용한 상품의 정보를 사진으로 띄우는 기능과 CCTV 기능이 들어가 있다.<br>
*				 14. boost 라이브러리를 추가하여 그 안에 있는 쓰레드를 이용하여 여러개의 함수를 돌릴 수 있도록 하였다. <br>
*				 15. 프로젝트03 의 추가 기본 기능인 재고상품의 판매 기록 출력,판매 상품의 검색을 구현하였다. <br>
*	
*	@date	2014.12.04 
*	@author	조영제 
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
	
	system("mode con:cols=150 lines=40"); // 콘솔크기키우기

	AppliCation app; /// 어플리케이션 객체선언 
	Bgm bgm; // Bgm 객체 선언 (FMOD 오픈 소스 사용 , 배경음악 관련 기능)
	Media op; // 미디어 객체 선언 (opencv 오픈 소스 사용 , CCTV 관련 기능)

	boost::thread th1(boost::bind(&AppliCation::print_Start,app)); // 쓰레드 첫번째 객체 선언
	boost::thread th2(boost::bind(&Bgm::music_case,bgm)); // 쓰레드 두번째 객체 선언
	boost::thread th3(boost::bind(&Media::On_Capture,op)); // 쓰레드 세번째 객체 선언

	th1.join(); // 쓰레드 1 실행
	th2.join(); // 쓰레드 2 실행
	th3.join(); // 쓰레드 3 실행
	
	return 0;
}