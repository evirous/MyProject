#pragma once
#include"List.h"
class DNode {//词库节点
	string Name;//词库名称
	string Ad;//词库路径
	DNode* Next;
public:
	DNode() {
		Next = NULL;
	}
	void setD(string n,string str) {
		Name = n;
		Ad = str;
	}
	friend class DList;
};
class DList {   //词库链表
	DNode* Head;
	DNode* Tail;
	int L;       //表长
public:
	DList() {
		Head = Tail = NULL;
		L = 0;
	}
	void Add(string n, string ad = "") {//添加一个词库
		if (ad == "")ad = "d:\\Baicisha\\" + n + ".txt";
		DNode* temp = new DNode;
		if (L == 0) {
			Head = temp;
			Tail = temp;
			temp->Next = NULL;
		}
		else {
			Tail->Next = temp;
			Tail = temp;
		}
		temp->setD(n, ad);
		L++;
	}
	void Read() {//读取所有词库名称、地址
		string n, ad;
		ifstream ifile("d:\\Baicisha\\Dict.txt");
		for (;;) {
			if (ifile.peek() == EOF) break;
			getline(ifile, n);
			if (ifile.peek() == EOF) break;
			getline(ifile, ad);
			Add(n, ad);
			L++;
		}
		ifile.close();
		return;
	}
	void Write() {//写入文件
		ofstream ifile("d:\\Baicisha\\Dict.txt");
		DNode* P = Head;
		for (; P != NULL; P = P->Next) {
			ifile << P->Name << '\n';
			ifile << P->Ad << '\n';
		}
		ifile.close();
		return;
	}
	void Del(int n) {//删除一个词库
		if (n == 0) {
			n = L;
		}
		DNode* P = Head;
		if (n == 1) {
			remove(Head->Ad.c_str());
			Head = Head->Next;
			free(P);
			P = NULL;
		}
		else{
			for (int i = 2; i < n; i++)P = P->Next;
			remove(P->Next->Ad.c_str());
			DNode* Q = P->Next;
			P->Next = P->Next->Next;
			free(Q);
			Q = NULL;
			P = NULL;
		}
		return;
	}
	bool check(string a) {//检测是否重名（不区分大小写）
		string lowerS1 = a; string lowerS2 = "dict";
		for (int i = 0; i < (lowerS1.length()); i++){
			if ('A' <= lowerS1[i] && lowerS1[i] <= 'Z')lowerS1[i] += 32;
		}
		if (lowerS1 == lowerS2)return false;
		DNode* P = Head;
		for (;P!=NULL;P=P->Next) {
			lowerS1 = P->Name, lowerS2 = a;
			for (int i = 0; i < (lowerS1.length()); i++) {
				if ('A' <= lowerS1[i] && lowerS1[i] <= 'Z')lowerS1[i] += 32;
			}
			for (int i = 0; i < (lowerS1.length()); i++) {
				if ('A' <= lowerS1[i] && lowerS1[i] <= 'Z')lowerS1[i] += 32;
			}
			if (lowerS1 == lowerS2)return false;
		}
		return true;
	}
	bool Change(int n,string a) {//修改库名
		if (check(a)) {
			DNode* P = Head;
			if (n > 0) {
				for (int i = 1; i < n; i++)P = P->Next;
			}
			else {
				if (n == 0) {
					P = Tail;
				}
			}
			P->Name = a;
			P->Ad = "d:\\Baicisha\\" + a + ".txt";
			return true;
		}
		else return false;
	}
	string operator[](int n) {//重载[]，返回词库地址
		if (n > 0) {
			DNode* P = Head;
			for (int i = 1; i < n; i++)P = P->Next;
			return P->Ad;
		}
		else {
			if (n == 0) {
				return Tail->Ad;
			}
		}
	}
	CString showvalue() {//显示可以修改的词库（除四六级词库）
		CString C;
		string s;
		DNode* P = Head;
		P = P->Next;
		P = P->Next;
		for (int i=1; P != NULL; P = P->Next,i++) {
			s = s + to_string(i) + "、" + P->Name + "\r\n";
		}
		C = s.c_str();
		return C;
	}
	CString show() {//显示所有词库
		CString C;
		string s;
		DNode* P = Head;
		for (int i = 1; P != NULL; P = P->Next, i++) {
			s = s + to_string(i) + "、" + P->Name + "\r\n";
		}
		C = s.c_str();
		return C;
	}
	void DelAll() {//清空链表
		Tail = NULL;
		DNode* P = Head;
		for (;P!=NULL;) {
			Head = Head->Next;
			free(P);
			P = Head;
		}
		L = 0;
	}
	int Len() {//返回长度
		return L;
	}
};