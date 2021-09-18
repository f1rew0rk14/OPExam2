#include <iostream>
using namespace std;

template<class T>
class Auto_ptr
{
	T* m_ptr;
public:
	Auto_ptr(T* ptr = nullptr)
		:m_ptr(ptr)
	{
	}

	~Auto_ptr()
	{
		delete m_ptr;
	}

	Auto_ptr(Auto_ptr& a) 
	{
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;
	}

	Auto_ptr& operator=(Auto_ptr& a)
	{
		if (&a == this)
			return *this;

		delete m_ptr;
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr; 
		return *this;
	}

	T& operator*() const { return *m_ptr; }

};