#pragma once

/**================================ struct DoublySortedNodeType ==============================================
@brief  �� ����ü�� Linked List�� �����ϱ� ���ؼ� �������� ����ü�̴�.
==============================================================================================================*/
template <class ItemType>
struct DoublySortedNodeType
{
	ItemType data;
	DoublySortedNodeType *prev;
	DoublySortedNodeType *next;
};

/**=================================Class DoublySortedLinkedList================================================================================
*   @brief DoublySortedLinkedList Ŭ����- ���ø��� �̿��� �ڷᱸ�� Ŭ����
*   @author ������
*   @date 2014/11/09
*   @details template�� �̿��ؼ� ���뼺�� �����ϰ���. DoubleSortedLinkedlist�� �����ؼ� �� ��带 ����Ű�� �����Ͱ� �ʿ��������(����ó���� ����)
================================================================================================================================================*/

template <class ItemType>
class DoublySortedLinkedList
{
public:
	/**
	*	DoublySortedLinkedList ������
	*/
	DoublySortedLinkedList();
	/**
	*	DoublySortedLinkedList �Ҹ���
	*/
	~DoublySortedLinkedList();

public:
	/**
	*	@brief	����Ʈ ������ �ʱ�ȭ �ϴ� �������Ѵ�
	*	@pre	����
	*	@post	����Ʈ�� �ʱ�ȭ �ȴ�.
	*/
	void MakeEmpty();
	/**
	*	@brief	List�� �� Node�� �߰��Ѵ�.
	*	@pre	������ ItemType�� �޾ƿ´�.
	*	@post	List�� ���Ļ��·� �߰��Ѵ�.
	*	@param	item �߰��Ϸ��� �����Ͱ� �� �ִ�.
	*/
	void Add(ItemType item);
	/**
	*	@brief	List�� ����� Node�� �����Ѵ�.
	*	@pre	������ ItemType�� �޾ƿ´�.
	*	@post	List���� ������ ��, ������ ItemType�� data���� �������ش�.
	*	@param	item �����Ϸ��� �����Ͱ� ����ִ�.
	*/
	void Delete(ItemType &item);
	/**
	*	@brief	�Է¹��� ���̵� �˻��Ͽ� ������ �����ϴ� �Լ���.
	*	@pre	�˻��ϱ� ���� �Է¹��� ���̵� ������ �־���Ѵ�.
	*	@param	item �˻��ϱ� ���� ������ ����ִ�.
	*	@post	������ ������ �˻��Ѵ�
	*   @return �Լ��� �� �۵��Ǹ� true�� �ƴϸ� false�� �����Ѵ�.
	*/
	bool search(ItemType &item);
	/**
	*	@brief	�Է¹��� ���̵� ���Ͽ� ã��, ������ ������ �����Ѵ�.
	*	@pre	���Źޱ� ���� �Է¹��� ���̵� ������ �־���Ѵ�.
	*	@param	item �����ϱ� ���� ������ �������ִ�.
	*	@post	������ ������ �����Ѵ�
	*   @return �Լ��� �� �۵��Ǹ� true�� ���� �ƴϸ� false�� �����Ѵ�.
	*/
	bool update(ItemType &item);
	/**
	*	@brief	List�� �ִ� ��� Node�� ����Ѵ�.
	*	@pre	None.
	*	@post	ȭ�鿡 List�� �ִ� ��� Node�� ����Ѵ�.
	*/
	bool print();/// �迭�ȿ� �ִ� ������ ����ϴ� �Լ��̴�.
	/**
	*	@brief	List�� ����� Node�� ������ ��ȯ�Ѵ�.
	*	@pre	����
	*	@post	List�� ����� Node�� ������ ��ȯ�Ѵ�.
	*/
	int GetLength();/// �迭�ȿ� �ִ� ���̸� �����Ѵ�.
	/**
	*	@brief	��带 ��ĭ �̵��ϰ� �� ����� ���� �����Ѵ�.
	*	@pre	����Ʈ�� ������ �� �־���Ѵ�.
	*	@post   ����� ��ġ�� ��ĭ�̵��ϰ� �ȴ�.
	*	@param	item �����带 ����Ű�� �ִ� �����̴�.
	*	@return	 ������ġ���� ���� ��忡 �ִ� ������ �����Ѵ�.
	*/
	bool GetNextItem(ItemType &item);
	/**
	*	@brief	��带 ó�� ��ġ�� �̵������ִ� �Լ��̴�.
	*	@pre	None.
	*	@post   ��带 ó�� ��ġ�� �̵��ϰԵȴ�.
	*/
	void ResetItem() { pCurrent = m_pFirst;}

private:
	DoublySortedNodeType<ItemType> *m_pFirst; ///< ����Ʈ�� ��ó��
	DoublySortedNodeType<ItemType> *m_pLast; ///< ����Ʈ�� �ǳ�
	DoublySortedNodeType<ItemType> *pCurrent; ///< ����Ʈ�� �̵���Ű�� ���� ������
	int m_nLength;	///< ����Ʈ�� ����.
};

