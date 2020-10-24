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
class Line {                      //���ʵ�ÿһ������
public:	
	string Wo;                    //����
	string EG;                    //����
	Line* Next;
	Line(string s,string eg="") { //���캯��
		Wo = s;
		EG = eg;
		Next = NULL;
	}
	friend class LineList;
};
class LineList {                   //��������
public:	
	Line* Head;
	Line* Tail;
	int L;
	LineList() {                   //���캯��
		Head = NULL;
		Tail = NULL;
		L = 0;
	}
	void Add(string word,string eg="") {   //������庯��
		Line* Li = new Line(word,eg);
		if (Head == NULL) {
			Head = Tail = Li;
		}
		else {
			Tail->Next = Li;
			Tail = Li;
		}
	}
	void DelAll() {                //�����������
		Line* P = Head;
		Tail = NULL;
		for (;P!=NULL;) {
			Head = Head->Next;
			free(P);
			P = Head;
		}
	}
	string show() {                 //�����������������
		string s;
		Line* P = Head;
		for (;P!=NULL;P=P->Next) {
			s = s + P->Wo + ":" + P->EG + "\r\n";
			cout << P->Wo << ":" << P->EG << '\n';
		}
		return s;
	}
	string show1() {                //ֻ���ص�һ����������岿��
		string s;
		s = Head->Wo + "\r\n";
		return s;
	}
};
class Word {                        //������
public:		
	string Eng;                     //Ӣ�Ĳ���
	LineList usual;                 //��������
	LineList profes;                //רҵ����
	LineList entoen;                //ӢӢ����
	int Score;                      //�÷�
	Word() {                        //���캯��
		Eng = "";
		Score = 0;
	}
	void click() {                  //����������Ҳ��
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
	void Read(int i=0) {            //��ȡ����
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
	void Find() {                   //������ҵ���
		ofstream ofile;
		ofile.open("d:\\whatword.txt", ios::out);
		ofile << Eng;
		ofile.close();
		click();
		Sleep(100);
		Read();
		return;
	}
	string showeasy() {             //���ص�һ������
		string s = Eng + ":";
		s=s+usual.show1();
		return s;
	}
	CString show() {                //����ȫ������
		CString C;
		string s = Eng + ":" + "\r\n" ;
		if (usual.Head != NULL) { s = s + "��������" + "\r\n" + usual.show(); }
		if (profes.Head != NULL) { s = s + "רҵ����" + "\r\n" + profes.show(); }
		if (entoen.Head != NULL) { s = s + "ӢӢ����" + "\r\n" + entoen.show(); }
		C = s.c_str();
		return C;
	}
	bool Select(int n) {            //ѡ�񵥴�
		if (n == 0) {               //����Ӣ��Ӣ�뺺
			if ((rand() % 5) > Score)return true;
			else return false;
		}
		if (n == 1) {               //ӢӢģʽ
			if (entoen.Head != NULL && entoen.Head->Wo != "" && entoen.Head->Wo.length() > 5) {
				if ((rand() % 5) > Score)return true;
				else return false;
			}
			else return false;
		}
		if (n == 2) {               //�������
			if (profes.Head != NULL && profes.Head->EG != "" && profes.Head->EG.length() > 5) {
				if ((rand() % 5) > Score)return true;
				else return false;
			}
			else return false;
		}
	}
	void AddScore() {               //�ӷ�
		Score += 1;
		if (Score > 4)Score = 4;
	}
	void DelScore() {               //����
		Score -= 1;
		if (Score < 0)Score = 0;
	}
	void Addusual(string s, string eg = "") {//��ӳ�������
		usual.Add(s,eg);
	}
	void Addprofes(string s, string eg = "") {//���רҵ����
		profes.Add(s, eg);
	}
	void Addentoen(string s, string eg = "") {//���ӢӢ����
		entoen.Add(s, eg);
	}
};