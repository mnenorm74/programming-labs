template<typename T>
class SignedLinkedList
{
public:
	SignedLinkedList();
	~SignedLinkedList();

	void AddFirst(T value);
	void AddLast(T value);
	void AddCenter(T ssvalue);
	void AddAt(T value, int index);

	void RemoveFirst();
	void RemoveLast();
	void RemoveAt(int index);

	int GetSize();
	void Delete();
	int GetCount(T value);
	T& operator[](const int index);
	int GetIndex(T value);



private:
	template<typename T>
	class Node
	{
	public:
		Node *nextNode;
		T value;

		Node(T value = T(), Node *nextNode = nullptr)
		{
			this->value = value;
			this->nextNode = nextNode;
		}
	};
	int Size;
	Node<T> *head;
};

template <typename T>
void PrintValues(SignedLinkedList<T> & list);
template <typename T>
void PrintAdresses(SignedLinkedList<T> & list);
template <typename T>
void PrintValuesAdresses(SignedLinkedList<T> & list);

