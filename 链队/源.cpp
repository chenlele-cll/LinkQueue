#include<iostream>
using namespace std;

template<class datatype>
class Linkqueue;

template<class datatype>
class node
{
public:
	//friend class Linkqueue<datatype>;
	datatype data;
	node<datatype> *next;
	node(datatype x) : data(x), next(NULL) {};
};

template<class datatype>
class Linkqueue
{
private:
	node<datatype> *front;
	node<datatype> *rear;
	int len;
public:
	Linkqueue();
	~Linkqueue();
	void inqueue(datatype val);
	void dequeue();
	int getlen1();
	int getlen2();
	datatype getfront()
	{
		return front->next->data;
	}
	datatype getrear()
	{
		return rear->data;
	}
	friend ostream &operator<<(ostream &output, const Linkqueue &D)
	{
		if (D.len == 0)
		{
			cout << "Linkqueue is empty" << endl;
		}
		else
		{
			node<datatype> *p = D.front->next;
			for (int i = 0; i < D.len; i++)
			{
				cout << p->data << " ";
				p = p->next;
			}
			cout << endl;
		}
		return output;
	}
};

template<class datatype>
Linkqueue<datatype>::Linkqueue()
{
	front = new node<datatype>(-1);
	rear = front;
	front->next = NULL;
	len = 0;
}

template<class datatype>
Linkqueue<datatype>::~Linkqueue()
{
	while (rear != front)
	{
		node<datatype> *temp = front->next;
		delete front;
		front = temp;
	}
	delete rear;
}

template<class datatype>
void Linkqueue<datatype>::inqueue(datatype val)
{
	rear->next = new node<datatype>(val);
	rear = rear->next;
	len++;
}

template<class datatype>
void Linkqueue<datatype>::dequeue()
{
	if (len == 0)
	{
		cerr << "Linkqueue is empty,can't dequeue" << endl;
	}
	else
	{
		node<datatype> *temp = front->next;
		front->next = front->next->next;
		delete temp;
		len--;
	}
}

template<class datatype>
int Linkqueue<datatype>::getlen1()
{
	return len;
}

template<class datatype>
int Linkqueue<datatype>::getlen2()
{
	node<datatype> *temp = front;
	int count = 0;
	while (temp != rear)
	{
		count++;
		temp = temp->next;
	}
	return count;
}
int main()
{
	//test
	Linkqueue<int> A;
	A.inqueue(3);
	A.inqueue(2);
	A.inqueue(1);
	A.inqueue(4);
	cout << A;
	cout << A.getlen2() << endl;
	cout << A.getfront() << " " << A.getrear() << endl;
	A.dequeue();
	A.dequeue();
	A.dequeue();
	cout << A;
	system("pause");
	return 0;
}