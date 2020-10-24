#pragma once
#include"List.h"
class DNode {//�ʿ�ڵ�
	string Name;//�ʿ�����
	string Ad;//�ʿ�·��
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
class DList {   //�ʿ�����
	DNode* Head;
	DNode* Tail;
	int L;       //��
public:
	DList() {
		Head = Tail = NULL;
		L = 0;
	}
	void Add(string n, string ad = "") {//���һ���ʿ�
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
	void Read() {//��ȡ���дʿ����ơ���ַ
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
	void Write() {//д���ļ�
		ofstream ifile("d:\\Baicisha\\Dict.txt");
		DNode* P = Head;
		for (; P != NULL; P = P->Next) {
			ifile << P->Name << '\n';
			ifile << P->Ad << '\n';
		}
		ifile.close();
		return;
	}
	void Del(int n) {//ɾ��һ���ʿ�
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
	bool check(string a) {//����Ƿ������������ִ�Сд��
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
	bool Change(int n,string a) {//�޸Ŀ���
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
	string operator[](int n) {//����[]�����شʿ��ַ
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
	CString showvalue() {//��ʾ�����޸ĵĴʿ⣨���������ʿ⣩
		CString C;
		string s;
		DNode* P = Head;
		P = P->Next;
		P = P->Next;
		for (int i=1; P != NULL; P = P->Next,i++) {
			s = s + to_string(i) + "��" + P->Name + "\r\n";
		}
		C = s.c_str();
		return C;
	}
	CString show() {//��ʾ���дʿ�
		CString C;
		string s;
		DNode* P = Head;
		for (int i = 1; P != NULL; P = P->Next, i++) {
			s = s + to_string(i) + "��" + P->Name + "\r\n";
		}
		C = s.c_str();
		return C;
	}
	void DelAll() {//�������
		Tail = NULL;
		DNode* P = Head;
		for (;P!=NULL;) {
			Head = Head->Next;
			free(P);
			P = Head;
		}
		L = 0;
	}
	int Len() {//���س���
		return L;
	}
};