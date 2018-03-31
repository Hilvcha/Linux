---
title: C++8-IO库
date: 2017-11-25 20:17:44
tags:
- c++
- IO
categories:
- c++primer5th
---

istream | ifstream |istringstream | 
--------|----------|--------------
**ostream** | **ofstream** |**ostringstream**  

**iostate_type**:  
badbit(崩溃) failbit(单次失败) eofbit(结束) goodbit(安全)  
  
**judge_state**:  
s.eof() s.fail() s.bad() s.good() s.clear()(复位所有) s.(flags)(只复位flag) s.setstate(flags) s.rdstate()(当前状态)  

<!--more-->

```c++
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);//返回原来绑的那个输出流。
	istream & test(istream & in) {
		int num;
		try {
			while (in >> num, !in.eof()) {
				if (in.bad()) {
					throw runtime_error("输入流崩啦")
				}
				else if (in.fail()) {
					cout
					in.clear();//仅仅将状态复位，流中依然有错误的值。
					in.ignore(1000, '\n');
					continue;
				}
				//处理这个数字。
				cout << num << ends;
			}
		}
		catch (runtime_error err) {
			//do something.
		}
		in.clear();
		return in;
	}
```