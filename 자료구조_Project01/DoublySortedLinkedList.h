#pragma once

/**================================ struct DoublySortedNodeType ==============================================
@brief  이 구조체는 Linked List를 구현하기 위해서 정의해준 구조체이다.
==============================================================================================================*/
template <class ItemType>
struct DoublySortedNodeType
{
	ItemType data;
	DoublySortedNodeType *prev;
	DoublySortedNodeType *next;
};

/**=================================Class DoublySortedLinkedList================================================================================
*   @brief DoublySortedLinkedList 클래스- 템플릿을 이용한 자료구조 클래스
*   @author 조영제
*   @date 2014/11/09
*   @details template을 이용해서 재사용성을 용이하게함. DoubleSortedLinkedlist로 구현해서 전 노드를 가르키는 포인터가 필요없도록함(예외처리를 줄임)
================================================================================================================================================*/

template <class ItemType>
class DoublySortedLinkedList
{
public:
	/**
	*	DoublySortedLinkedList 생성자
	*/
	DoublySortedLinkedList();
	/**
	*	DoublySortedLinkedList 소멸자
	*/
	~DoublySortedLinkedList();

public:
	/**
	*	@brief	리스트 정보를 초기화 하는 역할을한다
	*	@pre	없다
	*	@post	리스트가 초기화 된다.
	*/
	void MakeEmpty();
	/**
	*	@brief	List에 새 Node를 추가한다.
	*	@pre	저장할 ItemType을 받아온다.
	*	@post	List에 정렬상태로 추가한다.
	*	@param	item 추가하려는 데이터가 들어가 있다.
	*/
	void Add(ItemType item);
	/**
	*	@brief	List에 저장된 Node를 삭제한다.
	*	@pre	삭제할 ItemType을 받아온다.
	*	@post	List에서 삭제한 후, 삭제한 ItemType을 data에게 저장해준다.
	*	@param	item 삭제하려는 데이터가 들어있다.
	*/
	void Delete(ItemType &item);
	/**
	*	@brief	입력받은 아이디를 검색하여 정보를 리턴하는 함수다.
	*	@pre	검색하기 위해 입력받은 아이디를 가지고 있어야한다.
	*	@param	item 검색하기 위한 정보가 들어있다.
	*	@post	데이터 정보를 검색한다
	*   @return 함수가 잘 작동되면 true를 아니면 false를 리턴한다.
	*/
	bool search(ItemType &item);
	/**
	*	@brief	입력받은 아이디를 비교하여 찾고, 데이터 정보를 갱신한다.
	*	@pre	갱신받기 위해 입력받은 아이디를 가지고 있어야한다.
	*	@param	item 수정하기 위한 정보를 가지고있다.
	*	@post	데이터 정보를 수정한다
	*   @return 함수가 잘 작동되면 true를 리턴 아니면 false를 리턴한다.
	*/
	bool update(ItemType &item);
	/**
	*	@brief	List에 있는 모든 Node를 출력한다.
	*	@pre	None.
	*	@post	화면에 List에 있는 모든 Node를 출력한다.
	*/
	bool print();/// 배열안에 있는 정보를 출력하는 함수이다.
	/**
	*	@brief	List에 저장된 Node의 개수를 반환한다.
	*	@pre	없다
	*	@post	List에 저장된 Node의 개수를 반환한다.
	*/
	int GetLength();/// 배열안에 있는 길이를 리턴한다.
	/**
	*	@brief	노드를 한칸 이동하고 그 노드의 값을 리턴한다.
	*	@pre	리스트에 정보가 들어가 있어야한다.
	*	@post   노드의 위치를 한칸이동하게 된다.
	*	@param	item 현재노드를 가르키고 있는 정보이다.
	*	@return	 현재위치보다 다음 노드에 있는 정보를 리턴한다.
	*/
	bool GetNextItem(ItemType &item);
	/**
	*	@brief	노드를 처음 위치로 이동시켜주는 함수이다.
	*	@pre	None.
	*	@post   노드를 처음 위치로 이동하게된다.
	*/
	void ResetItem() { pCurrent = m_pFirst;}

private:
	DoublySortedNodeType<ItemType> *m_pFirst; ///< 리스트의 맨처음
	DoublySortedNodeType<ItemType> *m_pLast; ///< 리스트의 맨끝
	DoublySortedNodeType<ItemType> *pCurrent; ///< 리스트를 이동시키기 위한 포인터
	int m_nLength;	///< 리스트의 길이.
};

