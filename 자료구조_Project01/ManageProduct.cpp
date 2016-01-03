#include "ManageProduct.h"

ManageProduct::ManageProduct() // ManageProductd의 생성자
{
	M_Sell_Number=0;
	Custom_id=0;
	M_Product_sales=0;
	M_product_price=0;
	M_order_count=0;
	M_product_id=0;
	M_product_name="";
	M_manufacture_name="";
}

//매개변수가 있는 ManageProductd의 생성자
ManageProduct::ManageProduct(int _M_Sell_Number,int _Custom_id,int _M_product_id,string _M_product_name,string _M_manufacture_name,int _M_product_price,int _M_order_count,int _sum)
{
	M_Sell_Number=_M_Sell_Number;
	Custom_id=_Custom_id;
	M_product_id=_M_product_id;
	M_product_name=_M_product_name;
	M_manufacture_name=_M_manufacture_name;
	M_product_price=_M_product_price;
	M_order_count=_M_order_count;
	pre_time=get_preTime();
	M_Product_sales=_sum;
}

// << 연산자 오버로딩
ostream& operator << (ostream &os1, ManageProduct &item)
{


	item.Print_pro();
	
	return os1;
}

// = 연산자 오버로딩
void ManageProduct::operator = (ManageProduct &item)
{
	this->set_M_Sell_Number(item.get_M_Sell_Number());
	this->set_M_Custom_Id(item.get_M_Custom_Id());
	this->set_M_product_id(item.get_M_product_id());
	this->set_M_product_name(item.get_M_product_name()); 
	this->set_M_Manufacture_name(item.get_M_Manufacture_name());
	this->set_M_product_price(item.get_M_product_price());
	this->set_M_order_count(item.get_M_order_count()); 
	this->set_preTime(item._preTime());
	this->set_M_product_sales(item.get_M_product_sales());
}

// == 연산자 오버로딩
bool ManageProduct::operator == (ManageProduct &item)
{
	if(this->get_M_Custom_Id()==item.Custom_id && this->get_M_Sell_Number()== item.M_Sell_Number)
	{
		return true;
	}
	else 
		return false;
}

// > 연산자 오버로딩
bool ManageProduct::operator > (ManageProduct &item)
{

	if(this->_preTime() > item._preTime())
	{
		return true;
	}
	else
		return false;
}

// 판매하는 상품 확인
bool ManageProduct::check_sell_input(int number,int &modify_number) // 판매하는 상품이 맞는지 아닌지 체크하기 위한 함수
{
	char input; // 판매취소 여부확인
	int cancel_number; // 취소할려는 개수
	

	while(1)
	{
		system("cls");
		cout<<"\n\t 판매하는 상품이 "<< number << "개가 맞나요 (Y/N)? : ";
		cin>>input; 

		if(input == 'y' || input == 'Y') // 잘된 입력일시
		{
			return true;
		}
		else if(input == 'n' || input == 'N') // 잘못된 입력일시
		{
			cout<<"\n\t 취소할 상품의 개수를 입력하세요 \n ";
			cout<<"\t num : ";
			cin>>cancel_number;
			modify_number = number-cancel_number;
			return false;
		}
		else // y도 n도 아닌 입력을 할시
		{
			cout<<"\n\t < 잘못된 입력 > 다시 입력해 주세요 \n";
			system("pause");
		}
	}

}

void ManageProduct::Print_pro() // 특정한 상품의 아이템의 정보를 출력
{
	
		cout<<"\t ";
		print_preTime(_preTime());

		cout
		<<setw(10)<<get_M_Sell_Number() 
		<<setw(10)<<get_M_Custom_Id()
		<<setw(10)<<get_M_product_id()
		<<setw(15)<<get_M_product_name()
		<<setw(15)<<get_M_Manufacture_name()
		<<setw(10)<<get_M_product_price()
		<<setw(10)<<get_M_order_count()
		<<setw(10)<<get_M_product_sales();
}

time_t ManageProduct::get_preTime() //현재시간을 초로 바꾸어 리턴
{
	time_t current_time;
    current_time = time(NULL); // 현재시간을 초단위로바꿈
   
   return current_time;
}


void ManageProduct::print_preTime(time_t _current_time) // 현재시간을 형식에 맞춰 정렬해서 출력
{
	 struct tm *t;
	 t=localtime(&_current_time);

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

	buf=year; //년
	itoa(buf,target,10);
	currentTime.append(target);

	currentTime.append("/");

	buf=month;// 달
	itoa(buf,target,10);
	currentTime.append(target);

	currentTime.append("/");

	buf=day; // 일
	
	itoa(buf,target,10);
	currentTime.append(target);

	currentTime.append(" ");

	buf=hour; //  시간
	
	itoa(buf,target,10);
	currentTime.append(target);

	currentTime.append(":");

	buf=min; // 분

	itoa(buf,target,10);
	currentTime.append(target);

    cout<<left<<setw(30)<<currentTime;
}