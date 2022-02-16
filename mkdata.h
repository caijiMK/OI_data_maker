#ifndef MKDATA
#define MKDATA 1

#include "cstdio"
#include "string"
#include "cstdlib"
#include "cstring"
#include "iostream"

namespace mkdata
{
	void mkstart(std::string _mkstart_name)
	{
		_mkstart_name+=".in";
		char _mkstart_namenow[_mkstart_name.length()];
		for(int _mkstart_i=0;_mkstart_i<(int)_mkstart_name.length();_mkstart_i++)
			_mkstart_namenow[_mkstart_i]=_mkstart_name[_mkstart_i];
		freopen(_mkstart_namenow,"w",stdout);
		return ;
	}

	long long random(long long _random_l,long long _random_r)
	{
		long long _random_len=_random_r-_random_l+1;
		long long _random_len_len=0;
		while(_random_len) _random_len_len++,_random_len/=10;
		_random_len_len=_random_len_len/3+(_random_len_len%3?1:0);
		long long _random_ans=0;
		for(long long _random_i=1,_random_k=1;_random_i<=_random_len_len;
			_random_i++,_random_k*=1000)
			_random_ans+=rand()%1000*_random_k;
		_random_ans%=(_random_r-_random_l+1);
		return _random_l+_random_ans;
	}
	//生成一个在[_random_l,_random_r]中的随机整数

	void List(long long *_list_l,long long *_list_r,long long _list_lnum,long long _list_rnum)
	{
		for(;_list_l!=_list_r;_list_l++) *_list_l=random(_list_lnum,_list_rnum);
		return ;
	}
	//生成随机序列。

	void mkend(std::string _mkend_name,int _mkend_number)
	{
		std::string _mkend_lstname=_mkend_name;
		fclose(stdout);
		if(_mkend_number>99)
		{
			_mkend_name+=_mkend_number/100+'0';
			_mkend_number%=100;
		}
		if(_mkend_number>9)
		{
			_mkend_name+=_mkend_number/10+'0';
			_mkend_number%=10;
		}
		_mkend_name+=_mkend_number+'0';

		system("std.exe");
		std::string _mkend_command="ren "+_mkend_lstname+".in "+_mkend_name+".in";
		char _mkend_commandin[_mkend_command.length()];
		for(int _mkend_i=0;_mkend_i<(int)_mkend_command.length();_mkend_i++)
			_mkend_commandin[_mkend_i]=_mkend_command[_mkend_i];
		system(_mkend_commandin);

		_mkend_command="ren "+_mkend_lstname+".out "+_mkend_name+".out";
		char _mkend_commandout[_mkend_command.length()];
		for(int _mkend_i=0;_mkend_i<(int)_mkend_command.length();_mkend_i++)
			_mkend_commandout[_mkend_i]=_mkend_command[_mkend_i];
		system(_mkend_commandout);
		return ;
	}
	//生成一个随机序列。
	//其中元素的大小为[_list_l,_list_r]。

	void DAG(std::pair<int,int> *_DAG_edgel,std::pair<int,int> *_DAG_edger,int *_DAG_topol,int *_DAG_topor)
	{
		for(int _DAG_i=1;_DAG_i<_DAG_topor-_DAG_topol;_DAG_i++,_DAG_edgel++)
			*_DAG_edgel=std::make_pair(*(_DAG_topol+_DAG_i-1),*(_DAG_topol+_DAG_i));
		for(;_DAG_edgel!=_DAG_edger;_DAG_edgel++)
		{
			int _DAG_u=random(0,_DAG_topor-_DAG_topol-2);
			int _DAG_v=random(_DAG_u+1,_DAG_topor-_DAG_topol-1);
			*_DAG_edgel=std::make_pair(*(_DAG_topol+_DAG_u),*(_DAG_topol+_DAG_v));
		}
		return ;
	}
}

#endif