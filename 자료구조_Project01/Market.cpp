#include "Market.h"

void Market::M_print_product()
{

	cout<<"\t ";
	cout<<left<<setw(30)<<"현재시간(년/원/일 시:분)"

		<<setw(10)
		<<"판매번호 "<<setw(10)
		<<"구매자 ID "<<setw(10)
		<<"상품 ID "<<setw(15)
		<<"상품이름 "<<setw(15)
		<<"제조업자 "<<setw(10)
		<<"상품가격"<<setw(10)
		<<"판매개수 "<<setw(10)
		<<"총 금액 \n\n";
}

void Market::print_product_info()
{
	cout<<"\t "<<setw(10)
		<<left<<setw(10)
		<<"상품번호 "<<setw(15)
		<<"상품이름 "<<setw(10)
		<<"상품가격"<<setw(15)
		<<"제조업자 "<<setw(10)
		<<"재고량 / 주문량 "<<setw(10)
		<<"판매량 "<<setw(10)
		<<"수익금 "<<"\n\n";
}

int Market::EnProduct() //상품 등록
{
	int pro_id;
	int pro_price;
	string pro_name;
	string Manu_Name;
	int check=0;

	cout<<"\n\t ┌────────┐ ";
	cout<<"\n\t │    상품등록    │ ";
	cout<<"\n\t └────────┘ \n\n";

	cout<<"\t "<<"상품 ID 입력 : "; cin>>pro_id;
	if(check_input())
	{
		cout<<"\t "<<"상품 이름 입력 : "; cin>>pro_name;
		cout<<"\t "<<"제조 업자 입력 : "; cin>>Manu_Name;
		cout<<"\t "<<"상품 가격 입력 : "; cin>>pro_price;
		if(check_input())
		{
			Product a(pro_id,pro_name,Manu_Name,pro_price,0,0);

			if(Pro_list.search(a)==false) // 같은 이름이나 같은 아이디가 없을시.
			{
				Pro_list.Add(a); //해당 item을 추가한다.
				return 1;
			}
			else
				return 0;// 해당이름이나 아이디를 가진게 있을시
		}
		return -1; //잘못된 입력일시.
	}
	return -1; //잘못된 입력일시.

}

int Market::PlusProduct() // 상품입고
{
	Product item;
	int select_num;
	int _product;
	cout<<"\n\t ┌────────┐ ";
	cout<<"\n\t │    상품입고    │ ";
	cout<<"\n\t └────────┘ \n\n";

	print_product_info();
	print_prepro();

	cout<<"\t 입고할 상품의 ID를 입력해 주세요\n";
	cout<<"\t ID : "; cin>>select_num;
	if(check_input())
	{
		Pro_list.ResetItem();

		while(Pro_list.GetNextItem(item) != false)
		{
			if(item.get_product_ID() ==select_num) // 입력한 변수가 아이템의 아이디와 같을시
			{
				cout<<"\n\t 입고할 상품수량을 입력해주세요\n  ";
				cout<<"\t num : "; cin>>_product;
				if(check_input())
				{
					if(item.get_orderproduct_count() >= _product) // 주문량이 입력한 입고량보다 많을때
					{
						item.set_orderproduct_count(item.get_orderproduct_count()-_product); // 주문량 down
						item.set_presentproduct_count(item.get_presentproduct_count()+_product); // 입고량 up
						Pro_list.update(item);
						return 1; //상품 입고가 잘 작동햇을시
					}
					else return -1;	 // 아이디는 같으나 주문량이 부족햇을시
				}
			}
		}
	}
	return 0; //아이디와 같은 상품이 없을때
}

