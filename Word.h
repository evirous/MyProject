#pragma once
#include<iostream>
#include<fstream>
#include<ctime>
#include <string> 
#include <windows.h>
#include <io.h>
#include <direct.h>
#include <memory>
using namespace std;
class Line {                      //单词的每一个释义
public:	
	string Wo;                    //释义
	string EG;                    //例句
	Line* Next;
	Line(string s,string eg="") { //构造函数
		Wo = s;
		EG = eg;
		Next = NULL;
	}
	friend class LineList;
};
class LineList {                   //释义链表
public:	
	Line* Head;
	Line* Tail;
	int L;
	LineList() {                   //构造函数
		Head = NULL;
		Tail = NULL;
		L = 0;
	}
	void Add(string word,string eg="") {   //添加释义函数
		Line* Li = new Line(word,eg);
		if (Head == NULL) {
			Head = Tail = Li;
		}
		else {
			Tail->Next = Li;
			Tail = Li;
		}
	}
	void DelAll() {                //清空所有释义
		Line* P = Head;
		Tail = NULL;
		for (;P!=NULL;) {
			Head = Head->Next;
			free(P);
			P = Head;
		}
	}
	string show() {                 //返回所有释义的文字
		string s;
		Line* P = Head;
		for (;P!=NULL;P=P->Next) {
			s = s + P->Wo + ":" + P->EG + "\r\n";
			cout << P->Wo << ":" << P->EG << '\n';
		}
		return s;
	}
	string show1() {                //只返回第一个释义的释义部分
		string s;
		s = Head->Wo + "\r\n";
		return s;
	}
};
class Word {                        //单词类
public:		
	string Eng;                     //英文部分
	LineList usual;                 //常规释义
	LineList profes;                //专业释义
	LineList entoen;                //英英释义
	int Score;                      //得分
	Word() {                        //构造函数
		Eng = "";
		Score = 0;
	}
	void click() {                  //运行网络查找插件
		SHELLEXECUTEINFO ShExecInfo = { 0 };
		ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
		ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
		ShExecInfo.hwnd = NULL;
		ShExecInfo.lpVerb = NULL;
		ShExecInfo.lpFile = _T("D:\\Baicisha\\theword.exe");
		ShExecInfo.lpParameters = _T("theword");
		ShExecInfo.lpDirectory = NULL;
		ShExecInfo.nShow = SW_SHOW;
		ShExecInfo.hInstApp = NULL;
		ShellExecuteEx(&ShExecInfo);
		WaitForSingleObject(ShExecInfo.hProcess, INFINITE);
	}
	void Read(int i=0) {            //读取单词
		string s, e;
		ifstream ifile;
		usual.DelAll();
		profes.DelAll();
		entoen.DelAll();
		ifile.open("d:\\theword.txt", ios::in);
		getline(ifile, s);
		if (i == 1) { Eng = s; }
		for (;;) {
			getline(ifile, s);
			if (s == "$")break;
			Addusual(s);
		}
		for (;;) {
			getline(ifile, s);
			if (s == "$")break;
			getline(ifile, e);
			Addprofes(s, e);
		}
		for (;;) {
			getline(ifile, s);
			if (s == "$")break;
			getline(ifile, e);
			Addentoen(s, e);
		}
		ifile.close();
	}
	void Find() {                   //网络查找单词
		ofstream ofile;
		ofile.open("d:\\whatword.txt", ios::out);
		ofile << Eng;
		ofile.close();
		click();
		Sleep(100);
		Read();
		return;
	}
	string showeasy() {             //返回第一个释义
		string s = Eng + ":";
		s=s+usual.show1();
		return s;
	}
	CString show() {                //返回全部释义
		CString C;
		string s = Eng + ":" + "\r\n" ;
		if (usual.Head != NULL) { s = s + "常规释义" + "\r\n" + usual.show(); }
		if (profes.Head != NULL) { s = s + "专业释义" + "\r\n" + profes.show(); }
		if (entoen.Head != NULL) { s = s + "英英释义" + "\r\n" + entoen.show(); }
		C = s.c_str();
		return C;
	}
	bool Select(int n) {            //选择单词
		if (n == 0) {               //汉译英，英译汉
			if ((rand() % 5) > Score)return true;
			else return false;
		}
		if (n == 1) {               //英英模式
			if (entoen.Head != NULL && entoen.Head->Wo != "" && entoen.Head->Wo.length() > 5) {
				if ((rand() % 5) > Score)return true;
				else return false;
			}
			else return false;
		}
		if (n == 2) {               //句子填空
			if (profes.Head != NULL && profes.Head->EG != "" && profes.Head->EG.length() > 5) {
				if ((rand() % 5) > Score)return true;
				else return false;
			}
			else return false;
		}
	}
	void AddScore() {               //加分
		Score += 1;
		if (Score > 4)Score = 4;
	}
	void DelScore() {               //减分
		Score -= 1;
		if (Score < 0)Score = 0;
	}
	void Addusual(string s, string eg = "") {//添加常规释义
		usual.Add(s,eg);
	}
	void Addprofes(string s, string eg = "") {//添加专业释义
		profes.Add(s, eg);
	}
	void Addentoen(string s, string eg = "") {//添加英英释义
		entoen.Add(s, eg);
	}
};