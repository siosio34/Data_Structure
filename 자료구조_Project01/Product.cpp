#include "Product.h"

Product::Product()
{
	product_ID=0;
	product_presentCount=0;
	product_orderCount=0;
	product_price=0;
	product_name="";
	Manufacture_name="";
}

Product::~Product()
{

}

void Product::search_product_info() //��ǰ �˻��� ��µǰԵ�
{
	cout<<"\t ��ǰ��ȣ : "<<get_product_ID()<<"\n";
	cout<<"\t ��ǰ�̸� : "<<get_product_name()<<"\n";
	cout<<"\t �������� : "<<get_Manufacturet_name()<<"\n";
	cout<<"\t ��ǰ���� : "<<get_product_price()<<"\n";
	cout<<"\t ��� : "<<get_presentproduct_count()<<"\n";
	cout<<"\t �ֹ��� : "<<get_orderproduct_count()<<"\n";
}

bool Product::operator > (const Product &item) // > �����ڿ����ε�
{
	if(this->get_product_ID() > item.product_ID)
		return true;
	else
		return false;
}

bool Product::operator == (const Product &item) // == �����ڿ����ε�
{
	if( this->get_product_ID()==item.product_ID)
	{
		return true;
	}
	else
		return false;
}

void Product::operator = (Product &item1) // = �����ڿ����ε�
{
	this->set_product_ID(item1.get_product_ID());
	this->set_product_name(item1.get_product_name());
	this->set_Manufacturet_name(item1.get_Manufacturet_name());
	this->set_product_price(item1.get_product_price());
	this->set_presentproduct_count(item1.get_presentproduct_count());
	this->set_orderproduct_count(item1.get_orderproduct_count());
}


void Product::print_preProduct() // ��ǰ���� ���
{

	cout<<"\t "<<setw(10)<<left
		<<setw(10)<<get_product_ID()
		<<setw(15)<<get_product_name()
		<<setw(10)<<get_product_price()
		<<setw(15)<<get_Manufacturet_name()
		<<setw(10)<<get_presentproduct_count()
		<<setw(10)<<get_orderproduct_count();

}


ostream& operator << (ostream&os, Product &item) // <<�����ڿ����ε�
{
	item.print_preProduct();
	return os;
}
