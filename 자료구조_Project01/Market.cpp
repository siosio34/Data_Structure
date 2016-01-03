#include "Market.h"

void Market::M_print_product()
{

	cout<<"\t ";
	cout<<left<<setw(30)<<"����ð�(��/��/�� ��:��)"

		<<setw(10)
		<<"�ǸŹ�ȣ "<<setw(10)
		<<"������ ID "<<setw(10)
		<<"��ǰ ID "<<setw(15)
		<<"��ǰ�̸� "<<setw(15)
		<<"�������� "<<setw(10)
		<<"��ǰ����"<<setw(10)
		<<"�ǸŰ��� "<<setw(10)
		<<"�� �ݾ� \n\n";
}

void Market::print_product_info()
{
	cout<<"\t "<<setw(10)
		<<left<<setw(10)
		<<"��ǰ��ȣ "<<setw(15)
		<<"��ǰ�̸� "<<setw(10)
		<<"��ǰ����"<<setw(15)
		<<"�������� "<<setw(10)
		<<"��� / �ֹ��� "<<setw(10)
		<<"�Ǹŷ� "<<setw(10)
		<<"���ͱ� "<<"\n\n";
}

int Market::EnProduct() //��ǰ ���
{
	int pro_id;
	int pro_price;
	string pro_name;
	string Manu_Name;
	int check=0;

	cout<<"\n\t �������������������� ";
	cout<<"\n\t ��    ��ǰ���    �� ";
	cout<<"\n\t �������������������� \n\n";

	cout<<"\t "<<"��ǰ ID �Է� : "; cin>>pro_id;
	if(check_input())
	{
		cout<<"\t "<<"��ǰ �̸� �Է� : "; cin>>pro_name;
		cout<<"\t "<<"���� ���� �Է� : "; cin>>Manu_Name;
		cout<<"\t "<<"��ǰ ���� �Է� : "; cin>>pro_price;
		if(check_input())
		{
			Product a(pro_id,pro_name,Manu_Name,pro_price,0,0);

			if(Pro_list.search(a)==false) // ���� �̸��̳� ���� ���̵� ������.
			{
				Pro_list.Add(a); //�ش� item�� �߰��Ѵ�.
				return 1;
			}
			else
				return 0;// �ش��̸��̳� ���̵� ������ ������
		}
		return -1; //�߸��� �Է��Ͻ�.
	}
	return -1; //�߸��� �Է��Ͻ�.

}

int Market::PlusProduct() // ��ǰ�԰�
{
	Product item;
	int select_num;
	int _product;
	cout<<"\n\t �������������������� ";
	cout<<"\n\t ��    ��ǰ�԰�    �� ";
	cout<<"\n\t �������������������� \n\n";

	print_product_info();
	print_prepro();

	cout<<"\t �԰��� ��ǰ�� ID�� �Է��� �ּ���\n";
	cout<<"\t ID : "; cin>>select_num;
	if(check_input())
	{
		Pro_list.ResetItem();

		while(Pro_list.GetNextItem(item) != false)
		{
			if(item.get_product_ID() ==select_num) // �Է��� ������ �������� ���̵�� ������
			{
				cout<<"\n\t �԰��� ��ǰ������ �Է����ּ���\n  ";
				cout<<"\t num : "; cin>>_product;
				if(check_input())
				{
					if(item.get_orderproduct_count() >= _product) // �ֹ����� �Է��� �԰����� ������
					{
						item.set_orderproduct_count(item.get_orderproduct_count()-_product); // �ֹ��� down
						item.set_presentproduct_count(item.get_presentproduct_count()+_product); // �԰� up
						Pro_list.update(item);
						return 1; //��ǰ �԰� �� �۵�������
					}
					else return -1;	 // ���̵�� ������ �ֹ����� ����������
				}
			}
		}
	}
	return 0; //���̵�� ���� ��ǰ�� ������
}

bool Market::orderProduct() //��ǰ �ֹ�
{
	Product item;
	int select_num;
	int _product;

	cout<<"\n\t �������������������� ";
	cout<<"\n\t ��    ��ǰ�ֹ�    �� ";
	cout<<"\n\t �������������������� \n\n";

	print_product_info();
	print_prepro();

	cout<<"\t �ֹ��� ��ǰ�� ID�� �Է��� �ּ���\n";
	cout<<"\t ID : "; 
	cin>>select_num;

	if(check_input())
	{

		Pro_list.ResetItem();

		while(Pro_list.GetNextItem(item) != false)
		{
			if(item.get_product_ID() ==select_num) // �Է��� ������ �����Ҷ�
			{
				cout<<"\n\t �ֹ��� ��ǰ������ �Է����ּ���\n ";
				cout<<"\t num : ";
				cin>>_product;
				if(check_input())
				{
					item.set_orderproduct_count(item.get_orderproduct_count()+_product); // �ֹ��� up
					Pro_list.update(item);

					return true; //��ǰ �ֹ��� ����������
				}
				return false;
			}
		}
	}
	return false; //��ǰ �ֹ��� ����������
}

