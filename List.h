#pragma once
#include"Word.h"
class Node {             //单词节点
	Word w;
	Node* Next;
public:
	Node() {
		Next = NULL;
	}
	friend class List;
};
class List {           //单词链表
	Node* Head;
	Node* Tail;
	int L;             //单词数
	int R;             //未满分单词数
public:
	List() {           //构造函数
		Head = NULL;
		Tail = NULL;
		L = 0;
		R = 0;
	}
	bool Check(string s) {//检查是否存在该单词
		Node* P = Head;
		int Same = 0;
		for (; P != NULL;) {
			if (P->w.Eng == s) { Same = 1; break; }
			P = P->Next;
		}
		if (Same == 0)return true;
		if (Same == 1)return false;
	}
	void save(Word wo) {//保存单词
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
	void Read(string s) {//读取单词
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
	void Write(string s) {//写入文件
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
	void ReStart() {//重新开始（将所有单词分数重置）
		Node* P = Head;
		for (; P != nullptr;) {
			P->w.Score = 0;
			P = P->Next;
		}
		R = L;
	}
	Word operator[](int n) {//重载[]
		Node* P = Head;
		for (int i = 0; i < n; i++)P = P->Next;
		return P->w;
	}
	CString show() {   //返回第n个单词的文字部分
		Node* P = Head;
		CString C;
		string s;
		for (int i = 0; i < L; i++) {
			s=s+to_string(i+1)+"、"+P->w.showeasy();
			P = P->Next;
		}
		C = s.c_str();
		return C;
	}
	int length() {      //返回长度
		return L;
	}
	int testR() {//返回未满分单词个数
		return R;
	}
	void DelR() {//减少一个未背单词个数
		R -= 1;
	}
	void Del(int n) {//删除第n个单词
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
	void DelAll() {//清空链表
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
	bool Finish() {//是否背完全部单词
		if (R == 0)return true;
		else return false;
	}
	bool Lack() {//是否不足8个单词
		if (L < 8)return true;
		else return false;
	}
	void DaoruW(string s) {//网络导入
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
	void DaoruL(string s) {//本地导入
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
	~List() {//析构函数
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