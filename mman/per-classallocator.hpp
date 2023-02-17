#include <cstddef>
#include <iostream>
#include <new>
using namespace std;

class Screen {
public:
	Screen(int x) : i(x) { };
	int get() {return i;}

	void* operator new(size_t);
	void operator delete(void*, size_t);
	// ...
private:
	Screen* next;
	static Screen* freeStore;
	static const int screenChunk;

private:
	int i;

};
Screen* Screen::freeStore = 0;
const int Screen::screenChunk = 24;

void* Screen::operator new(size_t size) {
	Screen *p;
	if(!freeStore) {
		size_t chunk = screenChunk * size;
		freeStore = p = reinterpret_cast<Screen*>(new char[chunk]);
		// 建立链表
		for(; p != &freeStore[screenChunk - 1]; ++p)
			p->next = p + 1;
		p->next = 0;
	}
	p = freeStore;
	freeStore = freeStore->next;
	return p;
}

void Screen::operator delete(void* p, size_t) {
	// 链表操作罢了
	(static_cast<Screen*>(p))->next = freeStore;
	freeStore = static_cast<Screen*>(p);
}


class Airplane {
private:
	struct AirplaneRep {
		unsigned long miles;
		char type;
	};
private:
	union {						// 若加上名稱便是 type 定義式，未加名稱則是
		AirplaneRep rep;		// anonymous union { } 内便是数个申明
		Airplane* next;			// embedded pointer
	};
public:
	unsigned long getMiles() {return rep.miles;}
	char getType() { return rep.type; }
	void set(unsigned long m, char t) {
		rep.miles = m;
		rep.type = t;
	}

public:
	static void* operator new(size_t size);
	static void operator delete(void* deadObject, size_t);
public:
	static const int BLOCK_SIZE;
	static Airplane* headOfFreeList;
};

Airplane* Airplane::headOfFreeList;
const int Airplane::BLOCK_SIZE = 512;

void* Airplane::operator new(size_t size) {
	// 继承发生时,大小不为1
	if(size != sizeof(Airplane)) return ::operator new(size);

	Airplane* p =headOfFreeList;
	if(p) headOfFreeList = p->next;
	else {
		// freelist 空
		Airplane* newBlock = static_cast<Airplane*>(::operator new(BLOCK_SIZE * sizeof(Airplane)));
		//构建链表,跳过#0,应为他将被传回作为本次成果
		for(int i = 1; i < BLOCK_SIZE - 1; ++i)
			newBlock[i].next = &newBlock[i+1];
		newBlock[BLOCK_SIZE-1].next = 0;		// 结束list
		p = newBlock;
		headOfFreeList = &newBlock[1];
	}
	return p;
}

void Airplane::operator delete(void *deadObject, size_t size) {
	if(deadObject == 0) return;
	if(size != sizeof(Airplane)) {
		::operator delete(deadObject);
		return;
	}

	Airplane* carclass = static_cast<Airplane*>(deadObject);
	carclass->next = headOfFreeList;
	headOfFreeList = carclass;		// 回收进头
}