int Market::DeleteProduct() // ��ǰ ����
{
	Product item;
	int select_num;

	cout<<"\n\t �������������������� ";
	cout<<"\n\t ��    ��ǰ����    �� ";
	cout<<"\n\t �������������������� \n\n";

	print_product_info();
	print_prepro();

	if(Pro_list.GetLength())
	{
		cout<<"\t ������ ��ǰ�� ID�� �Է��� �ּ���\n";
		cout<<"\t ID : "; cin>>select_num;
		if(check_input())
		{
			Pro_list.ResetItem();
			while(Pro_list.GetNextItem(item) != false)
			{
				if(item.get_product_ID() == select_num)
				{
					Pro_list.Delete(item);
					return 1; // ��ǰ ������ ����������
				}
			}
			return 0; //�Է��� ������ �ش� id�� ������������.
		}
		else
			return 0;
	}

	return -1; // �߸��� �Է��� ������
}

bool Market::SearchProduct() // ��ǰ �˻�
{
	cout<<"\n\t �������������������� ";
	cout<<"\n\t ��    ��ǰ�˻�    �� ";
	cout<<"\n\t �������������������� \n\n";

	Product item;
	ManageProduct item2;
	Media Me;
	string pro_name;
	int count=0;

	cout<<"\t "<<"��ǰ �̸� �Է� : "; cin>>pro_name;

	cout<<"\n\n\t <�Է��� ��ǰ�� ����> \n";
	
	Pro_list.ResetItem();

	while(Pro_list.GetNextItem(item) != false)
	{
		if(item.get_product_name() ==pro_name) // ��ǰ�̸��� �Է��� �̸��� ������
		{
			item.search_product_info();

			cout<<"\n\n";
			cout<<"\n\t �������������������� ";
			cout<<"\n\t ��  ��ǰ�Ǹų���  �� ";
			cout<<"\n\t �������������������� \n\n";

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

			return true; //��ǰ �˻��� ���������� ������
		}
	}
	return false; // ��ǰ �˻��� ����������.
}

bool Market::printProduct()
{
	Product item;
	ManageProduct item2;
	cout<<"\n\t < ��ǰ ��� > \n\n";
	print_product_info();

	print_prepro();

	return true;
}

bool Market::check_input()  ///�Է��� ���� ����ó��
{
	if(cin.fail())
	{
		cout <<"\n\n\t �߸� �Է��Ͽ����ϴ�<���ڸ� �Է°���>.\n";
		cin.clear();
		cin.ignore(100, '\n');
		Sleep(500);
		return false;
	}
	return true;
}

int Market::sellProduct() //��ǰ �Ǹ�
{
	Product item;
	int select_num;
	int modify_number;
	int _product;
	int C_id;

	time_t s_time;

	cout<<"\n\t �������������������� ";
	cout<<"\n\t ��    ��ǰ �Ǹ�   �� ";
	cout<<"\n\t �������������������� \n\n";

	print_product_info();
	print_prepro();

	cout<<"\t �Ǹ��� ��ǰ�� ID�� �Է��� �ּ���\n";
	cout<<"\t ID : "; cin>>select_num;
	check_input();

	Pro_list.ResetItem();

	while(Pro_list.GetNextItem(item) != false)
	{
		if(item.get_product_ID() == select_num) //�Է¹��� ���ڰ� ��ǰ�� ���̵�� ������
		{
			cout<<"\n\t �Ǹ��� ��ǰ������ �Է����ּ��� ";
			cout<<"\n\t num : "; 

			cin>>_product;

			if(check_input())
			{

				if(item.get_presentproduct_count() >= _product) // �԰��� ����Ҷ�
				{
					cout<<"\n\t �����Ͻô� ȸ���� ���̵� �Է��ϼ��� \n";
					cout<<"\t ID : ";
					cin>>C_id;

					if(check_input())
					{
						
						item.set_presentproduct_count(item.get_presentproduct_count()-_product); // �԰� �ٿ�
						Pro_list.update(item);
						item.set_Sum_money(_product,item.get_product_price()); // �Ǹűݾ� ����
						s_time=clock();// �Ǹŵ����� �ð��� �޾ƿ�

						s_Money+=item.get_money(); // �ѱݾ� ����.

						ManageProduct M_list(c_Num,C_id,item.get_product_ID(),item.get_product_name(),item.get_Manufacturet_name(),item.get_product_price(),_product,item.get_money());
						c_Num++; //�ǸŹ�ȣ ����

						if(!M_list.check_sell_input(_product,modify_number)) // ���࿡ �Ǹŷ��� �߸����� ���
						{
							item.set_presentproduct_count(item.get_presentproduct_count() + (_product-modify_number)); // ȯ���Ѽ���ŭ �԰� ����
							Pro_list.update(item); //item�� �԰� ������Ʈ
							M_list.set_M_order_count(modify_number); // �Ǹ� ��ҷ� ����
							M_list.set_M_product_sales(item.get_product_price()*modify_number); // �Ǹ� ���ͱ� ����
						}

						Man_list.Add(M_list); // ����Ʈ�� �߰�

						return 1; //��ǰ�ǸŰ� ���������� �̷��������
					}
				}
				else return -1; //�԰��� ������Ҷ�
			}

		}
	}
	return 0; // �ش� ID�� ���� ��ǰ�� ������
}