bool Market::orderProduct() //상품 주문
{
	Product item;
	int select_num;
	int _product;

	cout<<"\n\t ┌────────┐ ";
	cout<<"\n\t │    상품주문    │ ";
	cout<<"\n\t └────────┘ \n\n";

	print_product_info();
	print_prepro();

	cout<<"\t 주문할 상품의 ID를 입력해 주세요\n";
	cout<<"\t ID : "; 
	cin>>select_num;

	if(check_input())
	{

		Pro_list.ResetItem();

		while(Pro_list.GetNextItem(item) != false)
		{
			if(item.get_product_ID() ==select_num) // 입력한 변수가 존재할때
			{
				cout<<"\n\t 주문할 상품수량을 입력해주세요\n ";
				cout<<"\t num : ";
				cin>>_product;
				if(check_input())
				{
					item.set_orderproduct_count(item.get_orderproduct_count()+_product); // 주문량 up
					Pro_list.update(item);

					return true; //상품 주문에 성공햇을시
				}
				return false;
			}
		}
	}
	return false; //상품 주문에 실패햇을시
}

int Market::DeleteProduct() // 상품 삭제
{
	Product item;
	int select_num;

	cout<<"\n\t ┌────────┐ ";
	cout<<"\n\t │    상품삭제    │ ";
	cout<<"\n\t └────────┘ \n\n";

	print_product_info();
	print_prepro();

	if(Pro_list.GetLength())
	{
		cout<<"\t 삭제할 상품의 ID를 입력해 주세요\n";
		cout<<"\t ID : "; cin>>select_num;
		if(check_input())
		{
			Pro_list.ResetItem();
			while(Pro_list.GetNextItem(item) != false)
			{
				if(item.get_product_ID() == select_num)
				{
					Pro_list.Delete(item);
					return 1; // 상품 삭제가 성공햇을시
				}
			}
			return 0; //입력은 햇으나 해당 id가 존재하지않음.
		}
		else
			return 0;
	}

	return -1; // 잘못된 입력을 햇을시
}

bool Market::SearchProduct() // 상품 검색
{
	cout<<"\n\t ┌────────┐ ";
	cout<<"\n\t │    상품검색    │ ";
	cout<<"\n\t └────────┘ \n\n";

	Product item;
	ManageProduct item2;
	Media Me;
	string pro_name;
	int count=0;

	cout<<"\t "<<"상품 이름 입력 : "; cin>>pro_name;

	cout<<"\n\n\t <입력한 상품의 정보> \n";
	
	Pro_list.ResetItem();

	while(Pro_list.GetNextItem(item) != false)
	{
		if(item.get_product_name() ==pro_name) // 상품이름이 입력한 이름과 같을시
		{
			item.search_product_info();

			cout<<"\n\n";
			cout<<"\n\t ┌────────┐ ";
			cout<<"\n\t │  상품판매내역  │ ";
			cout<<"\n\t └────────┘ \n\n";

			M_print_product();

			Man_list.ResetItem();

			while(Man_list.GetNextItem(item2) != false)
			{
				if(item2.get_M_product_name() == pro_name)
				{
					count++;
					item2.Print_pro();
					cout<<"\n";
				}

			}
			
			Me.print_Picture(pro_name);

			return true; //상품 검색이 성공적으로 됫을시
		}
	}
	return false; // 상품 검색에 실패햇을때.
}

bool Market::printProduct()
{
	Product item;
	ManageProduct item2;
	cout<<"\n\t < 상품 출력 > \n\n";
	print_product_info();

	print_prepro();

	return true;
}

bool Market::check_input()  ///입력한 변수 예외처리
{
	if(cin.fail())
	{
		cout <<"\n\n\t 잘못 입력하였습니다<숫자만 입력가능>.\n";
		cin.clear();
		cin.ignore(100, '\n');
		Sleep(500);
		return false;
	}
	return true;
}

