#include<iostream>
#include<stdlib.h>

#define size 5
static int count;

using namespace std;

template<class type>
class stack
{
	type stk[size];
	int index;

	public:
	stack()
	{
		index=-1;
	}
	///////////////////////////////////////////////////////
	void push()
	{
		count=0;
		if(index>=size-1)
		{
			cout << "\033[4;5;31mSTACK OVERFLOW\033[0m" << endl;
		}
		else
		{
			index++;
			cout<<"Enter input to PUSH"<<endl;
			cin>>stk[index];
		}
	}
	//////////////////////////////////////////////////////
	void pop()
	{
		count=0;
		if(index<=-1)
			cout << "\033[4;5;31mStack is underflow\033[0m" << endl;
		else
		{
			cout<<"delete"<<stk[index]<<endl;
			index--;
		}
	}
	/////////////////////////////////////////////////////
	void display()
	{
		count=0;
		if(index<=-1)
		{
			cout << "\033[4;5;31mSTACK IS EMPTY\033[0m" << endl;
		}
		else
		{
			for(int i=0;i<=index;i++)
				cout<<stk[i]<<" "<<endl;
		}
	}
};

///////////////////////////////////////////////////////
void termination(int &count)
{
	count++;
	if(count==1)
		cout<<"Please read the options carefully"<<endl;
	else if(count==2)
		cout<<"\033[31mLast chance pls take care!!!\033[0m"<<endl;
	else if(count==3)
	{
		cout<<"\033[5;31mThanks for using our application please read the manual and comeback properly\033[0m "<<endl;
		count=0;
		exit(0);
	}
	return;
}

int main()
{
	stack <int> obj_int1,*obj_int2;
	stack <char> obj1,*obj2;
	stack <float> f1,*f2;
	stack <double> d1,*d2;
	stack <string> s1,*s2;
	int op;
	int ch;
	bool int_used=0,char_used=0,float_used=0,double_used=0,string_used=0;
	
	while(1)
	{
		count=0;
		cout<<"\033[1;4;36m---Main Menu---\033[0m"<<endl;
		cout<<"Enter your choice \n1.int\n2.char\n3.float\n4.double\n5.string\n6.exit"<<endl;
		cin>>ch;

		if(cin.fail())
		{
			cin.clear();
			cin.ignore(1000,'\n');
			cout<<"invalid choice ! please enter a number \n";
			continue;
		}

		switch(ch)
		{
			case 1:
				count=0;
				cout<<"\033[1;32mint stack app ready to use\033[0m"<<endl;
				if(int_used==1)
				{
					cout<<"1.Continue old stack\n2.new stack"<<endl;
					int choice;
					cin>>choice;
					if(choice==2)
					{
						delete []obj_int2;
						obj_int2=new stack<int>;
					}
				}
				else
					obj_int2=&obj_int1;
				while(1)
				{
					int_used=1;
					cout << "\033[32m1)push 2)pop 3)display 4)main_menu\033[0m \n";
					cin>>op;
					if(cin.fail()){
						cin.clear();
						cin.ignore(1000,'\n');
						cout << "Invalid input! Please enter a number.\n";
						continue;
					}
					if(op==1)
						obj_int2->push();
					else if(op==2)
						obj_int2->pop();
					else if(op==3)
						obj_int2->display();
					else if(op==4)
						break;
					else
					{
						termination(count);
					}
				}
				break;
			case 2:
				count=0;
				cout<<"\033[1;32mint stack app ready to use\033[0m"<<endl;
				if(char_used==1)
				{
					cout<<"1.Continue old stack\n2.new stack"<<endl;
					int choice;
					cin>>choice;
					if(choice==2)
					{
						delete [] obj2;
						obj2=new stack<char>;
					}
					else
						obj2=&obj1;
				}
				else
					obj2=& obj1;
				while(1)
				{
					char_used=1;
					cout << "\033[32m1)push 2)pop 3)display 4)main_menu\033[0m \n";
					cin>>op;
					if(cin.fail())
					{
						cin.clear();
						cin.ignore(1000,'\n');
						cout<<"Invalid input! Please enter a number.\n";
						continue;
					}
					if(op==1)
						obj2->push();
					else if(op==2)
						obj2->pop();
					else if(op==3)
						obj2->display();
					else if(op==4)
						break;
					else
					{
						termination(count);
					}
				}
				break;
			case 3:
				count = 0;
				cout << "\033[1;32mint stack app ready to use\033[0m" << endl;

				if(float_used == 1)
				{
					cout << "1.Continue old stack\n2.new stack" << endl;

					int choice;
					cin >> choice;

					if(choice == 2)
					{
						delete [] f2;
						f2 = new stack<float>;
					}
				}
				else
					f2 = &f1;

				while(1)
				{
					char_used = 1;

					cout << "\033[32m1)push 2)pop 3)display 4)main_menu\033[0m \n";

					cin >> op;

					if(cin.fail())
					{
						cin.clear();
						cin.ignore(1000,'\n');
						cout << "Invalid input! Please enter a number.\n";
						continue;
					}

					if(op == 1)
						f2->push();

					else if(op == 2)
						f2->pop();

					else if(op == 3)
						f2->display();

					else if(op == 4)
						break;

					else
					{
						termination(count);
					}
				}
				break;
			case 4:
				count = 0;
				cout << "\033[1;32mint stack app ready to use\033[0m" << endl;

				if(double_used == 1)
				{
					cout << "1.Continue old stack\n2.new stack" << endl;

					int choice;
					cin >> choice;

					if(choice == 2)
					{
						delete [] d2;
						d2 = new stack<double>;
					}
				}
				else
					d2 = &d1;

				while(1)
				{
					double_used = 1;

					cout << "\033[32m1)push 2)pop 3)display 4)main_menu\033[0m \n";

					cin >> op;

					if(cin.fail())
					{
						cin.clear();
						cin.ignore(1000,'\n');
						cout << "Invalid input! Please enter a number.\n";
						continue;
					}

					if(op == 1)
						d2->push();

					else if(op == 2)
						d2->pop();

					else if(op == 3)
						d2->display();

					else if(op == 4)
						break;

					else
					{
						termination(count);
					}
				}
				break;
			case 5:
				count = 0;
				cout << "\033[1;32mint stack app ready to use\033[0m" << endl;

				if(string_used == 1)
				{
					cout << "1.Continue old stack\n2.new stack" << endl;

					int choice;
					cin >> choice;

					if(choice == 2)
					{
						delete [] s2;
						s2 = new stack<string>;
					}
				}
				else
					s2 = &s1;

				while(1)
				{
					char_used = 1;

					cout << "\033[32m1)push 2)pop 3)display 4)main_menu\033[0m \n";

					cin >> op;

					if(cin.fail())
					{
						cin.clear();
						cin.ignore(1000,'\n');
						cout << "Invalid input! Please enter a number.\n";
						continue;
					}

					if(op == 1)
						s2->push();

					else if(op == 2)
						s2->pop();

					else if(op == 3)
						s2->display();

					else if(op == 4)
						break;

					else
					{
						termination(count);
					}
				}
				break;
			case 6:
				exit(0);
		}
	}

	return 0;
}
