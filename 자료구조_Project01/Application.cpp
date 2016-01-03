#include "Application.h"

void AppliCation::print_Start() ///시작메뉴
{
	
	while(1)
	{
		check=true;
		int Command=get_Command();

		if(Command == 1)/// Command가 1일시 상품관리메뉴를 출력한다.
		{
			while(check)
			{
				system("cls");
				switch(print_product_menu())
				{
				case 1: // 상품 등록
					system("cls");
					AppEnProduct();
					break;
				case 2: // 상품 입고
					system("cls");
					AppPlusProduct();
					break;
				case 3: // 상품 주문
					system("cls");
					ApporderProduct();
					break;
				case 4: // 상품 삭제
					system("cls");
					AppDeleteProduct();
					break;
				case 5:// 상품 검색
					system("cls");
					AppSearchProduct();
					break;
				case 6: // 상품 출력
					system("cls");
					AppprintProduct();
					break;
				case 0: // 뒤로가기
					check=false;
					break;
				default : // 잘못 입력했을시
					print_error();
					break;

				}	
			}
		}


		else if(Command == 2) // Command가 2일시 판매관리메뉴를 출력한다.
		{
			while(check)
			{
				system("cls");
				switch(sell_product_menu())
				{
				case 1: // 상품 판매
					system("cls");
					AppsellProduct();
					break;
				case 2: // 상품 판매목록 출력
					system("cls");
					Appsell_printProduct();
					break;
				case 3: // 상품 환불
					system("cls");
					Appsell_refundProduct();
					break;
				case 4:
					system("cls");
					Appsearch_sell_product();
					break;
				case 0: // 뒤로가기
					check=false;
					break;
				default: // 잘못입력햇을시
					print_error();
					break;
				}

			}
		}
		else if(Command == 3)
		{
			market.sound_control();

		}
		else if(Command ==4)
			break;
		
	}	
	return ;
}

int AppliCation::get_Command() // 인터페이스 출력 및 키보드로부터 명령을 리턴함
{
	system("cls");
	cout<<"\n\t\t 영제's Market \n";
	cout<<"\t┌──────────────┐\n";
	cout<<"\t│  메뉴                      │\n";
	cout<<"\t│                            │\n";
	cout<<"\t│    1.상품 관리             │\n";
	cout<<"\t│    2.판매 목록관리         │\n";
	cout<<"\t│    3.매장 음악관리         │\n";
	cout<<"\t│    4.종료                  │\n";
	cout<<"\t│                            │\n";
	cout<<"\t└──────────────┘\n";

	cout<<"\t 메뉴 입력 : "; 
	cin>>input_Command;
	market.check_input();

	return input_Command;
}

int AppliCation::print_product_menu() // 인터페이스 출력 및 키보드로부터 명령을 리턴함
{
	while(1)
	{
		cout<<"\n\t\t 영제's Market \n";
		cout<<"\t┌──────────────┐\n";
		cout<<"\t│  상품메뉴                  │\n";     
		cout<<"\t│                            │\n";		
		cout<<"\t│ 1.  상품 등록              │\n";
		cout<<"\t│ 2.  상품 입고              │\n";
		cout<<"\t│ 3.  상품 주문              │\n";
		cout<<"\t│ 4.  상품 삭제              │\n";
		cout<<"\t│ 5.  상품 검색              │\n";
		cout<<"\t│ 6.  등록 상품 출력         │\n";
		cout<<"\t│ 0.  이전 메뉴로            │\n";
		cout<<"\t│                            │\n";
		cout<<"\t└──────────────┘\n";

		cout<<"\t 메뉴 입력 : "; 
		cin>>input_Command;

		if(market.check_input())
		 return input_Command;

		system("cls");
	}
}
int AppliCation::sell_product_menu() // 인터페이스 출력 및 키보드로부터 명령을 리턴함
{
	while(1)
	{
		cout<<"\n\t\t 영제's Market \n";
		cout<<"\t┌──────────────┐\n";
		cout<<"\t│  판매관리메뉴              │\n";     
		cout<<"\t│                            │\n";	
		cout<<"\t│ 1.  상품 판매              │\n";
		cout<<"\t│ 2.  상품 판매목록 출력     │\n";
		cout<<"\t│ 3.  상품 반품              │\n";
		cout<<"\t│ 4.  상품 판매목록 검색     │\n";
		cout<<"\t│ 0.  이전 메뉴로            │\n";
		cout<<"\t│                            │\n";
		cout<<"\t└──────────────┘\n";

		cout<<"\t 메뉴 입력 : "; 
		cin>>input_Command;
	
	
		if(market.check_input())
		return input_Command;
		
		system("cls");
	}
	
}