int Market::sellProduct() //상품 판매
{
	Product item;
	int select_num;
	int modify_number;
	int _product;
	int C_id;

	time_t s_time;

	cout<<"\n\t ┌────────┐ ";
	cout<<"\n\t │    상품 판매   │ ";
	cout<<"\n\t └────────┘ \n\n";

	print_product_info();
	print_prepro();

	cout<<"\t 판매할 상품의 ID를 입력해 주세요\n";
	cout<<"\t ID : "; cin>>select_num;
	check_input();

	Pro_list.ResetItem();

	while(Pro_list.GetNextItem(item) != false)
	{
		if(item.get_product_ID() == select_num) //입력받은 숫자가 상품의 아이디와 같을때
		{
			cout<<"\n\t 판매할 상품수량을 입력해주세요 ";
			cout<<"\n\t num : "; 

			cin>>_product;

			if(check_input())
			{

				if(item.get_presentproduct_count() >= _product) // 입고량이 충분할때
				{
					cout<<"\n\t 구매하시는 회원의 아이디를 입력하세요 \n";
					cout<<"\t ID : ";
					cin>>C_id;

					if(check_input())
					{
						
						item.set_presentproduct_count(item.get_presentproduct_count()-_product); // 입고량 다운
						Pro_list.update(item);
						item.set_Sum_money(_product,item.get_product_price()); // 판매금액 설정
						s_time=clock();// 판매됫을때 시간을 받아옴

						s_Money+=item.get_money(); // 총금액 증가.

						ManageProduct M_list(c_Num,C_id,item.get_product_ID(),item.get_product_name(),item.get_Manufacturet_name(),item.get_product_price(),_product,item.get_money());
						c_Num++; //판매번호 설정

						if(!M_list.check_sell_input(_product,modify_number)) // 만약에 판매량이 잘못됫을 경우
						{
							item.set_presentproduct_count(item.get_presentproduct_count() + (_product-modify_number)); // 환불한수만큼 입고량 증가
							Pro_list.update(item); //item의 입고량 업데이트
							M_list.set_M_order_count(modify_number); // 판매 취소량 설정
							M_list.set_M_product_sales(item.get_product_price()*modify_number); // 판매 수익금 결정
						}

						Man_list.Add(M_list); // 리스트에 추가

						return 1; //상품판매가 성공적으로 이루어졌을때
					}
				}
				else return -1; //입고량이 불충분할때
			}

		}
	}
	return 0; // 해당 ID를 가진 상품이 없을때
}

bool Market::sell_PrintProduct() // 판매목록 출력
{
	ManageProduct item;
	Man_list.ResetItem();

	time_t e_time;
	e_time=time(NULL); // 현재시간 저장

	

	while(Man_list.GetNextItem(item) != false)
	{
		item.set_endTime(e_time);

		if(e_time - item._preTime() > 86400) // 현재시간-판매시간 60초가 판매목록에서 삭제
		{
			Man_list.Delete(item);
			Man_list.ResetItem(); //sorted 리스트이므로 처음으로 돌아간다하더라도 이전에 삭제한 노드 다음걸 가르치게 할수 있다.
		}
	}

	cout<<"\n\t < 판매목록 출력 > \n\n";
	cout<<"\t < 총 수익 > : ";
	cout<<s_Money<<"\n\n";
	M_print_product();

	if(Man_list.print())
		return true;

	return false;
}

int Market::sell_ProductRefund() // 상품 환불
{	
	int C_id; //  고객 id
	int S_id; // 상품판매번호
	int r_count=0; // 환불 상품 목록이 있는지 없는지 체크
	bool check=true; // 입력한 판매상품 번호가 있는지 없는지 체크
	ManageProduct item;

	cout<<"\n\t ┌────────┐ ";
	cout<<"\n\t │    환불하기    │ ";
	cout<<"\n\t └────────┘ \n\n";


	if(sell_PrintProduct()) //판매목록이 잇을시
	{
		cout<<"\n\t 환불을 요청한 회원의 아이디를 입력하세요 \n";
		cout<<"\t ID : ";
		cin>>C_id;
		if(check_input())
		{
			system("cls");

			cout<<"\n\t ┌────────┐ ";
			cout<<"\n\t │  환불가능상품  │ ";
			cout<<"\n\t └────────┘ \n\n";

			Man_list.ResetItem();
			M_print_product();

			while(Man_list.GetNextItem(item) != false)
			{
				if(item.get_M_Custom_Id()== C_id)
				{
					r_count++;
					item.Print_pro();
					cout<<"\n";
				}

			}

			if(r_count==0)
			{
				cout<<"\n\t "<<C_id<<" 님이 환불 가능한 상품이 없습니다 \n";
				return 0;
			}

			cout<<"\n\t 환불할 물품의 판매번호를 입력하세요 \n";
			cout<<"\t Num : ";
			cin>>S_id;
			if(check_input())
			{
				Man_list.ResetItem();

				while(Man_list.GetNextItem(item) != false)
				{
					if(item.get_M_Sell_Number() == S_id)
					{
						s_Money-=item.get_M_product_sales();
						Man_list.Delete(item);
						return 1; // 상품환불이 잘됫을시
					}
					check=false;
				}
			}

		}
		if(!check) return -1; // 입력한 id와 같을게 없을시
	}

	return 0; // 아무것도 없을때
}


