#pragma once
#include"Word.h"
class Node {             //���ʽڵ�
	Word w;
	Node* Next;
public:
	Node() {
		Next = NULL;
	}
	friend class List;
};
class List {           //��������
	Node* Head;
	Node* Tail;
	int L;             //������
	int R;             //δ���ֵ�����
public:
	List() {           //���캯��
		Head = NULL;
		Tail = NULL;
		L = 0;
		R = 0;
	}
	bool Check(string s) {//����Ƿ���ڸõ���
		Node* P = Head;
		int Same = 0;
		for (; P != NULL;) {
			if (P->w.Eng == s) { Same = 1; break; }
			P = P->Next;
		}
		if (Same == 0)return true;
		if (Same == 1)return false;
	}
	void save(Word wo) {//���浥��
			Node* temp = new Node;
			temp->w = wo;
			if (L == 0) {
				Head = temp;
				Tail = temp;
				temp->Next = NULL;
				L++;
			}
			else {
				Node* P = Head;
				if (P->w.Eng == temp->w.Eng) {return;}
				if (P->w.Eng > temp->w.Eng) { temp->Next = P; Head = temp; L++; return; }
				for (; P->Next != NULL; P = P->Next) {
					if (P->Next->w.Eng >= temp->w.Eng)break;
				}
				if (P->Next == NULL) { Tail->Next = temp; Tail = temp; }
				else {
					if (P->Next->w.Eng == temp->w.Eng)return;
					else{
						temp->Next = P->Next;
						P->Next = temp;
						L++;
					}
				}
			}
	}
	void Read(string s) {//��ȡ����
		ifstream ifile(s);
		if (ifile.peek() == EOF) return;
		for (;;) {
			Node* temp = new Node;
			if (L == 0) {
				Head = temp;
				Tail = temp;
				temp->Next = NULL;
			}
			else {
				Tail->Next = temp;
				Tail = temp;
			}
			L++;
			ifile>>temp->w.Score;
			ifile >> temp->w.Eng;
			string s,e;
			for (;;) {
				getline(ifile, s);
				if (s == "$")break;
			}
			for (;;) {
				getline(ifile, s);
				if (s == "$"||s=="%")break;
				temp->w.usual.Add(s);
			}
			if (s == "%")continue;
			for (;;) {
				getline(ifile, s);
				if (s == "$"||s=="%"){ break; }
				getline(ifile, e);
				temp->w.profes.Add(s,e);
			}
			if (s == "%")continue;
			for (;;) {
				getline(ifile, s);
				if (s == "$" || s == "%") { break; }
				getline(ifile, e);
				temp->w.entoen.Add(s, e);
			}
			if (temp->w.Score < 4)R++;
			if (ifile.peek() == EOF) return;
		}
		ifile.close();
	}
	void Write(string s) {//д���ļ�
		ofstream f;
		f.open(s);
		Node* P = Head;
		for (int i = 0; i < L; i++) {
			f <<  P->w.Score<< P->w.Eng << '\n' << "$"<<'\n';
			Line* Q = P->w.usual.Head;
			for (;Q!=NULL;Q=Q->Next) {
				f << Q->Wo <<'\n';
			}
			Q = P->w.profes.Head;
			f << "$" << '\n';
			for (; Q != NULL; Q = Q->Next) {
				f << Q->Wo  <<'\n'<< Q->EG << '\n';
			}
			Q = P->w.entoen.Head;
			f << "$" << '\n';
			for (; Q != NULL; Q = Q->Next) {
				f << Q->Wo <<'\n'<< Q->EG << '\n';
			}
			f << "%" << '\n';
			P = P->Next;
		}
		f.close();
	}
	void ReStart() {//���¿�ʼ�������е��ʷ������ã�
		Node* P = Head;
		for (; P != nullptr;) {
			P->w.Score = 0;
			P = P->Next;
		}
		R = L;
	}
	Word operator[](int n) {//����[]
		Node* P = Head;
		for (int i = 0; i < n; i++)P = P->Next;
		return P->w;
	}
	CString show() {   //���ص�n�����ʵ����ֲ���
		Node* P = Head;
		CString C;
		string s;
		for (int i = 0; i < L; i++) {
			s=s+to_string(i+1)+"��"+P->w.showeasy();
			P = P->Next;
		}
		C = s.c_str();
		return C;
	}
	int length() {      //���س���
		return L;
	}
	int testR() {//����δ���ֵ��ʸ���
		return R;
	}
	void DelR() {//����һ��δ�����ʸ���
		R -= 1;
	}
	void Del(int n) {//ɾ����n������
		Node* P = Head;
		Node* Q = nullptr;
			if (n == 1) {
				Head = Head->Next;
				delete P;
				P = nullptr;
			}
			else {
				for (int i = 2; i < n; i++)P = P->Next;
				Q = P->Next;
				P->Next = P->Next->Next;
				delete Q;
				Q = nullptr;
			}
			L--;
	}
	void DelAll() {//�������
		R = 0;
		Node* P = Head;
		Tail = NULL;
		for (;P!=NULL;) {
			Head = Head->Next;
			free(P);
			P = Head;
		}
		L = 0;
	}
	bool Finish() {//�Ƿ���ȫ������
		if (R == 0)return true;
		else return false;
	}
	bool Lack() {//�Ƿ���8������
		if (L < 8)return true;
		else return false;
	}
	void DaoruW(string s) {//���絼��
		ifstream dfile;
		dfile.open(s, ios::in);
		string word;
		for (;;) {
			if (dfile.peek() == EOF) { dfile.close(); return; }
			getline(dfile, word);
			Word w;
			w.Eng = word;
			w.Find();
			save(w);
		}
		dfile.close();
		return;
	}
	void DaoruL(string s) {//���ص���
		ifstream dfile;
		dfile.open(s, ios::in);
		string word,Cn;
		for (;;) {
			if (dfile.peek() == EOF) { dfile.close(); return; }getline(dfile, word);
			if (dfile.peek() == EOF) { dfile.close(); return; }getline(dfile, Cn);
			Word w;
			w.Eng = word;
			w.Addusual(Cn);
			save(w);
		}
		dfile.close();
		return;
	}
	~List() {//��������
		Node* P = Head;
		Tail = NULL;
		for (;Head!=NULL;) {
			P = Head;
			Head = P->Next;
			P->Next = NULL;
			delete P;
			P = NULL;
		}
	}
};