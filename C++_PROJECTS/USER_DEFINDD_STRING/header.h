#ifndef HEADER_H
#define HEADER_H

#include<iostream>
#include<cstring>
using namespace std;

class STRING
{
	char *p;
	public:
	/////////////////////////////////////////////////////////////////////
	STRING()
	{
		p=0;
	}
	/////////////////////////////////////////////////////////////////////
	STRING(const char *s)
	{
		p=new char[strlen(s)+1];
		strcpy(p,s);
	}
	////////////////////////////////////////////////////////////////////
	STRING(STRING & s)
	{
		p=new char[strlen(s.p)+1];
		strcpy(p,s.p);
	}
	///////////////////////////////////////////////////////////////////
	STRING &operator=(STRING &s)
	{
		if(this !=&s)
		{
			delete[] p;
			p=new char[strlen(s.p)+1];
			strcpy(p,s.p);
		}
		return *this;
	}
	//////////////////////////////////////////////////////////////////
	STRING operator+(const STRING &s)
	{
		STRING temp;
		temp.p=new char[strlen(this->p)+strlen(s.p)+1];
		strcpy(temp.p,this->p);
		strcat(temp.p,s.p);
		return temp;
	}
	/////////////////////////////////////////////////////////////////
	char &operator[](int index)
	{
		return p[index];
	}
	////////////////////////////////////////////////////////////////
	bool operator<(STRING &s)
	{
		if(strcmp(this->p,s.p)<0)
			return true;
		return false;
	}
	//////////////////////////////////////////////////////////////
	bool operator>(STRING &s)
	{
		if(strcmp(this->p,s.p)>0)
			return true;
		return false;
	}
	/////////////////////////////////////////////////////////////
	bool operator>=(STRING &s)
	{
		if(strcmp(this->p,s.p)>=0)
			return true;
		return false;
	}
	///////////////////////////////////////////////////////////
	bool operator<=(STRING &s)
	{
		if(strcmp(this->p,s.p)<=0)
			return true;
		return false;

	}
	///////////////////////////////////////////////////////////
	bool operator!=(STRING &s)
	{
		if(strcmp(this->p,s.p)!=0)
			return true;
		return false;
	}
	//////////////////////////////////////////////////////////
	bool operator==(STRING &s)
	{
		if(strcmp(this->p,s.p)==0)
			return true;
		return false;
	}
	/////////////////////////////////////////////////////////
	friend istream&operator>>(istream &in,STRING &s);
	friend ostream&operator<<(ostream &out,STRING &s);
	friend char *strcpy1( STRING &s1,STRING &s2 );
	friend char *strncpy1(STRING &s1,STRING &s2 ,int n);
	friend bool  strcmp1( STRING &s1,STRING &s2 );
	friend bool  strncmp1( STRING &s1,STRING &s2 ,int n);
	friend char *strcat1(  STRING &s1,STRING &s2 );
	friend char *strncat1(  STRING &s1,STRING &s2 , int n);
	friend char *strrev1( STRING &s1);
	friend char *strupr1(STRING &s1);
	friend char *strlwr1( STRING &s1);
	friend char *strchr1( STRING &s1,char s2);
	friend char *strrchr1( STRING &s1,char s2);
	friend char *strstr1( STRING &s1 , const char *s2);
	friend int strlen1(STRING &s1);
};

int strlen1(STRING &s1)
{
	int len=0;
	for(len=0;s1.p[len];len++);
	return len;
}

/////////////////////////////////////////////////////////////////////
char *strstr1( STRING &s1 ,const char *s2)
{
	int i=0,j=0;
	for(i=0,j=0;s1.p[i]!='\0';i++)
	{
		if( s1.p[i]==s2[j] )
		{
			j++;
		}
		else
		{
			if(j>0)
			{
				i=i-j;
				j=0;
			}
		}
	}
	if(s2[j]=='\0')
		return &s1.p[i-j];
	else
		return NULL;
}

///////////////////////////////////////////////////////////////////
char *strrchr1( STRING &s1,char s2)
{
	int i=0;
	char *s;
	for(i=0;s1.p[i];i++)
	{
		if(s1.p[i]==s2)
			s=&s1.p[i];
	}
	return s;
}

