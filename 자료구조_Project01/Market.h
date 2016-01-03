#pragma once
#include <fstream>
#include <sstream>
#include "Product.h"
#include "ManageProduct.h"
#include "DoublySortedLinkedList.h"
#include "Media.h"

/**===========================================Market 클래스===========================================================================================
*	@author 조영제
*	@date 2014/10/14
*	@brief Market 클래스( Product의 상위클래스 ) - 마켓의 기본기능을 구현하는 클래스
*	@details 상품 등록, 상품 입고, 상품 주문, 상품 판매, 상품 삭제, 상품 검색, 등록 상품 출력,상품판매,판매목록출력,상품환불 등의 기능이 구현되어 있다.
*======================================================================================================================================================*/
class Market
{
public:
	Market(){s_Money=0,c_Num=0; load_product(); load_sellProduct(); ;}
	~Market(){save_product(); save_sellProduct(); save_endMarket(); };

	/**===========================================================================================================
	*	새로운 상품 등록을 하는 함수이다
	*	@brief	중복상품을 검색한 뒤 중복된게 없으면 새로운 상품을 등록하게 된다.
	*	@pre	아이템의 정보가 입력 되어 있어야한다.
	*	@post	새로운 상품이 등록되게 된다.
	*	@return	상품 등록이 성공하면 true를 리턴 성공하지 않으면 false를 리턴한다
	=============================================================================================================*/
	int EnProduct(); /// 상품 등록 (새로운 상품 등록)

	/**===========================================================================================================
	*	상품를 입고를 하는 하는 함수이다 ( 잔고량 갯수 증가 )
	*	@brief	입력한 id를 가진 아이템이 있을시 상품 갯수를 증가하게 된다.
	*	@pre	입고하고자 하는 양이 기존에 있던 주문량보다 적어야 된다.
	*	@post	기존 상품의 갯수가 올라가고 주문량의 갯수가 줄어들게 된다.
	*	@return	상품 등록이 성공하면 1을 입력한 상품의 아이디가 없을땐 0 상품 갯수가 충분하지 않으면 -1을 리턴한다. 
	==============================================================================================================*/
	int PlusProduct(); /// 상품 입고(상품 잔고개수 증가 주문량 감소)

	/**=============================================================================================================
	*	상품을 주문하는 함수이다 ( 주문량 갯수 증가 )
	*	@brief	입력한 id를 가진 아이템이 있을시 상품 주문량이 증가하게 된다.
	*	@pre	주문하고자 하는 숫자가 입력되어 있어야 된다.
	*	@post	주문량의 갯수가 늘어나게 된다.
	*	@return	상품주문이 성공하면 ture을 그렇지 않으면 false를 리턴하게 된다.
	================================================================================================================*/
	bool orderProduct();/// 상품 주문(주문량 증가) 

	/**===============================================================================================================
	*	기존 상품을 삭제하는 함수이다 
	*	@brief	입력한 id를 가진 아이템이 있을시 해당 상품이 삭제되게 된다.
	*	@pre	삭제하고자 하는 ID를 가진 정보가 있어야 된다.
	*	@post	해당 상품이 삭제되게 된다.
	*	@return	상품삭제가 성공하면 true을 그렇지 않으면 false를 리턴하게 된다.
	==================================================================================================================*/
	int DeleteProduct(); /// 상품 삭제 

	/**================================================================================================================
	*	기존 상품을 검색하는 함수이다 
	*	@brief	입력한 이름을 가진 상품 정보 존재 유무와 정보를 리턴하게 된다.
	*	@pre	검색하고자 하는 ID를 가진 정보가 있어야 된다.
	*	@post	해당 상품정보가 출력되게 된다.
	*	@return	상품검색이 성공하면 true을 그렇지 않으면 false를 리턴하게 된다.
	==================================================================================================================*/
	bool SearchProduct(); /// 상품 검색 (입력한 상품 정보 출력)

	/**================================================================================================================
	*	기존 상품을 출력하는 함수이다 
	*	@brief	상품 전체 정보를 출력하게 된다.
	*	@pre	기존 데이터에 정보가 있어야 된다.
	*	@post	전체 상품정보가 출력되게 된다.
	*	@return	상품출력이 성공하면 true을 그렇지 않으면 false를 리턴하게 된다.
	===================================================================================================================*/
	bool printProduct(); /// 등록 상품 출력 (상품 전체 목록 출력)

	/**================================================================================================================
	*	상품을 판매하는 함수이다 
	*	@brief	상품을 판매하는 함수이다.
	*	@pre	기존 데이터에 정보가 있어야 된다.
	*	@post	상품이 판매되게 되고 수익금이 올라가게 된다.
	*	@return	상품판매에 성공하면 1을 아무도 판매할게 없으면 0을 판매개수를 잘못입력햇으면 -1을 리턴하게 된다.
	===================================================================================================================*/
	int sellProduct(); /// 상품 판매(상품 잔고개수 감소)