bool Market::sell_PrintProduct() // �ǸŸ�� ���
{
	ManageProduct item;
	Man_list.ResetItem();

	time_t e_time;
	e_time=time(NULL); // ����ð� ����

	

	while(Man_list.GetNextItem(item) != false)
	{
		item.set_endTime(e_time);

		if(e_time - item._preTime() > 86400) // ����ð�-�ǸŽð� 60�ʰ� �ǸŸ�Ͽ��� ����
		{
			Man_list.Delete(item);
			Man_list.ResetItem(); //sorted ����Ʈ�̹Ƿ� ó������ ���ư����ϴ��� ������ ������ ��� ������ ����ġ�� �Ҽ� �ִ�.
		}
	}

	cout<<"\n\t < �ǸŸ�� ��� > \n\n";
	cout<<"\t < �� ���� > : ";
	cout<<s_Money<<"\n\n";
	M_print_product();

	if(Man_list.print())
		return true;

	return false;
}

int Market::sell_ProductRefund() // ��ǰ ȯ��
{	
	int C_id; //  �� id
	int S_id; // ��ǰ�ǸŹ�ȣ
	int r_count=0; // ȯ�� ��ǰ ����� �ִ��� ������ üũ
	bool check=true; // �Է��� �ǸŻ�ǰ ��ȣ�� �ִ��� ������ üũ
	ManageProduct item;

	cout<<"\n\t �������������������� ";
	cout<<"\n\t ��    ȯ���ϱ�    �� ";
	cout<<"\n\t �������������������� \n\n";


	if(sell_PrintProduct()) //�ǸŸ���� ������
	{
		cout<<"\n\t ȯ���� ��û�� ȸ���� ���̵� �Է��ϼ��� \n";
		cout<<"\t ID : ";
		cin>>C_id;
		if(check_input())
		{
			system("cls");

			cout<<"\n\t �������������������� ";
			cout<<"\n\t ��  ȯ�Ұ��ɻ�ǰ  �� ";
			cout<<"\n\t �������������������� \n\n";

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
				cout<<"\n\t "<<C_id<<" ���� ȯ�� ������ ��ǰ�� �����ϴ� \n";
				return 0;
			}

			cout<<"\n\t ȯ���� ��ǰ�� �ǸŹ�ȣ�� �Է��ϼ��� \n";
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
						return 1; // ��ǰȯ���� �ߵ�����
					}
					check=false;
				}
			}

		}
		if(!check) return -1; // �Է��� id�� ������ ������
	}

	return 0; // �ƹ��͵� ������
}


int Market::search_M_print_product()
{
	ManageProduct item;

	string name;
	Man_list.ResetItem();
	int count = 0;

	cout<<"\n\t �������������������� ";
	cout<<"\n\t ��  �ǸŻ�ǰ�˻�  �� ";
	cout<<"\n\t �������������������� \n\n";

	cout<<"\n\t �˻��� ��ǰ�� �̸��� �Է��ϼ��� \n";
	cout<<"\t �ǸŻ�ǰ�� : ";
	cin>>name;
	if(check_input())
	{
		system("cls");

		cout<<"\n\t �������������������� ";
		cout<<"\n\t ��  �ǸŻ�ǰ����  �� ";
		cout<<"\n\t �������������������� \n\n";

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

		if(count == 0 ) // �Ǥ��� ��ǰ������ ������
		{
			return -1;
		}
		else
			return 1; // �� ��µ�����
	}
	else	
		return 0; // �Է��� �߸�������
}

void Market::load_product() // ����ǰ �ε�
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

	while(getline(fin,record)) // ���� �� ������ ����
	{
		stringstream spacing(record);
		spacing >> P_Id >> P_ProName >>P_MaunName>>P_Price >> P_Pcount >> P_Ocount;
		Product a(P_Id,P_ProName,P_MaunName,P_Price,P_Pcount,P_Ocount);
		Pro_list.Add(a); //����Ʈ�� �߰�
	}

	fin.close();
}

