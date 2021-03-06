/**********************************************************************************
 Code by Leonardo Berti (c) 2006
 Esempio di classe stack implementata con una classe
 stack3.h:definizione
 -concrete types-
***********************************************************************************/

namespace ClassStack
{
	class Stack
	{
	private:

		char* v;
		int top;
		int maxsize;

	public:

		//classi usate per la gestione delle eccezioni
		class Overflow{};
		class Underflow{};
		class BadSize{};

		//costruttore
		Stack(int size);

		//distruttore: dealloca la memoria
		~Stack();

		char pop();
		void push(char);
	};
}