	/**================================================================================================================
	*	상품을 판매목록을 출력하는 함수
	*	@brief	상품을 판매목록을 출력하는 함수.
	*	@pre	기존 데이터에 정보가 있어야 된다.
	*	@post	상품목록을 출력하게된다.
	*	@return	상품판매에 성공하면 true를 아니면 false 를 리턴하게된다.
	===================================================================================================================*/
	bool sell_PrintProduct();/// 상품 판매목록 출력

	/**================================================================================================================
	*	상품을 환불하는 함수이다 
	*	@brief	상품을 환불하는 함수이다.
	*	@pre	기존 데이터에 정보가 있어야 된다.
	*	@post	상품이 환불되게 되고 수익금이 감소하게 된다.
	*	@return	상품환불에 성공하면 1을 아무도 환불할게 없으면 0을 환불 번호를잘못입력햇으면 -1을 리턴하게 된다.
	===================================================================================================================*/
	int sell_ProductRefund(); /// 상품 환불

	/***==========================================================================================================================
	*	@brief	Product 가 가지고 있는 정보가 무엇을 의미하는지 알려주는 함수이다.
	*	@pre	없다.
	*	@post	Product 가 가지고 있는 정보가 보여진다.
	*============================================================================================================================*/
	void print_product_info();

	/***==========================================================================================================================
	*	@brief	ManageProduct가 가지고 있는 정보가 무엇을 의미하는지 알려주는 함수이다.
	*	@pre	없다.
	*	@post	ManageProduct 가 가지고 있는 정보가 보여진다.
	*============================================================================================================================*/
	void M_print_product();

	/***==========================================================================================================================
	*	@brief	키보드로 입력받은 변수가 조건에 맞는지 확인하는 함수이다.
	*	@pre	키보드로 입력을 받아야된다
	*	@post	입력을 받은게 잘되는지 아닌지 확인하고 그거에 따른 결고를 출력한다
	*   @return 잘못입력햇을시 false를 리턴 제대로 입력햇을시 true를 리턴하게 된다.
	*============================================================================================================================*/
	bool check_input();  ///입력한 변수 예외처리

	/**===========================================================================================================
	*	재고상품 DB를 불러와서 리스트에 저장하는 함수이다
	*	@brief	재고 상품 리스트에 DB에 있는 내용을 넣게된다.
	*	@pre	재고상품 디비가 존재해야된다,
	*	@post	DB에 있는 재고상품 리스트가 옮겨 저장되게 된다.
	=============================================================================================================*/
	void load_product();

	/**===========================================================================================================
	*	재고상품 리스트를 불러와서 DB 저장하는 함수이다
	*	@brief	재고상품 리스트를 불러와서 DB 저장하게 하는 함수이다.
	*	@pre	재고상품 리스트가 존재해야된다,
	*	@post	재고상품 리스트를 불러와서 DB 저장하게 된다.
	=============================================================================================================*/
	void save_product();

	/**===========================================================================================================
	*	판매상품 DB를 불러와서 리스트에 저장하는 함수이다
	*	@brief	판매상품 리스트에 DB에 있는 내용을 넣게된다.
	*	@pre	판매상품 디비가 존재해야된다,
	*	@post	DB에 있는 판매상품 리스트가 옮겨 저장되게 된다.
	=============================================================================================================*/
	void load_sellProduct();

	/**===========================================================================================================
	*	판매상품 리스트를 불러와서 DB 저장하는 함수이다
	*	@brief	판매상품 리스트를 불러와서 DB 저장하게 하는 함수이다.
	*	@pre	판매상품 리스트가 존재해야된다,
	*	@post	판매상품 리스트를 불러와서 DB 저장하게 된다.
	=============================================================================================================*/
	void save_sellProduct();

	
	/**===========================================================================================================
	*	매일의 각 상품의 판매량과 이익을 텍스트에 저장하는 함수이다
	*	@brief	매일의 각 상품의 판매량과 이익을 텍스트에 저장하는 함수이다
	*	@pre	없다.
	*	@post	매일의 가계부를 저장하게 된다.
	=============================================================================================================*/
	void save_endMarket();
	
	/**================================================================================================================
	*	판매 상품을 검색하는 함수이다 
	*	@brief	판매 상품을 검색하는 함수이다 
	*	@pre	검색할 상품의 이름이 입력되어야 한다.
	*	@post	판매된 상품의 내역이 다뜨게 된다.
	*	@return	상품판매에 성공하면 1을 아무도 판매된게 없으면 0을 판매개수를 잘못입력햇으면 -1을 리턴하게 된다.
	===================================================================================================================*/
	int search_M_print_product();

	/**================================================================================================================
	*	상품의 정보를 출력하는 함수이다.
	*	@brief	상품의 정보를 출력하는 함수이다.
	*	@pre	없다.
	*	@post	상품의 정보가 출력되게된다.
	===================================================================================================================*/
	void print_prepro();

	void sound_control();
	

	
private:
	DoublySortedLinkedList<Product> Pro_list; /// < Product의 DoublySortedLinkedList
	DoublySortedLinkedList<ManageProduct> Man_list;/// < ManageProduct의 DoublySortedLinkedList
	
	int s_Money; /// 돈의 합계
	int c_Num; /// 판매번호
	
};