template <class ItemType>
DoublySortedLinkedList<ItemType>::DoublySortedLinkedList()
{
	m_nLength=0;
	m_pFirst = new DoublySortedNodeType<ItemType>;
	m_pLast = new DoublySortedNodeType<ItemType>;

	m_pFirst->prev = 0; //NULL (while 문 조건처리를 위함)
	m_pFirst->next = m_pLast;

	m_pLast->prev = m_pFirst;
	m_pLast->next = 0;// NULL (while 문 조건처리를 위함)

}

template <class ItemType>
DoublySortedLinkedList<ItemType>::~DoublySortedLinkedList()
{
	MakeEmpty(); /// 리스트의 정보를 초기화시켜준다.
}

template <class ItemType>
int DoublySortedLinkedList<ItemType>::GetLength() // 길이 리턴
{
	return m_nLength; /// 리스트의 길이를 리턴한다.
}


template <class ItemType>
void DoublySortedLinkedList<ItemType>::MakeEmpty() //정보 초기화
{
	if(!m_nLength) // 하나의 정보라도 들어가 있을때
	{
		DoublySortedNodeType<ItemType> *Temp;// 정보를 임시로 가르키기위해서 선언한변수
		pCurrent = m_pFirst->next;

		while(!pCurrent) // pCurrent가 0 (맨끝에 도달하기 까지)
		{
			Temp = pCurrent;
			pCurrent = pCurrent->next;
			pCurrent->prev->next = pCurrent->next;
			pCurrent->next->prev = pCurrent->prev;
			delete Temp;
		}
	}
}

template <class ItemType>
bool DoublySortedLinkedList<ItemType>::GetNextItem(ItemType &item) // 노드이동
{
	if(pCurrent->next == m_pLast) // 더이상 이동시킬게 없을때
	{
		return false;
	}
	else
	{
		pCurrent=pCurrent->next;
		item=pCurrent->data; //item 에 노드의 정보를 옮겨담음
		return true;
	}
}


template <class ItemType>
void DoublySortedLinkedList<ItemType>::Add(ItemType item) //노드추가
{
	pCurrent= m_pFirst; // 맨처음 노드로 초기화.
	DoublySortedNodeType<ItemType> *node = new DoublySortedNodeType<ItemType>;


	node->data=item; 
	node->next=NULL;
	node->prev=NULL;

	while(pCurrent->next->next) // pCurrent가 m_pLast에 도달하기 전까지
	{
		if(pCurrent->next ->data > item) // 대소비교를 해서 노드를 추가할 위치 선정
			break;
		pCurrent = pCurrent->next; // 노드이동
	}

	node->next = pCurrent->next;
	node->prev = pCurrent;
	pCurrent->next = node;

	m_nLength++; // 노드 길이 추가
}

template <class ItemType>
void DoublySortedLinkedList<ItemType>::Delete(ItemType &item) // 노드 삭제
{
	pCurrent = m_pFirst; // 맨처음 노드로 초기화.

	while(pCurrent->next->next) // pCurrent가 m_pLast에 도달하기 전까지
	{
		if(item == pCurrent->next->data) // item의 정보가 일치할때
		{
			DoublySortedNodeType<ItemType> *Temp;
			Temp = pCurrent->next; //노드 이동

			pCurrent->next->next->prev = pCurrent; 
			pCurrent->next = pCurrent->next->next;
			item = Temp->data;
			delete Temp;
			break;
		}
		else
			pCurrent = pCurrent->next; //노드 이동
	}
	m_nLength--; //노드 길이 감소
}

template <class ItemType>
bool DoublySortedLinkedList<ItemType>::print() // 정보 출력
{
	pCurrent=m_pFirst; // 맨처음 노드로 초기화.

	while(pCurrent->next->next) // pCurrent가 m_pLast에 도달하기 전까지
	{
		pCurrent=pCurrent->next; // 노드이동
		cout<<pCurrent->data<<"\n";
	}
	cout<<"\n";

	if(m_nLength==0) // 노드안에 정보가 없을때
		return false;

	return true;
}

template <class ItemType>
bool DoublySortedLinkedList<ItemType>::search(ItemType &item) // 정보 검색
{
	pCurrent=m_pFirst; // 맨처음 노드로 초기화.

	while(pCurrent->next->next) // pCurrent가 m_pLast에 도달하기 전까지
	{
		if(pCurrent->next->data==item) 
		{
			item=pCurrent->next->data;
			return true;
		}
		else
			pCurrent = pCurrent->next; //노드 이동
	}
	return false;
}

template <class ItemType>
bool DoublySortedLinkedList<ItemType>::update(ItemType &item) // 정보 업데이트
{
	pCurrent=m_pFirst; // 맨처음 노드로 초기화.

	while(pCurrent->next)
	{
		if(pCurrent->data == item)
		{
			pCurrent->data = item;
			return true;
		}
		pCurrent=pCurrent->next; //노드 이동
	}
	return false;
}










