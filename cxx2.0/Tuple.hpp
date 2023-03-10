template<typename... Values> class tuple;
template<> class tuple<> {
public:
	auto operator[](int index) {
		return 0;
	}
};

template<typename Head, typename... Tail>
class tuple<Head, Tail...>: public tuple<Tail...> {
public:

	typedef tuple<Tail...> inherited;
	tuple() {}
	tuple(Head v, Tail... vtail): m_head(v), inherited(vtail...) { }
	// 调用父类的构造函数,让父类去处理这件事情
	Head& head() { return m_head; }
	inherited& tail() { return *this; }

	auto operator[](int index)->decltype(index == 0 ? head() : tail().operator[](index - 1)){
		if(index == 0) return head();
		else return tail().operator[](index - 1);
	}


	Head m_head;
};