////////////////////////////////////////////////////////////////////
char *strchr1( STRING &s1,char s2)
{
	int i=0;
	for(i=0;s1.p[i];i++)
	{
		if(s1.p[i]==s2)
			break;
	}
	return &s1.p[i];
}

////////////////////////////////////////////////////////////////
char *strlwr1( STRING &s1)
{
	int i = 0;

	for(i = 0; s1.p[i]; i++)
	{
		if(s1.p[i] >= 'A' && s1.p[i] <= 'Z')
			s1.p[i] += 32;
	}

	return s1.p;
}

//////////////////////////////////////////////////////////////////
char *strupr1(STRING &s1)
{
	int i=0;
	for(i=0;s1.p[i];i++)
	{
		if(s1.p[i]>='a' && s1.p[i] <='z')
			s1.p[i]-=32;
	}
	return s1.p;
}

////////////////////////////////////////////////////////////////
char *strrev1( STRING &s1)
{
	int len=strlen(s1.p);
	int i=0;
	for(i=0;i<len/2;i++)
	{
		char s=s1.p[i];
		s1.p[i]=s1.p[len-1-i];
		s1.p[len-1-i]=s;
	}
	return s1.p;
}

/////////////////////////////////////////////////////////////////
char *strncat1(  STRING &s1,STRING &s2 , int n)
{
	int len1 = strlen(s1.p);
	int len2 = strlen(s2.p);

	int size = (n < len2) ? n : len2;

	char *temp = new char[len1 + size + 1];

	strcpy(temp, s1.p);

	int i = len1;
	int j = 0;

	while(s2.p[j] && j < n)
	{
		temp[i++] = s2.p[j++];
	}

	temp[i] = '\0';

	delete[] s1.p;

	s1.p = temp;

	return s1.p;
}

/////////////////////////////////////////////////////////////////
char *strcat1(STRING &s1, STRING &s2)
{
	int len1 = strlen(s1.p);
	int len2 = strlen(s2.p);

	char *temp = new char[len1 + len2 + 1];

	strcpy(temp, s1.p);

	int i = len1;
	int j = 0;

	while(s2.p[j])
	{
		temp[i++] = s2.p[j++];
	}

	temp[i] = '\0';

	delete[] s1.p;

	s1.p = temp;

	return s1.p;
}

///////////////////////////////////////////////////////////////////
bool  strncmp1( STRING &s1,STRING &s2 ,int n)
{
	if(n==0)
		return true;

	int i=0;
	for(i=0 ; i<n && s1.p[i] && s2.p[i] ; i++)
	{
		if(s1.p[i]!=s2.p[i])
		{
			return false;
		}

	}
	return true;
}

//////////////////////////////////////////////////////////////////
bool strcmp1( STRING &s1,STRING &s2 )
{
	if(strlen(s1.p)!=strlen(s2.p))
		return false;
	int i=0;
	for(i=0;s1.p[i]&&s2.p[i];i++)
	{
		if(s1.p[i]!=s2.p[i])
		{
			return false;
		}

	}
	return true;
}

///////////////////////////////////////////////////////////////////
char *strncpy1(STRING &s1,STRING &s2 ,int n)
{
	delete[] s1.p;
	s1.p=new char[n+1];
	int i=0;
	if(s2.p[0]=='\0')
		return NULL;

	for(i=0;i<n;i++)
		s1.p[i]=s2.p[i];
	s1.p[i]='\0';
	return s1.p;
}

/////////////////////////////////////////////////////////////////////
char *strcpy1( STRING &s1,STRING &s2 )
{
	delete[] s1.p;
	s1.p=new char[strlen(s2.p)+1];
	strcpy(s1.p,s2.p);
	return s1.p;
}

///////////////////////////////////////////////////////////////////////
istream&operator>>(istream &in,STRING &s)
{
	char temp[100];
	in>>temp;
	s.p=new char[strlen(temp)+1];
	strcpy(s.p,temp);
	return in;
}

////////////////////////////////////////////////////////////////////////
ostream&operator<<(ostream &out,STRING &s)
{
	out<<s.p;
	return out;
}

///////////////////////////////////////////////////////////////////////
#endif