template <class ItemType>
DoublySortedLinkedList<ItemType>::DoublySortedLinkedList()
{
	m_nLength=0;
	m_pFirst = new DoublySortedNodeType<ItemType>;
	m_pLast = new DoublySortedNodeType<ItemType>;

	m_pFirst->prev = 0; //NULL (while �� ����ó���� ����)
	m_pFirst->next = m_pLast;

	m_pLast->prev = m_pFirst;
	m_pLast->next = 0;// NULL (while �� ����ó���� ����)

}

template <class ItemType>
DoublySortedLinkedList<ItemType>::~DoublySortedLinkedList()
{
	MakeEmpty(); /// ����Ʈ�� ������ �ʱ�ȭ�����ش�.
}

template <class ItemType>
int DoublySortedLinkedList<ItemType>::GetLength() // ���� ����
{
	return m_nLength; /// ����Ʈ�� ���̸� �����Ѵ�.
}


template <class ItemType>
void DoublySortedLinkedList<ItemType>::MakeEmpty() //���� �ʱ�ȭ
{
	if(!m_nLength) // �ϳ��� ������ �� ������
	{
		DoublySortedNodeType<ItemType> *Temp;// ������ �ӽ÷� ����Ű�����ؼ� �����Ѻ���
		pCurrent = m_pFirst->next;

		while(!pCurrent) // pCurrent�� 0 (�ǳ��� �����ϱ� ����)
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
bool DoublySortedLinkedList<ItemType>::GetNextItem(ItemType &item) // ����̵�
{
	if(pCurrent->next == m_pLast) // ���̻� �̵���ų�� ������
	{
		return false;
	}
	else
	{
		pCurrent=pCurrent->next;
		item=pCurrent->data; //item �� ����� ������ �Űܴ���
		return true;
	}
}


template <class ItemType>
void DoublySortedLinkedList<ItemType>::Add(ItemType item) //����߰�
{
	pCurrent= m_pFirst; // ��ó�� ���� �ʱ�ȭ.
	DoublySortedNodeType<ItemType> *node = new DoublySortedNodeType<ItemType>;


	node->data=item; 
	node->next=NULL;
	node->prev=NULL;

	while(pCurrent->next->next) // pCurrent�� m_pLast�� �����ϱ� ������
	{
		if(pCurrent->next ->data > item) // ��Һ񱳸� �ؼ� ��带 �߰��� ��ġ ����
			break;
		pCurrent = pCurrent->next; // ����̵�
	}

	node->next = pCurrent->next;
	node->prev = pCurrent;
	pCurrent->next = node;

	m_nLength++; // ��� ���� �߰�
}

template <class ItemType>
void DoublySortedLinkedList<ItemType>::Delete(ItemType &item) // ��� ����
{
	pCurrent = m_pFirst; // ��ó�� ���� �ʱ�ȭ.

	while(pCurrent->next->next) // pCurrent�� m_pLast�� �����ϱ� ������
	{
		if(item == pCurrent->next->data) // item�� ������ ��ġ�Ҷ�
		{
			DoublySortedNodeType<ItemType> *Temp;
			Temp = pCurrent->next; //��� �̵�

			pCurrent->next->next->prev = pCurrent; 
			pCurrent->next = pCurrent->next->next;
			item = Temp->data;
			delete Temp;
			break;
		}
		else
			pCurrent = pCurrent->next; //��� �̵�
	}
	m_nLength--; //��� ���� ����
}

template <class ItemType>
bool DoublySortedLinkedList<ItemType>::print() // ���� ���
{
	pCurrent=m_pFirst; // ��ó�� ���� �ʱ�ȭ.

	while(pCurrent->next->next) // pCurrent�� m_pLast�� �����ϱ� ������
	{
		pCurrent=pCurrent->next; // ����̵�
		cout<<pCurrent->data<<"\n";
	}
	cout<<"\n";

	if(m_nLength==0) // ���ȿ� ������ ������
		return false;

	return true;
}

template <class ItemType>
bool DoublySortedLinkedList<ItemType>::search(ItemType &item) // ���� �˻�
{
	pCurrent=m_pFirst; // ��ó�� ���� �ʱ�ȭ.

	while(pCurrent->next->next) // pCurrent�� m_pLast�� �����ϱ� ������
	{
		if(pCurrent->next->data==item) 
		{
			item=pCurrent->next->data;
			return true;
		}
		else
			pCurrent = pCurrent->next; //��� �̵�
	}
	return false;
}

template <class ItemType>
bool DoublySortedLinkedList<ItemType>::update(ItemType &item) // ���� ������Ʈ
{
	pCurrent=m_pFirst; // ��ó�� ���� �ʱ�ȭ.

	while(pCurrent->next)
	{
		if(pCurrent->data == item)
		{
			pCurrent->data = item;
			return true;
		}
		pCurrent=pCurrent->next; //��� �̵�
	}
	return false;
}