void AppliCation::AppEnProduct() //상품등록
{
	int check=market.EnProduct(); //마켓의 함수를 불러옴

	if(check==0) cout<<"\n\t등록하려는 상품이 이미 있습니다 \n";
	else if(check==-1) cout<<"\n\t < 상품 등록 실패 >-잘못된 입력! \n";
	else cout<<"\n\n\t <상품 등록이 성공적으로 처리되었습니다> \n";

	system("pause");

}

void AppliCation::AppPlusProduct() // 상품 입고
{
	int check=market.PlusProduct(); //마켓의 함수를 불러옴

	if(check==0) cout<<"\n\t<상품 입고 실패>-잘못된 입력! \n";
	else if(check==-1) cout<<"\n\t 입고할려는 상품이 주문량이 충분하지 않습니다 \n";
	else cout<<"\n\n\t <상품 입고가 성공적으로 처리되었습니다> \n";

	system("pause");

}

void AppliCation::ApporderProduct() // 상품 주문
{
	bool check=market.orderProduct(); //마켓의 함수를 불러옴

	if(check==false) cout<<"\n\t<상품 주문 실패>-잘못된 입력! \n";	
	else cout<<"\n\n\t <상품 주문이 성공적으로 처리되었습니다> \n";

	system("pause");

}

void AppliCation::AppsellProduct() //상품 판매
{
	int check=market.sellProduct(); //마켓의 함수를 불러옴

	if(check==false) cout<<"\n\n\t<상품 판매 실패>-잘못된 입력!"<<endl;
	else if(check==-1) cout<<"\n\t <상품 수량 부족> ! \n " ;
	else cout<<"\n\n\t <상품 판매가 성공적으로 처리되었습니다> \n"; 

	system("pause");
}

void AppliCation::AppDeleteProduct() // 상품 삭제
{
	int check=market.DeleteProduct(); //마켓의 함수를 불러옴

	if(check==-1) cout<<"\n\n\t <현재 상품 정보 없음 > "<<endl;
	else if(check==0) cout<<"\n\n\t입력하신 ID를 가진 상품이 존재하지 않습니다 !"<<endl;
	else cout<<"\n\n\t <상품 삭제가 성공적으로 처리되었습니다> \n"; 

	system("pause");
}

void AppliCation::AppSearchProduct() // 상품 검색
{
	bool check=market.SearchProduct(); //마켓의 함수를 불러옴

	if(check==false) cout<<"\n\t입력하신 물품은 이 마트에 존재하지 않습니다 !"<<endl;
	else cout<<"\n\n\t <상품 검색이 성공적으로 처리되었습니다> \n";

	system("pause");
}

void AppliCation::AppprintProduct() // 상품 출력
{
	bool check=market.printProduct(); //마켓의 함수를 불러옴

	if(check==false) cout<<"\n\t 등록된 물품이 마트에 존재하지 않습니다 !" <<endl;
	else cout<<"\n\n\t <상품목록 출력이 성공적으로 처리되었습니다> \n";

	system("pause");
}

void AppliCation::Appsell_printProduct() //상품 판매
{
	bool check;
	check=market.sell_PrintProduct(); //마켓의 함수를 불러옴

	if(check==false) cout<<"\n\t 판매된 물품이 마트에 존재하지 않습니다 " <<endl;
	else cout<<"\n\n\t <상품판매 출력이 성공적으로 처리되었습니다> \n";

	system("pause");
}

void AppliCation::Appsell_refundProduct() // 상품 환불
{
	int check;

	check=market.sell_ProductRefund(); //마켓의 함수를 불러옴

	if(check==0) cout<<"\n\t <상품 환불 실패>-잘못된 입력!. \n";
	else if(check==-1) cout<<"\n\t 상품 번호를 잘못 입력하셧습니다. \n";
	else cout<<"\n\n\t <상품 환불이 성공적으로 처리되었습니다> \n";

	system("pause");

}

void AppliCation::Appsearch_sell_product() // 상품 판매목록 검색
{
	int check;

	check=market.search_M_print_product(); //마켓의 함수를 불러옴

	if(check==0) cout<<"\n\t < 판매 상품 검색 실패 > - 잘못된 입력 !. \n";
	else if(check==-1) cout<<"\n\t 판매된 상품이 없습니다 \n";
	else cout<<"\n\n\t < 판매 상품 검색이 성공적으로 처리 되었습니다 >\n";

	system("pause");
}






