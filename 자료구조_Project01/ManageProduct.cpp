#include "ManageProduct.h"

ManageProduct::ManageProduct() // ManageProductd�� ������
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

//�Ű������� �ִ� ManageProductd�� ������
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

// << ������ �����ε�
ostream& operator << (ostream &os1, ManageProduct &item)
{


	item.Print_pro();
	
	return os1;
}

// = ������ �����ε�
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

// == ������ �����ε�
bool ManageProduct::operator == (ManageProduct &item)
{
	if(this->get_M_Custom_Id()==item.Custom_id && this->get_M_Sell_Number()== item.M_Sell_Number)
	{
		return true;
	}
	else 
		return false;
}

// > ������ �����ε�
bool ManageProduct::operator > (ManageProduct &item)
{

	if(this->_preTime() > item._preTime())
	{
		return true;
	}
	else
		return false;
}

// �Ǹ��ϴ� ��ǰ Ȯ��
bool ManageProduct::check_sell_input(int number,int &modify_number) // �Ǹ��ϴ� ��ǰ�� �´��� �ƴ��� üũ�ϱ� ���� �Լ�
{
	char input; // �Ǹ���� ����Ȯ��
	int cancel_number; // ����ҷ��� ����
	

	while(1)
	{
		system("cls");
		cout<<"\n\t �Ǹ��ϴ� ��ǰ�� "<< number << "���� �³��� (Y/N)? : ";
		cin>>input; 

		if(input == 'y' || input == 'Y') // �ߵ� �Է��Ͻ�
		{
			return true;
		}
		else if(input == 'n' || input == 'N') // �߸��� �Է��Ͻ�
		{
			cout<<"\n\t ����� ��ǰ�� ������ �Է��ϼ��� \n ";
			cout<<"\t num : ";
			cin>>cancel_number;
			modify_number = number-cancel_number;
			return false;
		}
		else // y�� n�� �ƴ� �Է��� �ҽ�
		{
			cout<<"\n\t < �߸��� �Է� > �ٽ� �Է��� �ּ��� \n";
			system("pause");
		}
	}

}

void ManageProduct::Print_pro() // Ư���� ��ǰ�� �������� ������ ���
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

time_t ManageProduct::get_preTime() //����ð��� �ʷ� �ٲپ� ����
{
	time_t current_time;
    current_time = time(NULL); // ����ð��� �ʴ����ιٲ�
   
   return current_time;
}


void ManageProduct::print_preTime(time_t _current_time) // ����ð��� ���Ŀ� ���� �����ؼ� ���
{
	 struct tm *t;
	 t=localtime(&_current_time);

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

	buf=year; //��
	itoa(buf,target,10);
	currentTime.append(target);

	currentTime.append("/");

	buf=month;// ��
	itoa(buf,target,10);
	currentTime.append(target);

	currentTime.append("/");

	buf=day; // ��
	
	itoa(buf,target,10);
	currentTime.append(target);

	currentTime.append(" ");

	buf=hour; //  �ð�
	
	itoa(buf,target,10);
	currentTime.append(target);

	currentTime.append(":");

	buf=min; // ��

	itoa(buf,target,10);
	currentTime.append(target);

    cout<<left<<setw(30)<<currentTime;
}