int Market::search_M_print_product()
{
	ManageProduct item;

	string name;
	Man_list.ResetItem();
	int count = 0;

	cout<<"\n\t ┌────────┐ ";
	cout<<"\n\t │  판매상품검색  │ ";
	cout<<"\n\t └────────┘ \n\n";

	cout<<"\n\t 검색할 상품의 이름을 입력하세요 \n";
	cout<<"\t 판매상품명 : ";
	cin>>name;
	if(check_input())
	{
		system("cls");

		cout<<"\n\t ┌────────┐ ";
		cout<<"\n\t │  판매상품정보  │ ";
		cout<<"\n\t └────────┘ \n\n";

		M_print_product();

		while(Man_list.GetNextItem(item) != false)
		{
			if(item.get_M_product_name() == name)
			{
				count++;
				item.Print_pro();
				cout<<"\n";
			}

		}

		if(count == 0 ) // 판ㅁ된 상품정보가 없을때
		{
			return -1;
		}
		else
			return 1; // 잘 출력됫을때
	}
	else	
		return 0; // 입력이 잘못됫을때
}

void Market::load_product() // 재고상품 로드
{
	ifstream fin;
	fin.open("product.txt");

	int P_Id;
	int P_Pcount;
	int P_Ocount;
	int P_Price;
	
	string P_ProName;
	string P_MaunName;
	string record;

	while(getline(fin,record)) // 파일 다 읽을때 까지
	{
		stringstream spacing(record);
		spacing >> P_Id >> P_ProName >>P_MaunName>>P_Price >> P_Pcount >> P_Ocount;
		Product a(P_Id,P_ProName,P_MaunName,P_Price,P_Pcount,P_Ocount);
		Pro_list.Add(a); //리스트에 추가
	}

	fin.close();
}

void Market::save_product() //재고상품 리스트 저장
{
	ofstream fout;
	fout.open("product.txt");

	Product item;
	int count = 0;
	int length = Pro_list.GetLength();
	fout.clear();
	Pro_list.ResetItem();
	
	while(Pro_list.GetNextItem(item) != NULL)
	{
		fout<<item.get_product_ID()<<setw(15)<<item.get_product_name()<<setw(15)
			<<item.get_Manufacturet_name()<<setw(10)<<item.get_product_price()<<setw(10)
			<<item.get_presentproduct_count()<<setw(10)<<item.get_orderproduct_count();

		count ++;

		if(count != length) //맨마지막줄일때
			fout<<endl;
	}

	fout.close();
}

void Market::load_sellProduct() //판매 상품 리스트 로드
{
	ifstream fin;
	fin.open("sellproduct.txt");

	string record;
	ManageProduct a;

	int M_sellNum;
	int M_Cus_id;
	int M_Pro_id;
	string M_Pro_name;
	string M_Manu_name;
	int M_pro_price;
	int M_or_count;

	
	time_t M_preTime; //현재시간을 받아옴

	int M_Pro_sales;

	while(getline(fin,record))  //한줄씩 읽음
	{
		stringstream spacing(record);
		spacing >> M_sellNum >> M_Cus_id >> M_Pro_id >> M_Pro_name  >>M_Manu_name >>  M_pro_price >> M_or_count >> M_preTime >> M_Pro_sales;

		ManageProduct a(M_sellNum,M_Cus_id,M_Pro_id,M_Pro_name,M_Manu_name,M_pro_price,M_or_count,M_Pro_sales);
		a.set_preTime(M_preTime);
		Man_list.Add(a);
	}

	fin.close();
}

