#include "Application.h"

void AppliCation::print_Start() ///���۸޴�
{
	
	while(1)
	{
		check=true;
		int Command=get_Command();

		if(Command == 1)/// Command�� 1�Ͻ� ��ǰ�����޴��� ����Ѵ�.
		{
			while(check)
			{
				system("cls");
				switch(print_product_menu())
				{
				case 1: // ��ǰ ���
					system("cls");
					AppEnProduct();
					break;
				case 2: // ��ǰ �԰�
					system("cls");
					AppPlusProduct();
					break;
				case 3: // ��ǰ �ֹ�
					system("cls");
					ApporderProduct();
					break;
				case 4: // ��ǰ ����
					system("cls");
					AppDeleteProduct();
					break;
				case 5:// ��ǰ �˻�
					system("cls");
					AppSearchProduct();
					break;
				case 6: // ��ǰ ���
					system("cls");
					AppprintProduct();
					break;
				case 0: // �ڷΰ���
					check=false;
					break;
				default : // �߸� �Է�������
					print_error();
					break;

				}	
			}
		}


		else if(Command == 2) // Command�� 2�Ͻ� �ǸŰ����޴��� ����Ѵ�.
		{
			while(check)
			{
				system("cls");
				switch(sell_product_menu())
				{
				case 1: // ��ǰ �Ǹ�
					system("cls");
					AppsellProduct();
					break;
				case 2: // ��ǰ �ǸŸ�� ���
					system("cls");
					Appsell_printProduct();
					break;
				case 3: // ��ǰ ȯ��
					system("cls");
					Appsell_refundProduct();
					break;
				case 4:
					system("cls");
					Appsearch_sell_product();
					break;
				case 0: // �ڷΰ���
					check=false;
					break;
				default: // �߸��Է�������
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

int AppliCation::get_Command() // �������̽� ��� �� Ű����κ��� ����� ������
{
	system("cls");
	cout<<"\n\t\t ����'s Market \n";
	cout<<"\t��������������������������������\n";
	cout<<"\t��  �޴�                      ��\n";
	cout<<"\t��                            ��\n";
	cout<<"\t��    1.��ǰ ����             ��\n";
	cout<<"\t��    2.�Ǹ� ��ϰ���         ��\n";
	cout<<"\t��    3.���� ���ǰ���         ��\n";
	cout<<"\t��    4.����                  ��\n";
	cout<<"\t��                            ��\n";
	cout<<"\t��������������������������������\n";

	cout<<"\t �޴� �Է� : "; 
	cin>>input_Command;
	market.check_input();

	return input_Command;
}

int AppliCation::print_product_menu() // �������̽� ��� �� Ű����κ��� ����� ������
{
	while(1)
	{
		cout<<"\n\t\t ����'s Market \n";
		cout<<"\t��������������������������������\n";
		cout<<"\t��  ��ǰ�޴�                  ��\n";     
		cout<<"\t��                            ��\n";		
		cout<<"\t�� 1.  ��ǰ ���              ��\n";
		cout<<"\t�� 2.  ��ǰ �԰�              ��\n";
		cout<<"\t�� 3.  ��ǰ �ֹ�              ��\n";
		cout<<"\t�� 4.  ��ǰ ����              ��\n";
		cout<<"\t�� 5.  ��ǰ �˻�              ��\n";
		cout<<"\t�� 6.  ��� ��ǰ ���         ��\n";
		cout<<"\t�� 0.  ���� �޴���            ��\n";
		cout<<"\t��                            ��\n";
		cout<<"\t��������������������������������\n";

		cout<<"\t �޴� �Է� : "; 
		cin>>input_Command;

		if(market.check_input())
		 return input_Command;

		system("cls");
	}
}
int AppliCation::sell_product_menu() // �������̽� ��� �� Ű����κ��� ����� ������
{
	while(1)
	{
		cout<<"\n\t\t ����'s Market \n";
		cout<<"\t��������������������������������\n";
		cout<<"\t��  �ǸŰ����޴�              ��\n";     
		cout<<"\t��                            ��\n";	
		cout<<"\t�� 1.  ��ǰ �Ǹ�              ��\n";
		cout<<"\t�� 2.  ��ǰ �ǸŸ�� ���     ��\n";
		cout<<"\t�� 3.  ��ǰ ��ǰ              ��\n";
		cout<<"\t�� 4.  ��ǰ �ǸŸ�� �˻�     ��\n";
		cout<<"\t�� 0.  ���� �޴���            ��\n";
		cout<<"\t��                            ��\n";
		cout<<"\t��������������������������������\n";

		cout<<"\t �޴� �Է� : "; 
		cin>>input_Command;
	
	
		if(market.check_input())
		return input_Command;
		
		system("cls");
	}
	
}

void AppliCation::AppEnProduct() //��ǰ���
{
	int check=market.EnProduct(); //������ �Լ��� �ҷ���

	if(check==0) cout<<"\n\t����Ϸ��� ��ǰ�� �̹� �ֽ��ϴ� \n";
	else if(check==-1) cout<<"\n\t < ��ǰ ��� ���� >-�߸��� �Է�! \n";
	else cout<<"\n\n\t <��ǰ ����� ���������� ó���Ǿ����ϴ�> \n";

	system("pause");

}

void AppliCation::AppPlusProduct() // ��ǰ �԰�
{
	int check=market.PlusProduct(); //������ �Լ��� �ҷ���

	if(check==0) cout<<"\n\t<��ǰ �԰� ����>-�߸��� �Է�! \n";
	else if(check==-1) cout<<"\n\t �԰��ҷ��� ��ǰ�� �ֹ����� ������� �ʽ��ϴ� \n";
	else cout<<"\n\n\t <��ǰ �԰� ���������� ó���Ǿ����ϴ�> \n";

	system("pause");

}

void AppliCation::ApporderProduct() // ��ǰ �ֹ�
{
	bool check=market.orderProduct(); //������ �Լ��� �ҷ���

	if(check==false) cout<<"\n\t<��ǰ �ֹ� ����>-�߸��� �Է�! \n";	
	else cout<<"\n\n\t <��ǰ �ֹ��� ���������� ó���Ǿ����ϴ�> \n";

	system("pause");

}

void AppliCation::AppsellProduct() //��ǰ �Ǹ�
{
	int check=market.sellProduct(); //������ �Լ��� �ҷ���

	if(check==false) cout<<"\n\n\t<��ǰ �Ǹ� ����>-�߸��� �Է�!"<<endl;
	else if(check==-1) cout<<"\n\t <��ǰ ���� ����> ! \n " ;
	else cout<<"\n\n\t <��ǰ �ǸŰ� ���������� ó���Ǿ����ϴ�> \n"; 

	system("pause");
}

void AppliCation::AppDeleteProduct() // ��ǰ ����
{
	int check=market.DeleteProduct(); //������ �Լ��� �ҷ���

	if(check==-1) cout<<"\n\n\t <���� ��ǰ ���� ���� > "<<endl;
	else if(check==0) cout<<"\n\n\t�Է��Ͻ� ID�� ���� ��ǰ�� �������� �ʽ��ϴ� !"<<endl;
	else cout<<"\n\n\t <��ǰ ������ ���������� ó���Ǿ����ϴ�> \n"; 

	system("pause");
}

void AppliCation::AppSearchProduct() // ��ǰ �˻�
{
	bool check=market.SearchProduct(); //������ �Լ��� �ҷ���

	if(check==false) cout<<"\n\t�Է��Ͻ� ��ǰ�� �� ��Ʈ�� �������� �ʽ��ϴ� !"<<endl;
	else cout<<"\n\n\t <��ǰ �˻��� ���������� ó���Ǿ����ϴ�> \n";

	system("pause");
}

void AppliCation::AppprintProduct() // ��ǰ ���
{
	bool check=market.printProduct(); //������ �Լ��� �ҷ���

	if(check==false) cout<<"\n\t ��ϵ� ��ǰ�� ��Ʈ�� �������� �ʽ��ϴ� !" <<endl;
	else cout<<"\n\n\t <��ǰ��� ����� ���������� ó���Ǿ����ϴ�> \n";

	system("pause");
}

void AppliCation::Appsell_printProduct() //��ǰ �Ǹ�
{
	bool check;
	check=market.sell_PrintProduct(); //������ �Լ��� �ҷ���

	if(check==false) cout<<"\n\t �Ǹŵ� ��ǰ�� ��Ʈ�� �������� �ʽ��ϴ� " <<endl;
	else cout<<"\n\n\t <��ǰ�Ǹ� ����� ���������� ó���Ǿ����ϴ�> \n";

	system("pause");
}

void AppliCation::Appsell_refundProduct() // ��ǰ ȯ��
{
	int check;

	check=market.sell_ProductRefund(); //������ �Լ��� �ҷ���

	if(check==0) cout<<"\n\t <��ǰ ȯ�� ����>-�߸��� �Է�!. \n";
	else if(check==-1) cout<<"\n\t ��ǰ ��ȣ�� �߸� �Է��ϼ˽��ϴ�. \n";
	else cout<<"\n\n\t <��ǰ ȯ���� ���������� ó���Ǿ����ϴ�> \n";

	system("pause");

}

void AppliCation::Appsearch_sell_product() // ��ǰ �ǸŸ�� �˻�
{
	int check;

	check=market.search_M_print_product(); //������ �Լ��� �ҷ���

	if(check==0) cout<<"\n\t < �Ǹ� ��ǰ �˻� ���� > - �߸��� �Է� !. \n";
	else if(check==-1) cout<<"\n\t �Ǹŵ� ��ǰ�� �����ϴ� \n";
	else cout<<"\n\n\t < �Ǹ� ��ǰ �˻��� ���������� ó�� �Ǿ����ϴ� >\n";

	system("pause");
}






