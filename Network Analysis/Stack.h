#pragma once
#include<iostream>
using namespace std;

class node
{
	int data;
	node* next;
public:
	node()
	{
		data = 0;
		next = nullptr;
	}
	node(int data)
	{
		this->data = data;
		next = nullptr;
	}
	void set_data(int data)
	{
		this->data = data;
	}
	void set_next(node* ptr)
	{
		next = ptr;
	}
	int get_data() const
	{
		return this->data;
	}
	node* get_next() const
	{
		return this->next;
	}
};

class Stack
{
	node* top;

public:
	Stack()
	{
		top = NULL;
	}
	bool isEmpty()
	{
		if (top == NULL)
		{
			return true;
		}
		return false;
	}
	void push(int data)
	{
		if (top == nullptr)
		{
			top = new node(data);
		}
		else
		{
			node* temp = new node(data);
			temp->set_next(top);
			top = temp;
		}
	}
	int pop()
	{
		if (top == NULL)
		{
			return NULL;
		}
		else
		{
			node* temp = top->get_next();
			int data = top->get_data();
			delete top;
			top = temp;
			return data;
		}
	}
	int peek()
	{
		if (top == NULL)
		{
			return -32768;
		}
		return top->get_data();
	}
};