void Market::save_product() //����ǰ ����Ʈ ����
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

		if(count != length) //�Ǹ��������϶�
			fout<<endl;
	}

	fout.close();
}

void Market::load_sellProduct() //�Ǹ� ��ǰ ����Ʈ �ε�
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

	
	time_t M_preTime; //����ð��� �޾ƿ�

	int M_Pro_sales;

	while(getline(fin,record))  //���پ� ����
	{
		stringstream spacing(record);
		spacing >> M_sellNum >> M_Cus_id >> M_Pro_id >> M_Pro_name  >>M_Manu_name >>  M_pro_price >> M_or_count >> M_preTime >> M_Pro_sales;

		ManageProduct a(M_sellNum,M_Cus_id,M_Pro_id,M_Pro_name,M_Manu_name,M_pro_price,M_or_count,M_Pro_sales);
		a.set_preTime(M_preTime);
		Man_list.Add(a);
	}

	fin.close();
}

void Market::save_sellProduct() // �Ǹ� ����Ʈ ����
{
	ofstream fout;
	fout.open("sellproduct.txt");
	ManageProduct item;

	int count = 0;
	int length = Man_list.GetLength();
	fout.clear();

	Man_list.ResetItem(); //����Ʈ �ʱ�ȭ

	time_t e_time;
	e_time=time(NULL); // ����ð� ����

	while(Man_list.GetNextItem(item) != false)
	{
		if(e_time - item._preTime() > 86400) // ����ð�-�ǸŽð� 60�ʰ� �ǸŸ�Ͽ��� ����
		{
			Man_list.Delete(item);
			Man_list.ResetItem(); //sorted ����Ʈ�̹Ƿ� ó������ ���ư����ϴ��� ������ ������ ��� ������ ����ġ�� �Ҽ� �ִ�.
		}
	}

	Man_list.ResetItem(); //����Ʈ �ʱ�ȭ

	while(Man_list.GetNextItem(item) != NULL)
	{
		fout<<left<<item.get_M_Sell_Number()<<" "<<item.get_M_Custom_Id()<<" "
			<<item.get_M_product_id()<<" "<<item.get_M_product_name()<<" "
			<<item.get_M_Manufacture_name()<<" "<<item.get_M_product_price()<<" "
			<<item.get_M_order_count()<<" "<<item._preTime()<<" "<<item.get_M_product_sales();

		count ++;

		if(count != length) // �Ǹ����� ���϶�
			fout<<endl;
	}

	fout.close();
}

void Market::save_endMarket() // ������ ����� ����
{
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


	string str = currentTime+ "���� ����.txt"; // ���糯¥�̸��� ����θ� �����
	ofstream fout;
	fout.open(str);

	fout<<" ������ ��¥ : "<< currentTime <<"\n\n";
	fout<<" ���� ���� �� ����  : "<< s_Money << " �� "<<"\n\n";

	Product item;
	ManageProduct item2;

	int S_m=0;// �� ��ǰ�� ����
	int S_c=0;// �� ��ǰ�� �Ǹŷ�

	Pro_list.ResetItem();

	// ��� ��ǰ�� �ǸŻ�ǰ�� �̸��� �����Ÿ� ã�� ������ ���Ѵ�.
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
		fout<<" ������������������������������������������������\n";
		fout<<" �� ��ǰ �̸� : " <<left<<setw(31)<<item.get_product_name()<<"��\n";
		fout<<" �� ��ǰ �Ǹŷ� : "<<left<<setw(29)<<S_c<<"��\n";
		fout<<" �� ��ǰ ���� : "<<left<<setw(31)<<S_m<<"��\n";
		fout<<" ������������������������������������������������\n\n";
		S_m=0;
		S_c=0;
	}
	fout.close();
}

		
void Market::print_prepro() // ����ǰ�� ������ ����Ѵ�,
{
	Product item;
	ManageProduct item2;

	int S_m=0;// �� ��ǰ�� ����
	int S_c=0;// �� ��ǰ�� �Ǹŷ�

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
		item.print_preProduct(); //�������� �������
		cout<<setw(10)<<S_c<<setw(10)<<S_m<<setw(10)<<"\n\n\n"; //��ǰ�� ���ͱݰ� �Ǹŷ��� �����Ѵ�,
		S_m=0;
		S_c=0;
	}
}


void Market::sound_control()
{
	system("cls");
	cout<<"\t �� ���� ����Ű : Volume UP ! \n";
	cout<<"\t �� �Ʒ� ����Ű : Volume Down ! \n";
	cout<<"\t �� ���� ����Ű : Stop Music ! \n";
	cout<<"\t �� ������ ����Ű : Play Music !\n";

	Media Ma;
	string a="mp3";
	Ma.print_Picture(a);
}



		
		
		



