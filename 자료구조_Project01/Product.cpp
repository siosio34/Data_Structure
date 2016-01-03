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

void Product::search_product_info() //상품 검색시 출력되게됨
{
	cout<<"\t 상품번호 : "<<get_product_ID()<<"\n";
	cout<<"\t 상품이름 : "<<get_product_name()<<"\n";
	cout<<"\t 제조업자 : "<<get_Manufacturet_name()<<"\n";
	cout<<"\t 상품가격 : "<<get_product_price()<<"\n";
	cout<<"\t 재고량 : "<<get_presentproduct_count()<<"\n";
	cout<<"\t 주문량 : "<<get_orderproduct_count()<<"\n";
}

bool Product::operator > (const Product &item) // > 연산자오버로딩
{
	if(this->get_product_ID() > item.product_ID)
		return true;
	else
		return false;
}

bool Product::operator == (const Product &item) // == 연산자오버로딩
{
	if( this->get_product_ID()==item.product_ID)
	{
		return true;
	}
	else
		return false;
}

void Product::operator = (Product &item1) // = 연산자오버로딩
{
	this->set_product_ID(item1.get_product_ID());
	this->set_product_name(item1.get_product_name());
	this->set_Manufacturet_name(item1.get_Manufacturet_name());
	this->set_product_price(item1.get_product_price());
	this->set_presentproduct_count(item1.get_presentproduct_count());
	this->set_orderproduct_count(item1.get_orderproduct_count());
}


void Product::print_preProduct() // 상품정보 출력
{

	cout<<"\t "<<setw(10)<<left
		<<setw(10)<<get_product_ID()
		<<setw(15)<<get_product_name()
		<<setw(10)<<get_product_price()
		<<setw(15)<<get_Manufacturet_name()
		<<setw(10)<<get_presentproduct_count()
		<<setw(10)<<get_orderproduct_count();

}


ostream& operator << (ostream&os, Product &item) // <<연산자오버로딩
{
	item.print_preProduct();
	return os;
}
