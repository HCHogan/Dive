template<typename... Values> class tuple;
template<> class tuple<> {
public:
	int operator[](int index) {
		return 0;
	}
};

template<typename Head, typename... Tail>
class tuple<Head, Tail...>: private tuple<Tail...> {
	typedef tuple<Tail...> inherited;

public:
	tuple() {}
	tuple(Head v, Tail... vtail): m_head(v), inherited(vtail...) { }
	// 调用父类的构造函数,让父类去处理这件事情
	Head& head() { return m_head; }
	inherited& tail() { return *this; }

	auto& operator[](int index) {
		if(index == 0) return head();
		else return tail().operator[](index - 1);
	}

protected:
	Head m_head;
};