void Market::save_sellProduct() // 판매 리스트 저장
{
	ofstream fout;
	fout.open("sellproduct.txt");
	ManageProduct item;

	int count = 0;
	int length = Man_list.GetLength();
	fout.clear();

	Man_list.ResetItem(); //리스트 초기화

	time_t e_time;
	e_time=time(NULL); // 현재시간 저장

	while(Man_list.GetNextItem(item) != false)
	{
		if(e_time - item._preTime() > 86400) // 현재시간-판매시간 60초가 판매목록에서 삭제
		{
			Man_list.Delete(item);
			Man_list.ResetItem(); //sorted 리스트이므로 처음으로 돌아간다하더라도 이전에 삭제한 노드 다음걸 가르치게 할수 있다.
		}
	}

	Man_list.ResetItem(); //리스트 초기화

	while(Man_list.GetNextItem(item) != NULL)
	{
		fout<<left<<item.get_M_Sell_Number()<<" "<<item.get_M_Custom_Id()<<" "
			<<item.get_M_product_id()<<" "<<item.get_M_product_name()<<" "
			<<item.get_M_Manufacture_name()<<" "<<item.get_M_product_price()<<" "
			<<item.get_M_order_count()<<" "<<item._preTime()<<" "<<item.get_M_product_sales();

		count ++;

		if(count != length) // 맨마지막 줄일때
			fout<<endl;
	}

	fout.close();
}

void Market::save_endMarket() // 매일의 가계부 저장
{
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


	string str = currentTime+ "가계 정산.txt"; // 현재날짜이름의 가계부를 만든다
	ofstream fout;
	fout.open(str);

	fout<<" 오늘의 날짜 : "<< currentTime <<"\n\n";
	fout<<" 오늘 매장 총 수익  : "<< s_Money << " 원 "<<"\n\n";

	Product item;
	ManageProduct item2;

	int S_m=0;// 각 상품의 수익
	int S_c=0;// 각 상품의 판매량

	Pro_list.ResetItem();

	// 재고 상품과 판매상품의 이름이 같은거를 찾아 수익을 더한다.
	while(Pro_list.GetNextItem(item) != false)
	{
		Man_list.ResetItem();
	
		while(Man_list.GetNextItem(item2) != false) 
		{
			if(item.get_product_name() == item2.get_M_product_name())
			{
				S_m += item2.get_M_product_sales();
				S_c += item2.get_M_order_count();
			}
		}
		fout<<" ┌──────────────────────┐\n";
		fout<<" │ 상품 이름 : " <<left<<setw(31)<<item.get_product_name()<<"│\n";
		fout<<" │ 상품 판매량 : "<<left<<setw(29)<<S_c<<"│\n";
		fout<<" │ 상품 수익 : "<<left<<setw(31)<<S_m<<"│\n";
		fout<<" └──────────────────────┘\n\n";
		S_m=0;
		S_c=0;
	}
	fout.close();
}

		
void Market::print_prepro() // 각상품의 정보를 출력한다,
{
	Product item;
	ManageProduct item2;

	int S_m=0;// 각 상품의 수익
	int S_c=0;// 각 상품의 판매량

	Pro_list.ResetItem();
	
	while(Pro_list.GetNextItem(item) != false)
	{
		Man_list.ResetItem();
	
		while(Man_list.GetNextItem(item2) != false)
		{
			if(item.get_product_name() == item2.get_M_product_name())
			{
				S_m += item2.get_M_product_sales();
				S_c += item2.get_M_order_count();

			}
				
		}
		item.print_preProduct(); //아이템의 정보출력
		cout<<setw(10)<<S_c<<setw(10)<<S_m<<setw(10)<<"\n\n\n"; //상품의 수익금과 판매량을 리턴한다,
		S_m=0;
		S_c=0;
	}
}


void Market::sound_control()
{
	system("cls");
	cout<<"\t ↑ 위쪽 방향키 : Volume UP ! \n";
	cout<<"\t ↓ 아래 방향키 : Volume Down ! \n";
	cout<<"\t ← 왼쪽 방향키 : Stop Music ! \n";
	cout<<"\t → 오른쪽 방향키 : Play Music !\n";

	Media Ma;
	string a="mp3";
	Ma.print_Picture(a);
}



		
		
		



